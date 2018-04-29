//
// Created by Jake Billings on 4/28/18.
//

#include "utf.h"

/**
 * writeUTF()
 *
 * stolen from OpenJDK
 *
 * Writes a string to the specified DataOutput using
 * <a href="DataInput.html#modified-utf-8">modified UTF-8</a>
 * encoding in a machine-independent manner.
 * <p>
 * First, two bytes are written to out as if by the <code>writeShort</code>
 * method giving the number of bytes to follow. This value is the number of
 * bytes actually written out, not the length of the string. Following the
 * length, each character of the string is output, in sequence, using the
 * modified UTF-8 encoding for the character. If no exception is thrown, the
 * counter <code>written</code> is incremented by the total number of
 * bytes written to the output stream. This will be at least two
 * plus the length of <code>str</code>, and at most two plus
 * thrice the length of <code>str</code>.
 *
 * @param      str   a string to be written.
 * @param      out   destination to write to
 * @return     The number of bytes written out.
 * @exception  IOException  if an I/O error occurs.
 */
int writeUTF(const string &str, ostream &out) {
    int strlen = str.size();
    int utflen = 0;
    int c, count = 0;

    /* use charAt instead of copying String to char array */
    for (int i = 0; i < strlen; i++) {
        c = str[i];
        if ((c >= 0x0001) && (c <= 0x007F)) {
            utflen++;
        } else if (c > 0x07FF) {
            utflen += 3;
        } else {
            utflen += 2;
        }
    }

    if (utflen > 65535)
        throw runtime_error(
                "encoded string too long: bytes");

//        byte[] bytearr = null;
//        if (out instanceof DataOutputStream) {
//            DataOutputStream dos = (DataOutputStream) out;
//            if (dos.bytearr == null || (dos.bytearr.length < (utflen + 2)))
//                dos.bytearr = new byte[(utflen * 2) + 2];
//            bytearr = dos.bytearr;
//        } else {
    char chararr[utflen + 2];
//        }

    chararr[count++] = (char) ((utflen >> 8) & 0xFF);
    chararr[count++] = (char) ((utflen >> 0) & 0xFF);

    int i = 0;
    for (i = 0; i < strlen; i++) {
        c = str[i];
        if (!((c >= 0x0001) && (c <= 0x007F))) break;
        chararr[count++] = (char) c;
    }

    for (; i < strlen; i++) {
        c = str[i];
        if ((c >= 0x0001) && (c <= 0x007F)) {
            chararr[count++] = (char) c;

        } else if (c > 0x07FF) {
            chararr[count++] = (char) (0xE0 | ((c >> 12) & 0x0F));
            chararr[count++] = (char) (0x80 | ((c >> 6) & 0x3F));
            chararr[count++] = (char) (0x80 | ((c >> 0) & 0x3F));
        } else {
            chararr[count++] = (char) (0xC0 | ((c >> 6) & 0x1F));
            chararr[count++] = (char) (0x80 | ((c >> 0) & 0x3F));
        }
    }
    out.write(chararr, utflen + 2);
    return utflen + 2;
}

/**
 * readUTF()
 *
 * stolen from OpenJDK
 *
 * Reads from the
 * stream <code>in</code> a representation
 * of a Unicode  character string encoded in
 * <a href="DataInput.html#modified-utf-8">modified UTF-8</a> format;
 * this string of characters is then returned as a <code>String</code>.
 * The details of the modified UTF-8 representation
 * are  exactly the same as for the <code>readUTF</code>
 * method of <code>DataInput</code>.
 *
 * @param      in   a data input stream.
 * @return     a Unicode string.
 * @exception  EOFException            if the input stream reaches the end
 *               before all the bytes.
 * @exception  IOException   the stream has been closed and the contained
 *             input stream does not support reading after close, or
 *             another I/O error occurs.
 * @exception  UTFDataFormatException  if the bytes do not represent a
 *               valid modified UTF-8 encoding of a Unicode string.
 * @see        java.io.DataInputStream#readUnsignedShort()
 */
string readUTF(istream &in) {
    char lenarr[2];

    in.read(reinterpret_cast<char*>(&lenarr[1]), sizeof(char));
    in.read(reinterpret_cast<char*>(&lenarr[0]), sizeof(char));

    short utflen = lenarr[0];
//    char[] bytearr = null;
//    char[] chararr = null;
//    if (in instanceof DataInputStream) {
//        DataInputStream dis = (DataInputStream) in;
//        if (dis.bytearr.length < utflen) {
//            dis.bytearr = new byte[utflen * 2];
//            dis.chararr = new char[utflen * 2];
//        }
//        chararr = dis.chararr;
//        bytearr = dis.bytearr;
//    } else {
    char bytearr[utflen];
    char chararr[utflen];
//    }

    int c, char2, char3;
    int count = 0;
    int chararr_count = 0;

    in.read(bytearr, utflen);

    while (count < utflen) {
        c = (int) bytearr[count] & 0xff;
        if (c > 127) break;
        count++;
        chararr[chararr_count++] = (char) c;
    }

    while (count < utflen) {
        c = (int) bytearr[count] & 0xff;
        switch (c >> 4) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                /* 0xxxxxxx*/
                count++;
                chararr[chararr_count++] = (char) c;
                break;
            case 12:
            case 13:
                /* 110x xxxx   10xx xxxx*/
                count += 2;
                if (count > utflen)
                    throw runtime_error(
                            "malformed input: partial character at end");
                char2 = (int) bytearr[count - 1];
                if ((char2 & 0xC0) != 0x80)
                    throw runtime_error(
                            "malformed input around byte ");// + count);
                chararr[chararr_count++] = (char) (((c & 0x1F) << 6) |
                                                   (char2 & 0x3F));
                break;
            case 14:
                /* 1110 xxxx  10xx xxxx  10xx xxxx */
                count += 3;
                if (count > utflen)
                    throw runtime_error(
                            "malformed input: partial character at end");
                char2 = (int) bytearr[count - 2];
                char3 = (int) bytearr[count - 1];
                if (((char2 & 0xC0) != 0x80) || ((char3 & 0xC0) != 0x80))
                    throw runtime_error(
                            "malformed input around byte ");// + (count - 1));
                chararr[chararr_count++] = (char) (((c & 0x0F) << 12) |
                                                   ((char2 & 0x3F) << 6) |
                                                   ((char3 & 0x3F) << 0));
                break;
            default:
                /* 10xx xxxx,  1111 xxxx */
                throw new runtime_error(
                        "malformed input around byte ");// + count);
        }
    }
    // The number of chars produced may be less than utflen
    return string(chararr, 0, chararr_count);
}
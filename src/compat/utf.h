#include<string>
#include<iostream>
#include<stdexcept>

using namespace std;

#ifndef RESEARCH_MICROGRID_CPP_UTF_H
#define RESEARCH_MICROGRID_CPP_UTF_H

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
int writeUTF(const string &str, ostream &out);

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
string readUTF(istream &in);

#endif //RESEARCH_MICROGRID_CPP_UTF_H

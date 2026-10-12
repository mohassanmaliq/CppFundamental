/*
  fstream functions (<fstream>)

  Classes: ifstream (input), ofstream (output), fstream (input and output)

  File handling
  open(filename, mode)  opens a file
  is_open()             returns true if a file is open
  close()               closes the file
  rdbuf()               returns a pointer to the underlying filebuf
  swap()                swaps two stream objects (C++11)

  Input (ifstream, fstream)
  >>                    formatted read, skips whitespace
  get()                 reads one character
  getline()             reads a line
  read(buf, n)          reads n raw bytes
  ignore(n, delim)      skips characters
  peek()                looks at the next character without removing it
  putback(c)            puts a character back into the stream
  unget()               puts the last read character back
  gcount()              characters read by the last unformatted input
  seekg(pos)            moves the read position
  tellg()               returns the read position

  Output (ofstream, fstream)
  <<                    formatted write
  put(c)                writes one character
  write(buf, n)         writes n raw bytes
  flush()               forces buffered output to the file
  seekp(pos)            moves the write position
  tellp()               returns the write position

  State checking
  good()                no errors
  eof()                 end of file reached
  fail()                a read or format error occurred
  bad()                 serious stream error
  clear()               resets the error flags
  rdstate()             returns the current state flags
  setstate()            sets state flags
  operator bool         true if the stream has no failure, so if (file) works
  operator!             true if the stream has failed

  Formatting
  width()               sets the field width
  precision()           sets the number of decimal digits
  fill()                sets the padding character
  setf() / unsetf()     sets or clears format flags

  Open modes
  ios::in               open for reading
  ios::out              open for writing
  ios::app              append at the end
  ios::ate              go to the end on open
  ios::trunc            erase existing contents
  ios::binary           binary mode

  Default modes: ifstream = in, ofstream = out, fstream = in | out
*/
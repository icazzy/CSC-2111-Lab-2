#include "ReadFile.h"
#include <iostream>
#include <string>

ReadFile::ReadFile(const char* file_name) {
   m_input_file.open(file_name);
   m_eof = false;
   m_closed = false;
}

ReadFile::~ReadFile() {
   close();
}

bool ReadFile::eof() {
   return m_eof;
}

void ReadFile::close() {
   if (!m_closed) {
      m_input_file.close();
      m_closed = true;
   }
}

String* ReadFile::readLine() {
   if (m_closed) return NULL;
   if (m_eof) return NULL;

   string text;
   m_eof = !(getline(m_input_file, text));

   String* str = new String((const char*) text.c_str());
   return str;
}

#include "WriteFile.h"
#include <sstream>

WriteFile::WriteFile(const char* file_name)
{
   wf = new WriteFile;

   return wf;
}

WriteFile::~WriteFile()
{
   close(wf);
   delete[] wf;
}

WriteFile::close()
{
   if (!closed)
   {
      output_file.close();
      closed = true;
   }
}

WriteFile::writeLine(String* line)
{
   if (!closed && line->length() > 0)
   {
      output_file << line->getText() << endl;
   }
}

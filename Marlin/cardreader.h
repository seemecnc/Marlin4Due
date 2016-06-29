#ifndef CARDREADER_H
#define CARDREADER_H

#ifdef SDSUPPORT

#define MAX_DIR_DEPTH 10          // Maximum folder depth

#include "SdFile.h"
#ifdef SDHSMCI_SUPPORT
  #include <SD_HSMCI.h>
  #include "Arduino_Due_SD_HSCMI.h" // This creates the object SD
#endif
enum LsAction { LS_SerialPrint, LS_Count, LS_GetFilename };

class CardReader {
public:
  CardReader();

  void initsd();
  void write_command(char *buf);
  //files auto[0-9].g on the sd card are performed in a row
  //this is to delay autostart and hence the initialisaiton of the sd card to some seconds after the normal init, so the device is available quick after a reset

  void checkautostart(bool x);
  void openFile(char* name,bool read,bool replace_current=true);
  void openLogFile(char* name);
  void removeFile(char* name);
  void closefile(bool store_location=false);
  void release();
  void startFileprint();
  void pauseSDPrint();
  void getStatus();
  void printingHasFinished();

  #ifdef LONG_FILENAME_HOST_SUPPORT
    void printLongPath(char *path);
  #endif

  void getfilename(uint16_t nr, const char* const match=NULL);
  uint16_t getnrfilenames();

  void getAbsFilename(char *t);

  #ifdef SDHSMCI_SUPPORT
    void sdhsmci_init();
    void sdhsmci_open_file(char* name, bool read);
    bool sdhsmci_eof();
    //char sdhsmci_get();
    void sdhsmci_printing_finished();
    void sdhsmci_updir();
    bool sdhsmci_is_subdirectory();
  #endif
  void ls();
  void chdir(const char * relpath);
  void updir();
  void setroot();


 #ifdef SDHSMCI_SUPPORT
  FORCE_INLINE bool isFileOpen() { return sdhsmci_file.inUse; }
 #else
  FORCE_INLINE bool isFileOpen() { return file.isOpen(); }
 #endif

  FORCE_INLINE bool eof() { return sdpos >= filesize; }

 #ifdef SDHSMCI_SUPPORT
  FORCE_INLINE int16_t get() {
    char readByte;
    if( sdhsmci_file.Read(readByte) ) {//if successful read
      sdpos = sdhsmci_file.Position();
      return readByte;
    }
    else {
      //cardOK = false;
      sdprinting = false;
      //closefile();
      return -1;
    }
  }
 #else
  FORCE_INLINE int16_t get() { sdpos = file.curPosition(); return (int16_t)file.read(); }
 #endif

  FORCE_INLINE void setIndex(long index) { sdpos = index; file.seekSet(index); }
  FORCE_INLINE uint8_t percentDone() { return (isFileOpen() && filesize) ? sdpos / ((filesize + 99) / 100) : 0; }
  FORCE_INLINE char* getWorkDirName() { workDir.getFilename(filename); return filename; }

public:
  bool saving, logging, sdprinting, cardOK, filenameIsDir;
  char filename[FILENAME_LENGTH], longFilename[LONG_FILENAME_LENGTH];
  int autostart_index;
  #ifdef SDHSMCI_SUPPORT
    bool sdhsmci_printing;
    FileStore sdhsmci_file;
    char current_working_directory[256];
  #endif
private:
  SdFile root, *curDir, workDir, workDirParents[MAX_DIR_DEPTH];
  uint16_t workDirDepth;
  Sd2Card card;
  SdVolume volume;
  SdFile file;
  #define SD_PROCEDURE_DEPTH 1
  #define MAXPATHNAMELENGTH (FILENAME_LENGTH*MAX_DIR_DEPTH + MAX_DIR_DEPTH + 1)
  uint8_t file_subcall_ctr;
  uint32_t filespos[SD_PROCEDURE_DEPTH];
  char filenames[SD_PROCEDURE_DEPTH][MAXPATHNAMELENGTH];
  uint32_t filesize;
  millis_t next_autostart_ms;
  uint32_t sdpos;

  bool autostart_stilltocheck; //the sd start is delayed, because otherwise the serial cannot answer fast enought to make contact with the hostsoftware.

  LsAction lsAction; //stored for recursion.
  uint16_t nrFiles; //counter for the files in the current directory and recycled as position counter for getting the nrFiles'th name in the directory.
  char* diveDirName;
  void lsDive(const char *prepend, SdFile parent, const char * const match=NULL);
};

extern CardReader card;

#define IS_SD_PRINTING (card.sdprinting)

#ifdef SDHSMCI_SUPPORT //SDHSMCI_SUPPORT card detection
#define IS_SD_INSERTED (READ(SD_MMC_0_CD_GPIO) == SD_MMC_0_CD_DETECT_VALUE)
#else
#if (SDCARDDETECT > -1)
  #ifdef SDCARDDETECTINVERTED
    #define IS_SD_INSERTED (READ(SDCARDDETECT) != 0)
  #else
    #define IS_SD_INSERTED (READ(SDCARDDETECT) == 0)
  #endif
#else
  //No card detect line? Assume the card is inserted.
  #define IS_SD_INSERTED true
#endif
#endif //SDHSMCI_SUPPORT card detection

#else
#define IS_SD_PRINTING (false)

#endif //SDSUPPORT

#endif //__CARDREADER_H

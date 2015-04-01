// START DEFINE FOR POSIX


#define BYTE uint8_t
#define DWORD uint32_t 
#define WORD uint16_t

typedef struct _SYSTEMTIME {
   WORD wYear;
   WORD wMonth;
   WORD wDayOfWeek;
   WORD wDay;
   WORD wHour;
   WORD wMinute;
   WORD wSecond;
   WORD wMilliseconds;
} SYSTEMTIME;

// END DEFINE FOR POSIX, NOT FOR WINDWOS


typedef	struct	ExportFileHeader
{	char		HeaderText[16];		//'EXPORTFILEHEADER'
	DWORD		HeaderSize;			//sizeof this header (256)
	DWORD		RecordUnitSize;		//sizeof RecordUnit (512)
	DWORD		SamplingRate;		//
//	DWORD		Unused1;
	DWORD		WeightOfLSB;		//in uV*1000000, (1000000-> LSB=1uV), default 0 -> LSB=1uV
        SYSTEMTIME	RecordTime;
	DWORD		SecondFromStart;
	DWORD		Unused2;
        // Исправлено Лукьяновой с 20 на 10   
        wchar_t		Patient[10];		//Patient FIO. (UNICODE)
//	BYTE		Unused[160];
	BYTE		Unused[128];
	char		StationSerialNumber[32];
}	ExportFileHeader,*LPExportFileHeader;


typedef	struct	ExportRecordUnit
{	short		StandardECG[12];	//I, II, III, avr, avl, avf, V1, v2, v3, v4, v5, v6
	short		unused[4];
	short		ExtroECG[240];
}	ExportRecordUnit,*LPExportRecordUnit;


#pragma warning(disable:4200)

typedef	struct	ExportFile
{	ExportFileHeader	Header;
	ExportRecordUnit	Records[];
}	ExportFile,*LPExportFile;
#pragma warning(default:4200)


/* $Log:        ndis.h $
 * Revision 1.6  92/09/07  14:10:40  CRM
 * Added newline at end of file (stupid compiler.)
 *
 * Revision 1.5  92/09/04  16:15:51  CRM
 * Cleaned up a little; now has #ifdef test so won't multiply define.
 *
 * Revision 1.4  92/08/17  16:41:56  crm
 * Automatic checkin
 *
 * Revision 1.3  92/08/17  15:23:16  Unknown
 * releasing locks
 *
 * Revision 1.2  92/08/17  15:07:55  Unknown
 * Added log entries and RCS bookkeeping
 *
 * Revision 1.1  92/08/17  14:52:35  Unknown
 * Initial revision
 *  */
/* NDIS.H -- Definitions and structures related to the Network
 *                       Driver Interface Specification.
 *
 *     Names of structures, types, tables, and functions follow the
 *     NDIS naming conventions, whenever practical.
 *
 * NOTE:  This header file includes defs/structures for NDIS v 2.02.
 *        OUR MAC ADHERES TO NDIS v 2.01, and NOT TO 2.02 !!!!!!!
 *        I have not removed the 2.02 extensions, we simply don't use them.
 */
#if !defined(NDIS)
#    define NDIS

/*   #define NULL 0             */

#define NAME_LEN        16
#define ADDR_LEN        16
#define ADDR_SIZE        1
#define NUM_MCADDRS      2

/* System request function - opcodes */

#define InitiateBind                  1
#define Bind                          2

/* Protocol Manager opcodes */

#define GetPMInfo                     1
#define RegisterModule                2
#define BindAndStart                  3
#define GetPMLinkage                  4

/* General Request opcodes */

#define InitiateDiagnostics           1
#define ReadErrorLog                  2
#define SetStationAddress             3
#define OpenAdapter                   4
#define CloseAdapter                  5
#define ResetMAC                      6
#define SetPacketFilter               7
#define AddMulticastAddress           8
#define DeleteMulticastAddress        9
#define UpdateStatistics              10
#define ClearStatistics               11
#define Interrupt                     12
#define SetFunctionalAddress          13
#define SetLookAhead                  14
                                        /* V3.00.10 NDIS 2.02 enhancement     */
#define UnusedGenReq                  15
#define ModifyOpenParms               16

/* Status Indication opcodes */

#define RingStatus                    1
#define AdapterCheck                  2
#define StartReset                    3
#define InterruptStatus               4
#define EndReset                      5

/* Return error codes */

#define SUCCESS                       0x0000
#define WAIT_FOR_RELEASE              0x0001
#define REQUEST_QUEUED                0x0002
#define FRAME_NOT_RECOGNIZED          0x0003
#define FRAME_REJECTED                0x0004
#define FORWARD_FRAME                 0x0005
#define OUT_OF_RESOURCE               0x0006
#define INVALID_PARAMETER             0x0007
#define INVALID_FUNCTION              0x0008
#define NOT_SUPPORTED                 0x0009
#define HARDWARE_ERROR                0x000A
#define TRANSMIT_ERROR                0x000B
#define NO_SUCH_DESTINATION           0x000C
#define ALREADY_STARTED               0x0020
#define INCOMPLETE_BINDING            0x0021
#define DRIVER_NOT_INITIALIZED        0x0022
#define HARDWARE_NOT_FOUND            0x0023
#define HARDWARE_FAILURE              0x0024
#define CONFIGURATION_FAILURE         0x0025
#define INTERRUPT_CONFLICT            0x0026
#define INCOMPATIBLE_MAC              0x0027
#define INITIALIZATION_FAILED         0x0028
#define GENERAL_FAILURE               0x00FF

/* Adapter Check error codes */

#define AdapCheckInoperative          0x8000
#define AdapCheckIllegalOp            0x1000
#define AdapCheckLocalParityErr       0x0800
#define AdapCheckParityErr            0x0400
#define AdapCheckInternalParityErr    0x0100
#define AdapCheckRingXmitParityErr    0x0080
#define AdapCheckRingRcvParityErr     0x0040
#define AdapCheckXmitOverrun          0x0020
#define AdapCheckRcvOverrun           0x0010
#define AdapCheckUnrecogInterrupt     0x0008
#define AdapCheckUnrecogErrInt        0x0004
#define AdapCheckNoPCSysService       0x0003
#define AdapCheckUnrecogSuperReq      0x0002
#define AdapCheckProgramRequest       0x0001

/* protocol levels, interface types */

#define MACLvl                        1
#define MACTyp                        1

#define MAJOR_NDIS_VERSION            2
#define MINOR_NDIS_VERSION            0

/* Protocol Table structures */

/*
 * common characteristics table
 */
struct CommChar {
        ushort  CcSize;            /* Table size */
        uchar   CcLvlMjr;          /* V3.00.10 Major Level of table */
        uchar   CcLvlMnr;          /* V3.00.10 Minor Level of table */
        ushort  CcSpLvl;           /* Level of spec tables */
        uchar   CcMjrVer;          /* Module Major version number */
        uchar   CcMnrVer;          /* Module Minor version number */
        ulong   CcBindFnc;         /* "Hints" on binding support */
        uchar   CcName[NAME_LEN];  /* Module name */
        uchar   CcUPLevel;         /* Upper protocol level */
        uchar   CcUIType;          /* Upper interface type */
        uchar   CcLPLevel;         /* Lower protocol level */
        uchar   CcLIType;          /* Lower interface type */
        ushort  CcModuleID;        /* Module ID (supplied by PM) */
        ushort  CcDataSeg;         /* Module Data Segment */
        LPFUN   CcSysReq;          /*  System request function */
        struct MACSpecChar far  *CcSCp; /* specific characteristics         */
        struct MACSpecStat far  *CcSSp; /* specific status*/
        struct MACUprDisp far   *CcUDp; /* upper dispatch table */
        struct ProtLwrDisp far  *CcLDp; /* lower dispatch table */

        ulong           CcRsv1;                                                         /* reserved */
        ulong           CcRsv2;                                                         /* reserved */
};

/*
 * Definintions for the MAC Service Supported Flags.
 * Bits 0-14.
 */

#define BROADCAST_SUPP                  0x0001
#define MULTICAST_SUPP                  0x0002
#define FUNC_GROUP_ADDR_SUPP            0x0004
#define PROMISCUOUS_SUPP                0x0008
#define SET_STN_ADDR_SUPP               0x0010
#define STAT_ALWAYS_CURR                0x0020
#define DIAGNOSTICS_SUPP                0x0040
#define LOOPBACK_SUPP                   0x0080
#define RECEIVECHAIN_MOSTLY             0x0100
#define IBM_SOURCE_R_SUPP               0x0200
#define RESET_MAC_SUPP                  0x0400
#define OPEN_ADAPTER_SUPP               0x0800
#define INTERRUPT_RQ_SUPP               0x1000
#define SRC_RTNG_BRDG_SUPP              0x2000
#define GDT_ADDRESS_SUPP                0x4000
#define MULTI_DATAXFER                  0x8000
                                        /* V3.00.10 NDIS 2.02 enhancements    */
#define MODIFYOPEN_SUPP                 0x00010000L

/*
 * MAC Service Specific characteristics table
 */
struct MACSpecChar {
        ushort  MscSize;                 /* Table size*/
        uchar   MscType[NAME_LEN];       /* MAC type name*/
        ushort  MscStnAdrSz;             /* Station address length */
        uchar   MscPermStnAdr[ADDR_LEN]; /* Permanent station address */
        uchar   MscCurrStnAdr[ADDR_LEN]; /* Current station address */
        ulong   MscCurrFncAdr;           /* Current functional address */

        struct MCastBuf far *MscMCp;     /* Address of multicast buffer*/

        ulong   MscLinkSpd;              /* Link speed (bits/sec)    */
        ulong   MscService;              /* Services supported flags */
        ushort  MscMaxFrame;             /* Maximum frame size */
        ulong   MscTBufCap;              /* Transmit buffer capacity*/
        ushort  MscTBlkSz;               /* Transmit buf alloc block size*/
        ulong   MscRBufCap;              /* Receive buffer capacity */
        ushort  MscRBlkSz;               /* Receive buf alloc block size */
        uchar   MscVenCode[3];           /* Vendor code          */
        uchar   MscVenAdapter;           /* Vendor adapter code  */
        uchar far *MscVenAdaptDesc;      /* Ptr to vendor adapter desc   */
        ushort  MscInterrupt;            /* Interrupt level used */
        ushort  MscTxQDepth;             /* Transmit Queue Depth */
        ushort  MscMaxNumDataBlks;       /* Maximum number of data blocks   */

                                         /* V3.00.10 NDIS 2.02 enhancements */
        struct  MACStatInit far *MscMSIp;  /* Mac Status and Initialize table */
};
                                        /* V3.00.10 NDIS 2.02 enhancments    */

/*
 * MAC Statistics and Initialization table
 */
struct MACStatInit {
        uchar   MsiAdapterConfig;
        uchar   MsiRsvd;
        uchar   MsiMicrocodeLevel[10];
        LPBUF   MsiAdapterParmsAddr;
        LPBUF   MsiAdapterMacAddr;
        ushort  MsiSRAMAddr;
        ushort  MsiBringUps;
        ushort  MsiAdapterType;
};

/*
 * multicast address structure is ADDR_LEN bytes ulong
 */
struct MCastAddr {
        uchar   mAddr[ADDR_LEN];
};

/*
 * the multicast address buffer manages NUM_MCADDRS multicast address
 * structures.
 */
struct MCastBuf {
        ushort  McbMax;         /* max # of multicast addresses */
        ushort  McbCnt;         /* curr# "              "       " */

        struct MCastAddr McbAddrs[NUM_MCADDRS];
};

/*
 * MAC service-specific status table
 */
struct MACSpecStat {
        ushort  MssSize;           /* Table size                        */
        ulong   MssDiagDT;         /* Last diagnostic Date/Time         */
        ulong   MssStatus;         /* MAC status - bit mask             */
        ushort  MssFilter;         /* Current packet filter             */
        void far *MssM8Sp;         /* pointer to Media specific status  */
        ulong   MssClearDT;        /* Last clear stats Date/Time        */
        ulong   MssFR;             /* Frames received: total            */
        ulong   MssRFCRC;          /* Receive fail: CRC error           */
        ulong   MssFRByt;          /* Frames received: total bytes      */
        ulong   MssRFLack;         /* Receive fail: lack of buffers     */
        ulong   MssFRMC;           /* Frames received: multicast        */
        ulong   MssFRBC;           /* Frames received: broadcast        */
        ulong   MssRFErr;          /* rcv fail: errors in general       */
        ulong   MssRFMax;          /* rcv fail: exceeds max size        */
        ulong   MssRFMin;          /* rcv fail: less than min size      */
        ulong   MssFRMCByt;        /* Frames rcvd: multicast bytes      */
        ulong   MssFRBCByt;        /* Frames rcvd: broadcast bytes      */
        ulong   MssRFHW;           /* rcv fail: hardware error          */
        ulong   MssFS;             /* Frames sent: total                */
        ulong   MssFSByt;          /* Frames sent: total bytes          */
        ulong   MssFSMC;           /* Frames sent: multicast            */
        ulong   MssFSBC;           /* Frames sent: broadcast            */
        ulong   MssFSBCByt;        /* Frames sent: broadcast bytes      */
        ulong   MssFSMCByt;        /* Frames sent: multicast bytes      */
        ulong   MssSFTime;         /* Send fail: time-out               */
        ulong   MssSFHW;           /* Send fail: hardware error         */
};

/*
 * Packet filter bit definitions.
 */

#define FLTR_DIRECTED   0x01
#define FLTR_BRDCST     0x02
#define FLTR_PRMSCS     0x04
#define FLTR_SRC_RTG    0x08

/*
 * MAC status bits in MSS
 * bits 0-2 are coded to reflect the hardware status.
 */

#define MS_HW_MASK  0x0007

#define HW_MISSING  0x0000
#define HW_BUD_ERR  0x0001
#define HW_CFG_ERR  0x0002
#define HW_FAULT    0x0003
#define HW_SOFT_ERR 0x0004
#define HW_OK       0x0007

#define MS_BOUND    0x0008
#define MS_OPEN     0x0010
#define MS_DIAGS_ON 0x0020


/*
 * 802.3 status table
 */
struct MAC8023Stat {
        ushort  M83sSize;      /* Table size                     */
        ushort  M83sVer;       /* Version                        */
        ulong   M83sRFAln;     /* Receive fail: Alignment error  */
        ulong   M83sRMask;     /* Receive fail bit mask (below)  */
        ulong   M83sRFOvrn;    /* Receive fail: Overrun          */
        ulong   M83sFSCols;    /* Frames sent: after collisions  */
        ulong   M83sFSDfr;     /* Frames sent: after deferring   */
        ulong   M83sSFColMx;   /* Frames not sent: Max collisions*/
        ulong   M83sTotCol;    /* Total collision during tran attempts */
        ulong   M83sTotLCol;   /* Total late collisions          */
        ulong   M83sFSCol1;    /* Frames sent: after 1 collision */
        ulong   M83sFSColM;    /* Frames sent: multpl collisions */
        ulong   M83sFSHrtB;    /* Frames sent: CD heart beat     */
        ulong   M83sJabber;    /* Jabber errors                  */
        ulong   M83sLostCS;    /* Lost carrier sense during tran */
        ulong   M83sTMask;     /* Transmit fail bit mask (below) */
        ulong   M83snumunder;  /* V3.00.10 Number of underruns   */
        ushort  M83sRingUtil;  /* V3.00.10 Ring Utilization Measure */
};

#define M83Sb_RFCRC     1      /* Recv bit 0       CRC error          */
#define M83Sb_RFFE      2      /*          1       Framing error      */
#define M83Sb_RFMaxSz   4      /*          2       Frame size > Max   */

#define M83Sb_TFColMx   1      /* Xmit bit 0   Excessive collisions    */
#define M83Sb_TFCrr     2      /*          1       Carrier check failed*/
#define M83Sb_TFShrt    4      /*          2       Short circuit       */
#define M83Sb_TFOpen    8      /*          3       Open circuit        */
#define M83Sb_TFLong    16     /*          4       Frame size > Max    */
#define M83Sb_TFRemFl   32     /*          5       Remote fail to defer*/



/*
 * 802.5 status table
 */
struct MAC8025Stat {
        ushort  M85sSize;       /* Table size                       */
        ushort  M85sVer;        /* Version                          */
        ulong   M85sFCS;        /* FCS error or repeat frame code error */
        ulong   M85sRMask;      /* Receive fail bit mask (below)    */
        ulong   M85s5hbtt;      /* "5 half-bit transition" errors.  */
        ulong   M85sACerr;      /* Access Control errors            */
        ulong   M85sFsAbrtD;    /* Frames sent: w/ abort delimiter  */
        ulong   M85sFsNrcv;     /* Frames sent: Not received.       */
        ulong   M85sFrNoBuf;    /* Frames recognized, no buffers    */
        ulong   M85sFcopyErr;   /* Frame copy errors                */
        ulong   M85sFreqErr;    /* Frequency errors                 */
        ulong   M85sMonRegen;   /* Active Monitor regeneration count.   */
        ulong   M85sRsrvd1;     /* reserved                         */
        ulong   M85sRsrvd2;     /* reserved                         */
        ulong   M85sRsrvd3;     /* reserved                         */
        ulong   M85sTMask;      /* Transmit fail bit mask (below)   */
        ulong   M85snumunder;   /* V3.00.10 Number of underruns     */
        ushort  M85sRingUtil;   /* V3.00.10 Ring Utilization Measure */
};

#define M85Sb_RFCon     1       /* Recv bit0       Receiver Congestion  */
#define M85Sb_RFCopy    2       /*         1       Frame Copy error     */

#define M85Sb_TFunrun   1       /* Xmit bit 0   Transmit underrrun      */
#define M85Sb_TFLine    2       /*         1       Transmit Line error  */
#define M85Sb_TFAbDlm   4       /*         2       Abort delimiter xmitted */
#define M85Sb_TFLost    8       /*         3       Frame Lost           */
#define M85Sb_TFToken   16      /*         4       Token error          */


/*
 * the general request C function gets a pointer to a structure of this
 * type.
 */
struct GenReq {
        ushort  GReqProtID;
        ushort  GReqReqHandle;
        ushort  GReqP1;
        ulong   GReqP2;
        ushort  GReqOpCode;
        ushort  GReqMacDs;
};

/*
 * MAC upper dispatch table
 */
struct MACUprDisp {

        struct CommChar far *MudCCp;   /* Back pointer to CC table */

        /* MAC entry points, all are assembly functions. */

        LPFUN  MudGReq;
        LPFUN  MudXmitChain;
        LPFUN  MudXferData;
        LPFUN  MudRcvRelease;
        LPFUN  MudIndOn;
        LPFUN  MudIndOff;
};

/*
 * protocol lower dispatch table
 */
struct ProtLwrDisp {

        struct CommChar far *PldCCp;   /* Back pointer to CC table */

        ulong PldIFF;                                                                   /* Interface flags                                      */

        /* Protocol stack entry points. */
        /* NOTE: these functions are defined as returning long, even though
                 they return ushort so that h2inc.exe will generate the
                 correct sizes for ndis.inc
         */

        ulong  (far pascal *PldReqConfirm)(ushort,ushort,ushort,ushort,ushort,ushort);
        ulong  (far pascal *PldXmitConfirm)(ushort,ushort,ushort,ushort,ushort);
        ulong  (far pascal *PldRcvLkAhead)(ushort,ushort,ushort,LPBUF,LPBUF,ushort);
        ulong  (far pascal *PldIndComplete)(ushort,ushort);
        ulong  (far pascal *PldRcvChain)(ushort,ushort,ushort,LPBUF,LPBUF,ushort);
        ulong  (far pascal *PldStatInd)(ushort,ushort,LPBUF,ushort,ushort);

};

/*
 * Data structures for TransmitChain (Tx), TransferData (TD), and
 * ReceiveLookahed (Rx).
 */

struct TxDataBlock {
        uchar   TxPtrType;    /* 0 => Physical pointer, 1 => GDT pointer */
        uchar   TxRsvdByte;   /* Reserverd, must be zero.    */
        ushort  TxDataLen;    /* Data block length in bytes. */
        LPBUF TxDataPtr;      /* Far pointer to data block.  */
};
#define TDDataBlockShift 3 /* sizeof(TDDatablock) in power of 2 */
struct TDDataBlock {
        uchar   TDPtrType;    /* 0 => Physical pointer, 1 => GDT pointer  */
        uchar   TDRsvdByte;   /* Reserverd, must be zero.    */
        ushort  TDDataLen;    /* Data block length in bytes. */
        LPBUF TDDataPtr;      /* Far pointer to data block.  */
};
#define TxBufDescSize   8  /* sizeof(TxBufDesc) - TxDataBlk */
#define MAX_TX_DATABLK  8
#define MAX_IMMED_LEN   64
struct TxBufDesc {
        ushort  TxImmedLen;   /* Byte count of immediate data (max = 64) */
        LPBUF   TxImmedPtr;   /* Virtual address of Immediate data       */
        ushort  TxDataCount;  /* Number of Data Blocks (max = 8)         */

        struct TxDataBlock TxDataBlk[MAX_TX_DATABLK];
};


#define MAX_TD_DATABLK  8
struct TDBufDesc {
        ushort  TDDataCount;  /* Number of Data Blocks (max = 8) */

        struct TDDataBlock TDDataBlk[MAX_TD_DATABLK];
};

struct RxDataBlock {
        ushort  RxDataLen;    /* Length of the Data Block */
        LPBUF RxDataPtr;      /* Far Pointer to Data Block*/
};

#define MAX_RX_DATABLK  8
struct RxBufDesc {
        ushort  RxDataCount;   /* Number of Data Blocks.*/

        struct RxDataBlock RxDataBlk[MAX_RX_DATABLK];
};

/*
 * Data structures for the "Module Configuration" structure parsed from
 * the PROTOCOL.INI file. see NDIS spec for details.
 */

struct Param {

        ushort ParamType;  /* 0 => 31 bit signed integer, 1 => string      */
        ushort ParamLen;   /* String length (including null) or 4.         */

        /*
         * the parameter immediately follows this structure, it can be any
         * length or type and follows the union structure. the AWK script is
         * just dumb enough that it's not able to parse union definitions. so all
         * references to ParNum and ParStr are indirect.
         */

      union ParValu
         {
         ulong ParNum;
         uchar ParStr[1];
         } ParVal;

};

struct KeywordEntry {
        struct KeywordEntry far *NextKeywordEntry;    /* Forward pointer */
        struct KeywordEntry far *PrevKeywordEntry;    /* Back Pointer    */

        uchar   KeyWord[NAME_LEN];      /* Keyword on left side of "="   */
        ushort  NumParams;              /* Number of parameters on r. side of "="       */

        struct Param Params[1];         /* Actual size depends on NumParams                             */
};

struct ModCfg {
        struct ModCfg far *NextModCfg;  /* Module config images are in a   */
        struct ModCfg far *PrevModCfg;  /* double-linked list.   */

        uchar   ModName[NAME_LEN];      /* Bracketed Module Name.  */

        struct KeywordEntry KE[1];      /* Head of Keyword list, always one */

};                                                                              /* or more entries per module.                                  */

struct ProIni {
        struct ModCfg MC[1];            /* Head of Module config list.*/
};

/*
 * request block used to register a module
 */
struct RqBlk {
        ushort  Opcode;
        ushort  Status;
        void  far *Pointer1;
        void  far *Pointer2;
        ushort  Word1;
};

/*
 * the minimum lookahead defaults to 64
 */
#define MIN_LOOKAHEAD_DEFAULT 64
/*
 * the minimum buffer for a Read Error Log must be 14 bytes
 */
#define MIN_ERR_LOG_LEN       14


#endif

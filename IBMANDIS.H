/*$Log*/
// ibmandis.h

#define         MAX_PPATS            256

typedef         unsigned short       ANDIS_PCMID;     /* PCM ID for SCPI Calls */
typedef         unsigned short       ANDIS_REQHANDLE; /* Request Handle for SCPI Calls */
typedef         unsigned short       ANDIS_PARM_1;    /* Parameter 1 for SCPI Calls */
typedef         unsigned long        ANDIS_PARM_2;    /* Parameter 2 for SCPI Calls */
typedef         unsigned short       ANDIS_FC;        /* Function Code for SCPI Calls */
typedef         unsigned short       ANDIS_MAC_DS;    /* MAC DS Parm for SCPI Calls */

#define  ANDIS_PARMS  ANDIS_PCMID,ANDIS_REQHANDLE,ANDIS_PARM_1,ANDIS_PARM_2,ANDIS_FC,ANDIS_MAC_DS

typedef struct andis_ppat
{
   unsigned short PPAT_Length;      // Length of PPAT
   unsigned char  PPAT_Ver_Major;   // PPAT Structure Version Number
   unsigned char  PPAT_Ver_Minor;   // PPAT Structure Version Number
   unsigned short Port_Interface_Type; // 1 = SCPI
   unsigned char  Port_Interface_Version; // SCPI Version Number
   unsigned char  Conn_Type;        // Connection Type (1-Nonswitched,
                                    //                  2-Switched)
   unsigned char  Phys_Conn_State;  // Physical Connection State
                                    //    00h - Hardware Available, Present
                                    //    01h - Disconnected
                                    //    02h - Connect Pending
                                    //    03h - Connected
                                    //    04h - Disconnect Pending
                                    //    0Eh - Hardware not Present, awaiting insertion
                                    //    0Eh - Hardware Present, non-functional, unowned
                                    //    FEh - Hardware not Present, unowned
                                    //    FFh - Hardware not Present, non-functional, unowned
   unsigned char  ANDIS_MAC_Mode;   // Current Mode of an ANDIS MAC
                                    //    00h - Connection Mode
                                    //    01h - Protocol Mode
                                    //    02h - Unformatted Mode
                                    //    ffh - MAC Connection Management Disabled,
                                    //          PPAT Registration Failed
   unsigned short ANDIS_MAC_DS;     // MACS DS Value for the Current this Port
   void far  *MAC_CCT_ptr;          // Pointer to MACs Common Characteristics Table
   char       Port_Name[16];        // ASCIIZ
   char       Phys_Interface[16];   // ASCIIZ
   int (far pascal *MAC_PPAT_Mgmt)(ANDIS_PARMS);  // MAC's PPAT Management Entry Point
   int (far pascal *PPAT_Mgmt)(ANDIS_PARMS);   //  Registration Fac. PPAT Management Entry Point
   int (far pascal *Port_Mgmt)(ANDIS_PARMS);   // Port Management Entry Point
   int (far pascal *Xmit_Imm)(ANDIS_PARMS);    // Transmit Immediate Entry Point
   int (far pascal *Rcv_Imm_Cnf)(ANDIS_PARMS); // Receive Immediate Confirm Entry Point
   void far  *Port_Log_ptr;         // Pointer to Port Error Log
   unsigned long Max_Speed;         // Maximum Physical Port Speed
   unsigned long Max_Xmit_Buff;     // Maximum Transmit Immediate Buffer size
                                    // (Set by MAC), 0 - MAC doesn't care
   unsigned short Port_ID;          // Port ID/Address (AWP-209)
   unsigned char  Slot_Number;      // Slot Number of Hardware
   unsigned char  Port_Number;      // Port Number of Hardware
   unsigned char  Channel_Number;   // Channel Number of Hardware
   char       ANDIS_Align;          // Reserved space
   char       ANDIS_Reserve[6];     // Reserved space

} ANDISPPAT, far *PANDISPPAT;


typedef struct ppat_list_t {                         //List of PPAT's
 unsigned short             num_of_ppats;          //Number of PPATS
 PANDISPPAT                 ppat_array[MAX_PPATS]; //array of PPAT addresses
} PPAT_LIST, far *PPPAT_LIST;


/* PCM and Null DLC Entry Table */

typedef struct entrytbl_t
   {
      int (far pascal *PortMgmtInd)( ANDIS_PARMS );
      int (far pascal *RecvImmData)( ANDIS_PARMS );
      int (far pascal *XmitImmDataCnf)( ANDIS_PARMS );
      ANDIS_MAC_DS pcm_ds;
   } ENTRYTBL, far *PENTRYTBL;


/* ANDIS Function Codes */
/* Port Management      */

#define ANDIS_FC_REG_PCM         0x0000
#define ANDIS_FC_REL_PCM         0x0001
#define ANDIS_FC_ACT_MODE        0x0002
#define ANDIS_FC_RET_PPI_STAT    0x0003
#define ANDIS_FC_GET_PPAT_PARMS  0x0004
#define ANDIS_FC_SET_PPAT_PARMS  0x0005
#define ANDIS_FC_RESET_PORT      0x0006
#define ANDIS_FC_ACT_PHYS_CONN   0x0007
#define ANDIS_FC_DEACT_PHYS_CONN 0x0008
#define ANDIS_FC_REG_NULL_DLC    0x0009
#define ANDIS_FC_REL_NULL_DLC    0x000A
#define ANDIS_FC_ACT_DTR         0x000B
#define ANDIS_FC_ACT_RTS         0x000D

/* Port Management Ind  */

#define ANDIS_FC_CONN_ACTIVE     0x0000
#define ANDIS_FC_CONN_INACTIVE   0x0001
#define ANDIS_FC_PPI_SIGNAL      0x0002
#define ANDIS_FC_PPI_EXCEPTION   0x0003
#define ANDIS_FC_PM_REQ_COMPLETE 0x0004

/* Transmit Immediate   */

#define ANDIS_FC_TX_IMM_DATA     0x0000
#define ANDIS_FC_SEND_BREAK      0x0001

/* Transmit Immediate Confirm  */

#define ANDIS_FC_TX_IMM_DATA_CNF 0x0000

/* Receive Immediate   */

#define ANDIS_FC_RX_IMM_DATA     0x0000

/* Receive Immediate Confirm  */

#define ANDIS_FC_RX_IMM_DATA_CNF 0x0000

/* Update PPAT   */

#define ANDIS_FC_UPDATE_PPAT     0x0000

/* MAC Mode (Used in SCPI Word for Activate Mode primitive) */

#define ANDIS_MAC_MODE_CONN      0x0000
#define ANDIS_MAC_MODE_PROTOCOL  0x0001
#define ANDIS_MAC_MODE_DATA      0x0002


/* Reset Type (Used in SCPI Word for Reset Port primitive) */

#define ANDIS_RESET_SOFT         0x0000
#define ANDIS_RESET_HARD         0x0001

/* Connect Mode (Used in SCPI Word for Activate Phys Conn primitive) */

#define ANDIS_CONN_MODE_PCM      0x0000
#define ANDIS_CONN_MODE_DLC      0x0001
#define ANDIS_CONN_MODE_NULL_DLC 0x0002

/* SCPI Return Codes */

#define ANDIS_RC_SUCCESS         0x0000
#define ANDIS_RC_REQ_QUEUED      0x0002
#define ANDIS_RC_OUT_OF_RESOURCE 0x0006
#define ANDIS_RC_INVALID_PARM    0x0007
#define ANDIS_RC_INVALID_FUNC    0x0008
#define ANDIS_RC_NOT_SUPPORTED   0x0009
#define ANDIS_RC_HW_ERROR        0x000A
#define ANDIS_RC_TRANSMIT_ERROR  0x000B
#define ANDIS_RC_BUFF_TOO_SMALL  0x000D
#define ANDIS_RC_DRIVER_NOT_INIT 0x0022
#define ANDIS_RC_HW_NOT_FOUND    0x0023
#define ANDIS_RC_HW_FAILURE      0x0024
#define ANDIS_RC_CONFIG_FAILURE  0x0025
#define ANDIS_RC_INT_CONFLICT    0x0026
#define ANDIS_RC_INCOMPAT_MAC    0x0027
#define ANDIS_RC_INIT_FAILED     0x0028
#define ANDIS_RC_NO_BINDING      0x0029
#define ANDIS_RC_NET_NOT_CONN    0x002A
#define ANDIS_RC_INCOMPAT_OS_VER 0x002B
#define ANDIS_RC_ALREADY_REG     0x002C
#define ANDIS_RC_PATH_NOT_FOUND  0x002D
#define ANDIS_RC_INSUF_MEM       0x002E
#define ANDIS_RC_INFO_NOT_FOUND  0x002F
#define ANDIS_RC_GEN_FAILURE     0x00FF



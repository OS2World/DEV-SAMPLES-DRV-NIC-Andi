/*$Log: andis.h $
 * Revision 1.4  93/03/29  17:53:50  DAN
 * changed line "typedef struct xvppat" to "typedef struct xvppat_t"
 * (immediate typedef'ing should not affect .c files, and few other
 * .h files, though.)
 *
 * Revision 1.3  92/09/11  11:46:54  JJM
 * now uses ibmandis.h for the header part of ppat
 *
 * Revision 1.2  92/09/08  12:47:01  JJM
 * added some new defs
 *
 * Revision 1.1  92/09/02  19:05:44  JJM
 * Initial revision
 * */
/***************************************************************************
*file: andis.h
*function:  This is the interface module for the andis.c module.
*changes:
*    SV_ANDIS added;
*    USHORT- to ushort
*    to the 3 typedef's, needed to name the  struct
****************************************************************************/

/*the following are defs I've added .........       */

/*create defines for the ppat's Phys_Conn_State field */
#define SCPI_PCS_AVAILABLE    0x00     // hardware available AND present
#define SCPI_PCS_DISCONNECTED 0x01     // Disconnected
#define SCPI_PCS_CONN_PENDING 0x02     // Connect Pending
#define SCPI_PCS_CONNECTED    0x03     // Connected
#define SCPI_PCS_DISC_PENDING 0x04     // Disconnect Pending

/*defines for Conn_Type field */
#define SCPI_CT_NONSWITCHED  0x01      // non switched connection type
#define SCPI_CT_SWITCHED     0x02      // switched connection type

#define         SV_ANDIS              0x40000

#include        "ibmandis.h"

#define         XVLOG                 0x80

#define         REGDEV                  01
#define         STARTREG                02
#define         GETLST                  03

#define         SCPI_PCMID           ANDIS_PCMID      /* PCM ID for SCPI Calls */
#define         SCPI_REQHANDLE       ANDIS_REQHANDLE  /* Request Handle for SCPI Calls */
#define         SCPI_PARM_1          ANDIS_PARM_1     /* Parameter 1 for SCPI Calls */
#define         SCPI_PARM_2          ANDIS_PARM_2     /* Parameter 2 for SCPI Calls */
#define         SCPI_FC              ANDIS_FC         /* Function Code for SCPI Calls */
#define         SCPI_MAC_DS          ANDIS_MAC_DS     /* MAC DS Parm for SCPI Calls */

#define  SCPI_PARMS ANDIS_PARMS

typedef struct xvppat_t
{
   ANDISPPAT      Header;
   unsigned short PPI_Status;       // Physical Port Interface Status
                                    // Bit   0 - DTR, Bit   1 - RTS
                                    // Bit   2 - HDR, Bit   3 - Unused
                                    // Bit   4 - CTS, Bit   5 - DSR
                                    // Bit   6 - RI,  Bit   7 - DCD
   unsigned long Port_Attribs;      // Port Attribute Indicator
                                    // Bit  0 - Port Active
                                    // Bit  1 - Port Owned
                                    // Bit  2 - Port Parameters Modifiable
                                    // Bit  3 - V.25bis Supported
                                    // Bit  4 - V.54 Supported
                                    // Bit  5 - Async Supported
                                    // Bit  6 - BiSync Supported
                                    // Bit  7 - Sync (HDLC) Supported
                                    // Bit  8 - Mode is Software
                                    //          Selectable/Resetable
                                    // Bit  9 - Data Mode Active
                                    // Bit 10 - High Data Rate (HDR)
                                    //          Mode Supported
                                    // Bit 11 - Port Monitors Ring
                                    //          Indicate (RI)
                                    // Bit 12 - NRZI/NRZ Supported
                                    // Bit 13 - XON/XOFF Flow Control
                                    //          Supported
                                    // Bit 14 - Hardware Handshaking
                                    // Bit 15 - ISO 3309.2 Supported
                                    // Bit 16 - AWP 0224 Supported
                                    // Bit 17 - Novell Async Supported
                                    // Bit 18 - Bisync Supported
                                    // Bit 19 - HDLC Supported
                                    // Bit 20-31 - Reserved
   unsigned char Clock_Type;        // Clocking Type - AWP-0209
                                    //    01h - Internal-Sync
                                    //    02h - External
                                    //    04h - Local Attach
                                    //    11h - Internal Async
   unsigned char XVRESERVE_1;       // Reserved
// NOTE:  The rest of the PPAT can be modified by a PCM or NULL DLC.
   unsigned long Xmit_Speed;        // Transmit Speed
   unsigned long Rcv_Speed;         // Receive Speed
   unsigned char Comm_Type;         // Communication Type - AWP-0209
                                    //    01h - Half Duplex (HDX)
                                    //    02h - Full Duplex (FDX)
                                    //    03h - FDX Facility
   unsigned char Port_Mode;         // Current framing mode
                                    //    01h - ISO 3309.2
                                    //    02h - AWP 0224
                                    //    03h - Novell Async
                                    //    04h - BiSync
                                    //    05h - HDLC
   unsigned char Transparency;      // 00h - Negotiated 01h - None (Null DLC)
                                    // 02h - Flow Control, 03h - Full
   unsigned char Hard_Hand;         // Hardware Handshaking Type
                                    //    Bit   0 - Inbound XON/XOFF
                                    //    Bit   1 - Outbound XON/XOFF
                                    //    Bit   2 - CTS Handshaking
                                    //    Bit   3 - RTS Handshaking
                                    //    Bit   4 - DSR Handshaking
                                    //    Bit   5 - DTR Handshaking
                                    //    Bit   6 - Reserved
   unsigned char XOFF_Char;         // 13h - Default
   unsigned char XON_Char;          // 11h - Default
   unsigned short Port_Trans_Mode;  // Port Transfer Mode
                                    // For Async
                                    //  Bits 0-3 - Bits per Character
                                    //  Bits 4-5 - Number of Start/Stop Bits
                                    //             00h - 1 Bit
                                    //             01h - 1.5 Bits
                                    //             02h - 2 Bits
                                    //  Bit  6-8 - Parity
                                    //             00h - None
                                    //             01h - Even
                                    //             02h - Odd
                                    //             03h - Mark
                                    //             04h - Space
                                    // For Sync
                                    //  0h - NRZ
                                    //  1h - NRZI
   unsigned short Signal_Mask;      // Signal Indication Mask
                                    //      Bit   0 - DTR
                                    //      Bit   1 - RTS
                                    //      Bit   2 - HDR
                                    //      Bit   3 - Unused
                                    //      Bit   4 - CTS
                                    //      Bit   5 - DSR
                                    //      Bit   6 - RI
                                    //      Bit   7 - DCD
                                    //      Bits  8-15 - Reserved
                                    //
                                    //   NOTE:  A value of one in any bit posi-
                                    //   tion indicates that the upper layer
                                    //   (the PCM or DLC) is interested in the
                                    //   coresponding signal.
   unsigned short Hw_Err_Mask;      // Hardware Error Mask
                                    //    Bit   0 - DSR Dropped
                                    //    Bit   1 - CTS Dropped
                                    //    Bit   2 - DCD Dropped
                                    //    Bit   3 - DSR Hot
                                    //    Bit   4 - DSR Dead
                                    //    Bit   5 - CTS Dead
                                    //    Bit   6 - DCD Dead
                                    //    Bit   7 - DSR Stuck
                                    //    Bit   8 - CTS Stuck
                                    //    Bit   9 - DCD Stuck
                                    //    Bit  10 - CTS Hot HDX
                                    //    Bit  11 - Break Detected
                                    //    Bit  12 - Parity Error
                                    //    Bit  13 - Framing Error
                                    //    Bit  14 - Hardware Overrun
                                    //    Bit  15 - Receive Buffer Overflow
                                    //
                                    // NOTE:  A value of one in any bit posi-
                                    // tion indicates that the upper layer
                                    // (the PCM or DLC) is interested in the
                                    // coresponding error.
} XVPPAT, far *PXVPPAT;

/* SCPI Function Codes */

#define SCPI_FC_REG_PCM         ANDIS_FC_REG_PCM
#define SCPI_FC_REG_NULL_DLC    ANDIS_FC_REG_NULL_DLC
#define SCPI_FC_REL_PCM         ANDIS_FC_REL_PCM
#define SCPI_FC_REL_NULL_DLC    ANDIS_FC_REL_NULL_DLC
#define SCPI_FC_ACT_MODE        ANDIS_FC_ACT_MODE
#define SCPI_FC_RET_PPI_STAT    ANDIS_FC_RET_PPI_STAT
#define SCPI_FC_GET_PPAT_PARMS  ANDIS_FC_GET_PPAT_PARMS
#define SCPI_FC_SET_PPAT_PARMS  ANDIS_FC_SET_PPAT_PARMS
#define SCPI_FC_RESET_PORT      ANDIS_FC_RESET_PORT
#define SCPI_FC_ACT_PHYS_CONN   ANDIS_FC_ACT_PHYS_CONN
#define SCPI_FC_DEACT_PHYS_CONN ANDIS_FC_DEACT_PHYS_CONN
#define SCPI_FC_ACT_DTR         ANDIS_FC_ACT_DTR
#define SCPI_FC_ACT_RTS         ANDIS_FC_ACT_RTS

#define PORT_MGMT_IND_MIN       0x0020
#define SCPI_FC_CONN_ACTIVE     (ANDIS_FC_CONN_ACTIVE     + PORT_MGMT_IND_MIN)
#define SCPI_FC_CONN_INACTIVE   (ANDIS_FC_CONN_INACTIVE   + PORT_MGMT_IND_MIN)
#define SCPI_FC_PPI_SIGNAL      (ANDIS_FC_PPI_SIGNAL      + PORT_MGMT_IND_MIN)
#define SCPI_FC_PPI_EXCEPTION   (ANDIS_FC_PPI_EXCEPTION   + PORT_MGMT_IND_MIN)
#define SCPI_FC_PM_REQ_COMPLETE (ANDIS_FC_PM_REQ_COMPLETE + PORT_MGMT_IND_MIN)

#define XMIT_DATA_MIN           0X0030
#define SCPI_FC_TX_IMM_DATA     (ANDIS_FC_TX_IMM_DATA     + XMIT_DATA_MIN)
#define SCPI_FC_SEND_BREAK      (ANDIS_FC_SEND_BREAK      + XMIT_DATA_MIN)

#define XMIT_DATA_CNF_MIN       0X0040
#define SCPI_FC_TX_IMM_DATA_CNF (ANDIS_FC_TX_IMM_DATA_CNF + XMIT_DATA_CNF_MIN)

#define RECV_DATA_MIN           0X0050
#define SCPI_FC_RX_IMM_DATA     (ANDIS_FC_RX_IMM_DATA     + RECV_DATA_MIN)

#define XMIT_CNFM_MIN           0x0060
#define SCPI_FC_RX_IMM_DATA_CNF (ANDIS_FC_RX_IMM_DATA_CNF + XMIT_CNFM_MIN)

#define SCPI_FC_UPDATE_PPAT     (ANDIS_FC_UPDATE_PPAT     + 0x0070)


/* MAC Mode (Used in SCPI Word for Activate Mode primitive) */

#define SCPI_MAC_MODE_CONN      ANDIS_MAC_MODE_CONN
#define SCPI_MAC_MODE_PROTOCOL  ANDIS_MAC_MODE_PROTOCOL
#define SCPI_MAC_MODE_DATA      ANDIS_MAC_MODE_DATA


/* Reset Type (Used in SCPI Word for Reset Port primitive) */

#define SCPI_RESET_SOFT         ANDIS_RESET_SOFT
#define SCPI_RESET_HARD         ANDIS_RESET_HARD


/* Connect Mode (Used in SCPI Word for Activate Phys Conn primitive) */

#define SCPI_CONN_MODE_PCM      ANDIS_CONN_MODE_PCM
#define SCPI_CONN_MODE_DLC      ANDIS_CONN_MODE_DLC
#define SCPI_CONN_MODE_NULL_DLC ANDIS_CONN_MODE_NULL_DLC


/* State (Used in SCPI Word for Activate DTR and Activate RTS primitives) */

#define SCPI_STATE_DEACTIVATE   0x0000
#define SCPI_STATE_ACTIVATE     0x0001


/* PPI Exception (Used in SCPI Word for PPI Exception primitive) */

#define SCPI_XCPT_DSR_DROPPED   0x0001
#define SCPI_XCPT_CTS_DROPPED   0x0002
#define SCPI_XCPT_DCD_DROPPED   0x0004
#define SCPI_XCPT_DSR_HOT       0x0008
#define SCPI_XCPT_DSR_DEAD      0x0010
#define SCPI_XCPT_CTS_DEAD      0x0020
#define SCPI_XCPT_DCD_DEAD      0x0040
#define SCPI_XCPT_DSR_STUCK     0x0080
#define SCPI_XCPT_CTS_STUCK     0x0100
#define SCPI_XCPT_DCD_STUCK     0x0200
#define SCPI_XCPT_CTS_HOT_HDX   0x0400
#define SCPI_XCPT_BREAK_DET     0x0800
#define SCPI_XCPT_PARITY_ERR    0x1000
#define SCPI_XCPT_FRAMING_ERR   0x2000
#define SCPI_XCPT_HW_OVERRUN    0x4000
#define SCPI_XCPT_RX_OVERFLOW   0x8000


/* PPI Status (Used in SCPI Word for several primitives) */

#define SCPI_PPI_STAT_DTR       0x0001
#define SCPI_PPI_STAT_RTS       0x0002
#define SCPI_PPI_STAT_HDR       0x0004
#define SCPI_PPI_STAT_CTS       0x0010
#define SCPI_PPI_STAT_DSR       0x0020
#define SCPI_PPI_STAT_RI        0x0040
#define SCPI_PPI_STAT_DCD       0x0080


/* SCPI Return Codes */

#define SCPI_RC_SUCCESS         ANDIS_RC_SUCCESS
#define SCPI_RC_REQ_QUEUED      ANDIS_RC_REQ_QUEUED
#define SCPI_RC_OUT_OF_RESOURCE ANDIS_RC_OUT_OF_RESOURCE
#define SCPI_RC_INVALID_PARM    ANDIS_RC_INVALID_PARM
#define SCPI_RC_INVALID_FUNC    ANDIS_RC_INVALID_FUNC
#define SCPI_RC_NOT_SUPPORTED   ANDIS_RC_NOT_SUPPORTED
#define SCPI_RC_HW_ERROR        ANDIS_RC_HW_ERROR
#define SCPI_RC_TRANSMIT_ERROR  ANDIS_RC_TRANSMIT_ERROR
#define SCPI_RC_BUFF_TOO_SMALL  ANDIS_RC_BUFF_TOO_SMALL
#define SCPI_RC_DRIVER_NOT_INIT ANDIS_RC_DRIVER_NOT_INIT
#define SCPI_RC_HW_NOT_FOUND    ANDIS_RC_HW_NOT_FOUND
#define SCPI_RC_HW_FAILURE      ANDIS_RC_HW_FAILURE
#define SCPI_RC_CONFIG_FAILURE  ANDIS_RC_CONFIG_FAILURE
#define SCPI_RC_INT_CONFLICT    ANDIS_RC_INT_CONFLICT
#define SCPI_RC_INCOMPAT_MAC    ANDIS_RC_INCOMPAT_MAC
#define SCPI_RC_INIT_FAILED     ANDIS_RC_INIT_FAILED
#define SCPI_RC_NO_BINDING      ANDIS_RC_NO_BINDING
#define SCPI_RC_NET_NOT_CONN    ANDIS_RC_NET_NOT_CONN
#define SCPI_RC_INCOMPAT_OS_VER ANDIS_RC_INCOMPAT_OS_VER
#define SCPI_RC_ALREADY_REG     ANDIS_RC_ALREADY_REG
#define SCPI_RC_PATH_NOT_FOUND  ANDIS_RC_PATH_NOT_FOUND
#define SCPI_RC_INSUF_MEM       ANDIS_RC_INSUF_MEM
#define SCPI_RC_INFO_NOT_FOUND  ANDIS_RC_INFO_NOT_FOUND
#define SCPI_RC_GEN_FAILURE     ANDIS_RC_GEN_FAILURE



/******************************************************************************
*                                                                             *
*   Module:     DisassemblerInterface.h                                       *
*                                                                             *
*   Revision:   1.00                                                          *
*                                                                             *
*   Date:       3/17/2000                                                     *
*                                                                             *
*   Author:     Goran Devic                                                   *
*                                                                             *
*******************************************************************************

    Module Description:

        This is a header file containing the interface definitions for
        a generic Intel disassembler.

*******************************************************************************
*                                                                             *
*   Changes:                                                                  *
*                                                                             *
*   DATE     DESCRIPTION OF CHANGES                               AUTHOR      *
* --------   ---------------------------------------------------  ----------- *
* 3/17/2000  Original                                             Goran Devic *
* 4/26/2000  Major rewrite                                        Goran Devic *
* --------   ---------------------------------------------------  ----------- *
*******************************************************************************
*   Important Defines                                                         *
******************************************************************************/
#ifndef _DISASM_INT_H_
#define _DISASM_INT_H_

/******************************************************************************
*                                                                             *
*   Include Files                                                             *
*                                                                             *
******************************************************************************/

/******************************************************************************
*                                                                             *
*   Global Defines, Variables and Macros                                      *
*                                                                             *
******************************************************************************/

/******************************************************************************
*
*   This structure is used to pass parameters and options to the
*   line disassembler.
*
******************************************************************************/
typedef struct
{
    DWORD dwFlags;              // Generic flags (described below)
    BYTE *bpTarget;             // Target pointer to disassemble
    BYTE *bpEffTarget;          // Effective target address to print
    BYTE *szDisasm;             // String where to put ascii result
    BYTE bAsciiLen;             // Length of the ascii result
    BYTE bInstrLen;             // Instruction lenght in bytes

    int nDisplacement;          // Scanner: possible constant displacement
    int nScanEnum;              // Scanner: specific flags SCAN_*

} TDisassembler;

// dwFlags contains a set of boolean flags with the following functionality

#define DIS_DATA32          0x0001  // Data size 16/32 bits (0/1)
#define   DIS_GETDATASIZE(flags) ((flags)&DIS_DATA32)
#define DIS_ADDRESS32       0x0002  // Address size 16/32 bits (0/1)
#define   DIS_GETADDRSIZE(flags) (((flags)&DIS_ADDRESS32)?1:0)

#define DIS_SEGOVERRIDE     0x0004  // Default segment has been overriden

#define DIS_REP             0x0100  // Return: REP prefix found (followed by..)
#define DIS_REPNE           0x0200  // Return: REPNE prefix found
#define   DIS_GETREPENUM(flags)  (((flags)>>8)&3)
#define DIS_ILLEGALOP       0x8000  // Return: illegal opcode

/******************************************************************************
*                                                                             *
*   External Functions                                                        *
*                                                                             *
******************************************************************************/

extern BYTE Disassembler( TDisassembler *pDis );
extern DWORD GetDisFlags(void);


#endif //  _DISASM_INT_H_

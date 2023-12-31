/**************************************************************************
    BuguRTOS-4.0.x (Bugurt real time operating system)
    Copyright (C) 2018 anonimous

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    Please contact with me by E-mail: shkolnick.kun@gmail.com

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes BuguRTOS, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
**************************************************************************/

/*****************************************************************************************
```````````````````````````````..:+oyhdmNNMMMMMMNmmdhyo+:..```````````````````````````````
``````````````````````````.:oydNMMMMMMMMMNNNNNNNNMMMMMMMMMNdy+:.``````````````````````````
```````````````````````:sdNMMMMMNdys+/::----------::/osydNMMMMMNds:```````````````````````
```````````````````.+hNMMMMmho/-..........................-/shmMMMMNh/.```````````````````
````````````````./hNMMMNho:...................................-:ohNMMMNh/`````````````````
``````````````.smMMMNy/-.......:////ss++/+-.......................-+yNMMMmo.``````````````
````````````-sNMMMd+-.....:////:-...-/s::..............+o/-..........-odMMMNs.````````````
``````````.sNMMNh/....................................-o:--............./hMMMNo.``````````
`````````+mMMMh:-........................................-...............-/dMMMm/`````````
```````.yMMMm/...................-::--..................:-........--........+mMMMy.```````
``````:mMMMy-.......................-::-...............-:.........-::........-yMMMd:``````
`````/NMMN+-..................::-.....-:-............../--.........-:/-.......-+NMMN:`````
````+NMMm::o/-..--/+o+o+++++o+osys+//::-::.............:/....-:-::-..-++-.......:NMMN/````
```/NMMm:.-++-+yhs/-``       `dMMMMMmho+:-..............:-/+yho/:/+oyo//o-......./mMMN:```
``-NMMm/....-/--::/o+o+oo+oo++oosyss+smyo/.............:yyho-`     smMMddh-......./NMMN.``
`.hMMM/......-++:-.-:oooooooooosyyhhys/...............-+osyyyyysssssooo+ohhs-......+MMMh.`
`+MMMy.......-::/++:-.....-:/++++o+o/--................--/oooo+o++o+++////-y/.......hMMM/`
.mMMN:.........--:---...-::/+//::--.......................--//+//-...-.....+/......./NMMd`
/MMMy............-::----------....----/+-.....................-++/:---....-o-........hMMN:
yMMM/.............--:://///oo+++/+++oo+-.......................-://+/:--::::.........+MMMs
mMMN:................----:/h:::/:/::---.........................--/osss+++:..........:NMMd
MMMd-....................:mNs:-....................................--:odo:-..........:mMMN
MMMd-....................yoshyoso:--................................../mm/...........:mMMM
MMMm:..................../-o/h.y-:+dooo+/:--....................-/osydddmh...........:mMMN
mMMN:........................+mNs `h.  -d/:/+h++ooooy+++s++y+++mo+y` yh.do...........:NMMh
sMMM+........................-hmMo/ds  oMo`.-o     :h   s:`h` `Nysd.-Ny-h:...........+MMMo
/MMMh........................./smMMMMd+NMMNNMh`    sN: .mNNMddNMMMMNmN+..............hMMN:
.dMMN/........................./+hMMMMMMMMMMMMmhyyyNMNNMMMMMMMMMMMNsoo-............./NMMd`
`+MMMh.........................-/+omMMMMMMMMMMMMMMMMMMMMMMMMMMMMms-/+...............hMMM/`
`.hMMM+..........................:/-omMMMMMMMMMMMMMMMdmMdhMMMds/-..-...............oMMMy``
``.NMMN/............................--/hNN/h.`ys:dmsd:-syos+--+.................../NMMN.``
```/NMMm:...........................:+/--:+s++oo+osoo+/:-..-/+::-................/mMMN:```
````/NMMN:............................-/++/:-..........-//+/-..:+.--............/NMMN/````
`````:NMMN+-.............../+-.............-://////////:-.......+s+::.........-oNMMN:`````
``````:mMMMy-..............:/o-.................................:yo//........-hMMMd-``````
```````.yMMMm+.............:o:++-...............................+y+o-......-+mMMMs.```````
`````````/mMMMd/-...........-++:+/-.---........................-ho+/.....-/dMMMm/`````````
``````````.oNMMMh/............-++:++/////:....................-yo:o-...-+hMMMNo.``````````
````````````.sNMMMdo-...........-++::++:-:/+//:..............:o:/o-..-omMMMNo.````````````
``````````````.omMMMNy+-..........-/+-.:/+/:--:+++/++//:/::/+/-+/.-+hMMMMmo```````````````
`````````````````/hNMMMNho:-...............-:/:-....--::::--..-/ohNMMMNy:`````````````````
```````````````````./hNMMMMmhs/-..........................-/shNMMMMNy/.```````````````````
```````````````````````:sdNMMMMMNdhso+/:----------:/+oshdNMMMMMNho:```````````````````````
``````````````````````````.:+ydNMMMMMMMMMMNNNNNNMMMMMMMMMMmds+:```````````````````````````
````````````````````````````````.:/osyhdmNNMMMMNNmdhyso/:.````````````````````````````````
******************************************************************************************
*                                                                                        *
*                   This logo was graciously delivered by 10003-kun ITT:                 *
*                                                                                        *
*                           http://www.0chan.ru/r/res/9996.html                          *
*                                                                                        *
*****************************************************************************************/
#ifndef BGRT_ATM_GEN_1_H
#define BGRT_ATM_GEN_1_H
BGRT_CDECL_BEGIN

#define BGRT_ATM_INIT_ISR(map_ptr) do{*(map_ptr) = (bgrt_map_t)0;}while(0)

static inline void bgrt_atm_init(bgrt_map_t * fic) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_INT_LOCK();
    BGRT_ATM_INIT_ISR(fic);
    BGRT_INT_FREE();
}

#define BGRT_ATM_BSET_ISR(map_ptr, msk) do{ *(map_ptr) |= (msk); }while(0)

static inline void bgrt_atm_bset(bgrt_map_t * fic, bgrt_map_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    BGRT_INT_LOCK();
    BGRT_ATM_BSET_ISR(fic,msk);
    BGRT_INT_FREE();
}

#define BGRT_ATM_BGET_ISR(map_ptr, msk) (*(map_ptr) & (msk))

static inline bgrt_map_t bgrt_atm_bget(bgrt_map_t * fic, bgrt_map_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    bgrt_map_t ret;
    BGRT_INT_LOCK();
    ret = BGRT_ATM_BGET_ISR(fic,msk);
    BGRT_INT_FREE();
    return ret; /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

#define BGRT_ATM_BCLR_ISR(map_ptr, msk) (__bgrt_atm_bclr_isr((map_ptr), (msk)))
static inline bgrt_map_t __bgrt_atm_bclr_isr(bgrt_map_t * fic, bgrt_map_t msk)
{
    bgrt_map_t ret;
    /* Get states */
    ret = *fic & msk; /* ADLINT:SL:[W0422,W0165] NULL ptr deref*/
    /* Clear states */
    *fic &= ~msk;     /* ADLINT:SL:[W0422,W0165,W0578] NULL ptr deref*/
    return ret;           /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

static inline bgrt_map_t bgrt_atm_bclr(bgrt_map_t * fic, bgrt_map_t msk) /* ADLINT:SL:[W0629] linkage*/
{
    bgrt_map_t ret;
    BGRT_INT_LOCK();
    ret = BGRT_ATM_BCLR_ISR(fic,msk);
    BGRT_INT_FREE();
    return ret;         /* ADLINT:SL:[W0256,W0268] ret type check fail*/
}

#ifndef BGRT_VINT_PUSH_ISR
#   define BGRT_VINT_PUSH_ISR    bgrt_vint_push_isr
#endif /*BGRT_VINT_PUSH_ISR*/

BGRT_CDECL_END
#endif /*BGRT_ATM_GEN_1_H*/

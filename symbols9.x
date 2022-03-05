
/* arm9 */

CP_RestoreContext = 0x1FF8000;
CP_SaveContext = 0x1FF806C;
OS_DisableIrqMask = 0x1FF80E0;
OS_EnableIrqMask = 0x1FF8128;
OS_LoadContext = 0x1FF8164;
OS_ResetRequestIrqMask = 0x1FF81A8;
OS_SaveContext = 0x1FF81DC;
OS_SetIrqMask = 0x1FF8228;
OSi_IrqCallback = 0x1FF825C;
OSi_IrqDma2 = 0x1FF8318;
OSi_IrqDma3 = 0x1FF8328;
OSi_IrqTimer0 = 0x1FF8338;
OSi_IrqTimer1 = 0x1FF8348;
OSi_IrqTimer2 = 0x1FF8358;
OSi_IrqTimer3 = 0x1FF8368;
MI_StopDma = 0x1FF8378;
MI_IsDmaBusy = 0x1FF83FC;
MI_HBlankDmaCopy16 = 0x1FF8420;
MIi_CheckAnotherAutoDMA = 0x1FF8494;
OS_WakeupThread = 0x1FF8548;
OSi_RemoveLinkFromQueue = 0x1FF85C8;
OS_RescheduleThread = 0x1FF85FC;
OS_SelectThread = 0x1FF86E8;
G3dDrawInternal_ = 0x1FF8C50;
G3dDrawInternal_Loop_ = 0x1FF8DD8;
NNS_G3dDraw = 0x1FF8E44;
NNS_G3dGeBufferOP_N = 0x1FF8F20;
NNS_G3dGeFlushBuffer = 0x1FF9010;
NNS_G3dGeSendDL = 0x1FF9084;
NNS_G3dGeWaitSendDL = 0x1FF9144;
MI_SendGXCommandAsync = 0x1FFA244;
MI_WaitDma = 0x1FFA358;
MIi_CheckDma0SourceAddress = 0x1FFA3C8;
MIi_DMACallback = 0x1FFA438;
MIi_DmaSetParams = 0x1FFA4AC;
MIi_FIFOCallback = 0x1FFA4FC;
OS_DisableInterrupts = 0x1FFA5C4;
OS_DisableInterrupts_IrqAndFiq = 0x1FFA5D8;
OS_EnableInterrupts = 0x1FFA5EC;
OS_EnableInterrupts_IrqAndFiq = 0x1FFA600;
OS_GetIrqFunction = 0x1FFA614;
OS_GetProcMode = 0x1FFA6A0;
OS_Halt = 0x1FFA6AC;
OS_RestoreInterrupts = 0x1FFA6C0;
OS_RestoreInterrupts_IrqAndFiq = 0x1FFA6D8;
OS_SetIrqFunction = 0x1FFA6F0;
OS_SpinWait = 0x1FFA780;
OSi_EnterDmaCallback = 0x1FFA78C;
OSi_IdleThreadProc = 0x1FFA7D8;
PXIi_HandlerRecvFifoNotEmpty = 0x1FFA7EC;
PxiFifoCallback = 0x1FFA910;
SNDi_CallAlarmHandler = 0x1FFA940;
OS_GetTick = 0x1FFA9A0;
NNSi_G3dAnmBlendJnt = 0x1FFAA50;
NNSi_G3dAnmCalcNsBca = 0x1FFAD38;
MTX_Identity22_ = 0x1FFB6E4;
MTX_Identity33 = 0x1FFB6FC;
MTX_Copy33To43 = 0x1FFB720;
MTX_RotX33 = 0x1FFB74C;
MTX_RotY33 = 0x1FFB768;
MTX_RotZ33 = 0x1FFB784;
MTX_MultVec33 = 0x1FFB79C;
MTX_Concat33 = 0x1FFB820;
MTX_RotAxis33 = 0x1FFB9BC;
MTX_ScaleApply33 = 0x1FFBB1C;
MTX_Identity43_ = 0x1FFBBE0;
MTX_Copy43To44_ = 0x1FFBC08;
MTX_Scale43_ = 0x1FFBC3C;
MTX_RotX43_ = 0x1FFBC54;
MTX_RotY43_ = 0x1FFBC74;
MTX_RotZ43_ = 0x1FFBC90;
MTX_MultVec43 = 0x1FFBCAC;
MTX_Concat43 = 0x1FFBD60;
MTX_Inverse43 = 0x1FFBF80;
MTX_RotAxis43 = 0x1FFC314;
MTX_ScaleApply43 = 0x1FFC338;
MTX_Identity44_ = 0x1FFC378;
MTX_Copy44To43_ = 0x1FFC3A4;
MTX_Concat44 = 0x1FFC3D8;
FX_ModS32 = 0x1FFC6FC;
FX_DivAsync = 0x1FFC754;
FX_GetSqrtResult = 0x1FFC78C;
FX_SqrtAsync = 0x1FFC7B8;
FX_InvAsync = 0x1FFC808;
FX_GetDivResult = 0x1FFC844;
FX_GetDivResultFx64c = 0x1FFC880;
FX_InvSqrt = 0x1FFC8A8;
FX_Sqrt = 0x1FFC918;
FX_Div = 0x1FFC9C0;
FX_Inv = 0x1FFC968;
VEC_Fx16Normalize = 0x1FFC9DC;
VEC_Normalize = 0x1FFCB30;
VEC_Mag = 0x1FFCC70;
VEC_Fx16CrossProduct = 0x1FFCCD8;
VEC_CrossProduct = 0x1FFCD44;
VEC_Fx16DotProduct = 0x1FFCDE0;
VEC_DotProduct = 0x1FFCE30;
VEC_Subtract = 0x1FFCE74;
VEC_Add = 0x1FFCEA8;
FX_Atan2Idx = 0x1FFCEDC;
FX_Init = 0x1FFD0B0;
OS_IrqHandler = 0x1FFD5E4;
OS_IrqHandler_ThreadSwitch = 0x1FFD63C;
OSi_DoBoot = 0x1FFD798;
CpuClear32 = 0x1FFD848;
OSi_ReadCardRom32 = 0x1FFD85C;
OSi_ReloadRomData = 0x1FFD98C;
OSi_DoResetSystem = 0x1FFDA6C;
MIi_DmaSetParams_wait_noInt = 0x1FFDAAC;
MIi_DmaSetParams_noInt = 0x1FFDB0C;
MIi_DmaSetParams_wait = 0x1FFDB44;
SVC_CpuClear = 0x02000437;
SVC_WaitByLoop = 0x02000739;
_start = 0x02000800;
INITi_CpuClear32 = 0x2000920;
MIi_UncompressBackward = 0x2000934;
NitroMain = 0x2003000;
OS_Terminate = 0x20045EC;
NitroStartUp = 0x2004C24;
NNS_FndGetPrevListObject = 0x2055ADC;
NNS_FndGetNextListObject = 0x2055AF0;
NNS_FndRemoveListObject = 0x2055B08;
NNS_FndInsertListObject = 0x2055B70;
NNS_FndPrependListObject = 0x2055BE4;
NNS_FndAppendListObject = 0x2055C40;
NNS_FndInitList = 0x2055CCC;
NNS_FndGetSizeForMBlockExpHeap = 0x2055E18;
NNS_FndVisitAllocatedForExpHeap = 0x2055E20;
NNS_FndGetGroupIDForExpHeap = 0x2055E6C;
NNS_FndSetGroupIDForExpHeap = 0x2055E74;
NNS_FndGetAllocatableSizeForExpHeapEx = 0x2055E84;
NNS_FndGetTotalFreeSizeForExpHeap = 0x2055F08;
NNS_FndFreeToExpHeap = 0x2055F30;
NNS_FndResizeForMBlockExpHeap = 0x2055F6C;
NNS_FndAllocFromExpHeapEx = 0x20560E0;
NNS_FndDestroyExpHeap = 0x205611C;
NNS_FndCreateExpHeapEx = 0x2056128;
NNS_FndResizeForMBlockFrmHeap = 0x2056694;
NNS_FndAdjustFrmHeap = 0x2056714;
NNS_FndFreeByStateToFrmHeap = 0x2056748;
NNS_FndRecordStateForFrmHeap = 0x20567A4;
NNS_FndGetAllocatableSizeForFrmHeapEx = 0x20567F4;
NNS_FndFreeToFrmHeap = 0x2056830;
NNS_FndAllocFromFrmHeapEx = 0x2056868;
NNS_FndDestroyFrmHeap = 0x20568A8;
NNS_FndCreateFrmHeapEx = 0x20568B4;
NNS_FndOpenArchiveFileByIndex = 0x2056A5C;
NNS_FndGetArchiveFileByIndex = 0x2056A9C;
NNS_FndUnmountArchive = 0x2056AC4;
NNS_FndMountArchive = 0x2056AEC;
NNS_G2dFindBinaryBlock = 0x2057210;
NNS_G2dFontGetCharWidthsFromIndex = 0x2057268;
NNS_G2dFontFindGlyphIndex = 0x20572C4;
NNS_G2dFontInitAuto = 0x205731C;
NNS_G2dFontInitUTF16 = 0x205731C;
NNSi_G2dUnpackNFT = 0x2057430;
NNSi_G2dGetUnpackedFont = 0x2057520;
NNS_G3dBindMdlSet = 0x205768C;
NNS_G3dBindMdlPltt = 0x2057708;
NNS_G3dPlttLoad = 0x2057A14;
NNS_G3dPlttSetPlttKey = 0x2057A78;
NNS_G3dPlttGetRequiredSize = 0x2057A80;
NNS_G3dTexLoad = 0x2057A8C;
NNS_G3dTexSetTexKey = 0x2057B60;
NNS_G3dTex4x4GetRequiredSize = 0x2057B74;
NNS_G3dTexGetRequiredSize = 0x2057B80;
NNS_G3dGlbGetInvWV = 0x2057F10;
NNS_G3dGlbGetWV = 0x2057F50;
NNS_G3dGlbGetInvV = 0x2057FF0;
NNS_G3dGlbFlushP = 0x2058148;
NNS_G3dGlbInit = 0x2058184;
NNSi_G3dFuncSbc_BBY = 0x2059220;
NNSi_G3dFuncSbc_BB = 0x20595B0;
NNS_G3dDraw1Mat1Shp = 0x2059950;
NNS_G3dResDefaultSetup = 0x2059B68;
NNS_G3dInit = 0x2059DC0;
NNS_G3dGetCurrentMtx = 0x2059DF0;
NNS_G3dGetTex = 0x205A340;
NNS_G3dGetMdlSet = 0x205A380;
NNS_G3dGetResDictIdxByName = 0x205A390;
NNS_G3dGetResDataByName = 0x205A4E4;
NNSi_G3dAnmObjInitNsBca = 0x205B34C;
NNSi_G3dAnmCalcNsBma = 0x205B3E0;
NNSi_G3dAnmObjInitNsBma = 0x205B4AC;
NNSi_G3dAnmCalcNsBta = 0x205B7D8;
NNSi_G3dAnmObjInitNsBta = 0x205B824;
NNSi_G3dAnmCalcNsBtp = 0x205BBD4;
NNSi_G3dAnmObjInitNsBtp = 0x205BD90;
NNSi_G3dAnmCalcNsBva = 0x205BE40;
NNSi_G3dAnmObjInitNsBva = 0x205BE80;
NNSi_G3dSendTexSRT3dsMax = 0x205CB10;
NNS_SndMain = 0x205D1E8;
NNS_SndInit = 0x205D218;
NNSi_SndInitResourceMgr = 0x205D2B8;
NNS_SndFreeAlarm = 0x205D2E4;
NNS_SndAllocAlarm = 0x205D304;
NNS_SndUnlockCapture = 0x205D348;
NNS_SndLockCapture = 0x205D364;
NNS_SndUnlockChannel = 0x205D388;
NNS_SndLockChannel = 0x205D3B8;
NNSi_SndPlayerAllocHeap = 0x205D6E4;
NNSi_SndPlayerPause = 0x205D738;
NNSi_SndPlayerStopSeq = 0x205D774;
NNSi_SndPlayerStartSeq = 0x205D7C4;
NNSi_SndPlayerFreeSeqPlayer = 0x205D81C;
NNSi_SndPlayerAllocSeqPlayer = 0x205D828;
NNSi_SndPlayerMain = 0x205D8D4;
NNSi_SndPlayerInit = 0x205DA40;
NNS_SndPlayerWriteGlobalVariable = 0x205DAF4;
NNS_SndPlayerWriteVariable = 0x205DB0C;
NNS_SndPlayerReadVariable = 0x205DB3C;
NNS_SndPlayerSetSeqArcNo = 0x205DB80;
NNS_SndPlayerSetSeqNo = 0x205DBA8;
NNS_SndPlayerSetTempoRatio = 0x205DBC4;
NNS_SndPlayerSetTrackPan = 0x205DBEC;
NNS_SndPlayerSetTrackPitch = 0x205DC14;
NNS_SndPlayerSetTrackVolume = 0x205DC3C;
NNS_SndPlayerSetChannelPriority = 0x205DC9C;
NNS_SndPlayerMoveVolume = 0x205DCC4;
NNS_SndPlayerSetInitialVolume = 0x205DD00;
NNS_SndPlayerSetVolume = 0x205DD10;
NNS_SndPlayerCountPlayingSeqByPlayerNo = 0x205DD20;
NNS_SndHandleReleaseSeq = 0x205DD38;
NNS_SndHandleInit = 0x205DD50;
NNS_SndPlayerPauseAll = 0x205DD5C;
NNS_SndPlayerPause = 0x205DDB8;
NNS_SndPlayerStopSeqAll = 0x205DDC8;
NNS_SndPlayerStopSeqByPlayerNo = 0x205DE34;
NNS_SndPlayerStopSeq = 0x205DE98;
NNS_SndPlayerCreateHeap = 0x205DEA8;
NNS_SndPlayerSetAllocatableChannel = 0x205DF3C;
NNS_SndPlayerSetPlayableSeqCount = 0x205DF54;
NNS_SndStrmSetVolume = 0x205E020;
NNS_SndStrmStop = 0x205E08C;
NNS_SndStrmStart = 0x205E0B4;
NNSi_SndCaptureEndSleep = 0x205E29C;
NNSi_SndCaptureBeginSleep = 0x205E318;
NNSi_SndCaptureStop = 0x205E370;
NNSi_SndCaptureStart = 0x205E464;
NNSi_SndCaptureMain = 0x205E7BC;
NNSi_SndCaptureInit = 0x205E858;
NNS_SndCaptureCreateThread = 0x205E878;
NNS_SndCaptureStopEffect = 0x205E90C;
NNS_SndCaptureStartEffect = 0x205E948;
NNS_SndArcSetFileAddress = 0x205EA1C;
NNS_SndArcGetFileAddress = 0x205EA38;
NNS_SndArcReadFile = 0x205EA60;
NNS_SndArcGetFileSize = 0x205EAD8;
NNS_SndArcGetGroupInfo = 0x205EB00;
NNS_SndArcGetPlayerInfo = 0x205EB64;
NNS_SndArcGetWaveArcInfo = 0x205EBC8;
NNS_SndArcGetBankInfo = 0x205EC2C;
NNS_SndArcGetSeqArcInfo = 0x205EC90;
NNS_SndArcGetSeqInfo = 0x205ECF4;
NNS_SndArcGetCurrent = 0x205ED58;
NNS_SndArcSetCurrent = 0x205ED68;
NNS_SndArcInitOnMemory = 0x205ED80;
NNS_SndArcSetup = 0x205EE48;
NNS_SndArcInitWithResult = 0x205F034;
NNS_SndArcInit = 0x205F0C0;
NNS_SndHeapLoadState = 0x205F1F0;
NNS_SndHeapSaveState = 0x205F2D4;
NNS_SndHeapAlloc = 0x205F320;
NNS_SndHeapClear = 0x205F388;
NNS_SndHeapDestroy = 0x205F444;
NNS_SndHeapCreate = 0x205F45C;
NNSi_SndArcLoadFile = 0x205FAFC;
NNSi_SndArcLoadWaveArc = 0x205FB9C;
NNSi_SndArcLoadBank = 0x205FC38;
NNSi_SndArcLoadSeqArc = 0x205FD80;
NNSi_SndArcLoadSeq = 0x205FDE4;
NNSi_SndArcLoadGroup = 0x205FE80;
NNS_SndArcLoadSeq = 0x205FFA8;
NNS_SndArcLoadGroup = 0x205FFDC;
NNS_SndArcPlayerStartSeqArc = 0x20601BC;
NNS_SndArcPlayerStartSeq = 0x2060244;
NNS_SndArcPlayerSetup = 0x2060290;
NNSi_SndArcStrmMain = 0x206054C;
NNS_SndCaptureChangeOutputEffect = 0x2060AD8;
NNS_SndCaptureStopOutputEffect = 0x2060BBC;
NNS_SndCaptureStartOutputEffect = 0x2060BEC;
NNSi_SndFaderIsFinished = 0x2060C80;
NNSi_SndFaderUpdate = 0x2060C98;
NNSi_SndFaderGet = 0x2060CB0;
NNSi_SndFaderSet = 0x2060CE4;
NNSi_SndFaderInit = 0x2060D10;
GXx_SetMasterBrightness_ = 0x2060D30;
GXS_SetGraphicsMode = 0x2060D5C;
GX_SetGraphicsMode = 0x2060D78;
GX_DispOn = 0x2060DEC;
GX_VBlankIntr = 0x2060E38;
GX_HBlankIntr = 0x2060E68;
GX_GetSizeOfTexPltt = 0x2060E98;
GX_GetSizeOfX_ = 0x2060EB0;
GX_GetBankForSubOBJ = 0x2060F04;
GX_GetBankForSubBG = 0x2060F14;
GX_GetBankForTex = 0x2060F24;
GX_DisableBankForSubOBJExtPltt = 0x2060F34;
GX_DisableBankForSubBGExtPltt = 0x2060F5C;
GX_DisableBankForSubOBJ = 0x2060F84;
GX_DisableBankForSubBG = 0x2060F98;
GX_DisableBankForLCDC = 0x2060FAC;
GX_DisableBankForARM7 = 0x2060FC0;
GX_DisableBankForClearImage = 0x2060FD4;
GX_DisableBankForTexPltt = 0x2060FE8;
GX_DisableBankForTex = 0x2060FFC;
GX_DisableBankForOBJExtPltt = 0x2061010;
GX_DisableBankForBGExtPltt = 0x2061034;
GX_DisableBankForOBJ = 0x2061058;
GX_DisableBankForBG = 0x206106C;
GX_ResetBankForSubOBJExtPltt = 0x2061164;
GX_ResetBankForSubBGExtPltt = 0x206118C;
GX_ResetBankForSubOBJ = 0x20611B4;
GX_ResetBankForSubBG = 0x20611C8;
GX_ResetBankForClearImage = 0x20611DC;
GX_ResetBankForTexPltt = 0x20611F0;
GX_ResetBankForTex = 0x2061204;
GX_ResetBankForOBJExtPltt = 0x2061218;
GX_ResetBankForBGExtPltt = 0x206123C;
GX_ResetBankForOBJ = 0x2061260;
GX_ResetBankForBG = 0x2061274;
GX_SetBankForSubBGExtPltt = 0x20612C0;
GX_SetBankForSubOBJ = 0x206134C;
GX_SetBankForSubBG = 0x20613C8;
GX_SetBankForLCDC = 0x2061474;
GX_SetBankForTexPltt = 0x2061494;
GX_SetBankForTex = 0x2061588;
GX_SetBankForOBJExtPltt = 0x206178C;
GX_SetBankForBGExtPltt = 0x2061844;
GX_SetBankForOBJ = 0x2061958;
GX_SetBankForBG = 0x2061AC4;
GX_VRAMCNT_SetLCDC_ = 0x2061D7C;
G2S_GetBG3CharPtr = 0x2061E34;
G2_GetBG3CharPtr = 0x2061E84;
G2S_GetBG2CharPtr = 0x2061EE4;
G2_GetBG2CharPtr = 0x2061F2C;
G2S_GetBG1CharPtr = 0x2061F84;
G2_GetBG1CharPtr = 0x2061FA4;
G2S_GetBG0CharPtr = 0x2061FD8;
G2_GetBG0CharPtr = 0x2061FF8;
G2S_GetBG3ScrPtr = 0x206202C;
G2_GetBG3ScrPtr = 0x20620AC;
G2S_GetBG2ScrPtr = 0x2062138;
G2_GetBG2ScrPtr = 0x20621B8;
G2S_GetBG1ScrPtr = 0x2062244;
G2_GetBG1ScrPtr = 0x2062264;
G2S_GetBG0ScrPtr = 0x2062298;
G2_GetBG0ScrPtr = 0x20622B8;
G2x_SetBlendBrightness_ = 0x20622EC;
G2x_SetBlendAlpha_ = 0x2062310;
G2x_SetBGyAffine_ = 0x206232C;
G3_MultMtx33 = 0x20623E0;
G3_MultMtx43 = 0x20623FC;
G3_LoadMtx43 = 0x2062418;
GXi_NopClearFifo128_ = 0x2062434;
G3X_SetHOffset = 0x20624C8;
G3X_GetMtxStackLevelPJ = 0x20624D8;
G3X_GetMtxStackLevelPV = 0x2062504;
G3X_InitTable = 0x2062530;
G3X_SetClearColor = 0x20625D8;
G3X_SetToonTable = 0x2062608;
G3X_SetFogTable = 0x2062620;
G3X_GetVectorMtx = 0x2062634;
G3X_GetClipMtx = 0x206267C;
G3X_SetFog = 0x20626C4;
G3X_ResetMtxStack = 0x2062718;
G3X_InitMtxStack = 0x20627C4;
G3X_ClearFifo = 0x2062874;
G3X_Reset = 0x20628A8;
G3X_Init = 0x2062930;
G3_RotZ = 0x2062A8C;
G3i_LookAt_ = 0x2062AC8;
G3i_OrthoW_ = 0x2062C60;
G3i_PerspectiveW_ = 0x2062F5C;
GXS_EndLoadBGExtPltt = 0x206314C;
GXS_LoadBGExtPltt = 0x2063198;
GX_EndLoadOBJExtPltt = 0x2063230;
GX_LoadOBJExtPltt = 0x2063288;
GX_BeginLoadOBJExtPltt = 0x20632FC;
GX_EndLoadBGExtPltt = 0x206336C;
GX_LoadBGExtPltt = 0x20633D0;
GX_BeginLoadBGExtPltt = 0x2063450;
GX_LoadBG1Char = 0x2063554;
GXS_LoadBG0Char = 0x20635BC;
GXS_LoadBG3Scr = 0x2063624;
GX_LoadBG3Scr = 0x206368C;
GXS_LoadBG2Scr = 0x20636F4;
GX_LoadBG2Scr = 0x206375C;
GX_LoadBG1Scr = 0x20637C4;
GXS_LoadBG0Scr = 0x206382C;
GXS_LoadOBJ = 0x2063894;
GXS_LoadOAM = 0x20638F4;
GX_LoadOAM = 0x206395C;
GXS_LoadOBJPltt = 0x20639B8;
GX_LoadOBJPltt = 0x2063A20;
GXS_LoadBGPltt = 0x2063A88;
GX_LoadBGPltt = 0x2063AF0;
GX_EndLoadTexPltt = 0x2063B4C;
GX_LoadTexPltt = 0x2063BA4;
GX_BeginLoadTexPltt = 0x2063C18;
GX_EndLoadTex = 0x2063C60;
GX_LoadTex = 0x2063CD0;
GX_BeginLoadTex = 0x2063E34;
GX_SendFifo48B = 0x2063EB4;
OS_GetIrqStackStatus = 0x2063ED8;
OS_SetIrqStackChecker = 0x2063F54;
OSi_EnterTimerCallback = 0x2063F88;
OS_InitIrqTable = 0x2063FD4;
OS_UnLockCartridge = 0x2063FEC;
OS_GetLockID = 0x2063FF8;
OS_ReleaseLockID = 0x2064050;
OS_ReadOwnerOfLockWord = 0x2064080;
OSi_FreeCardBus = 0x2064088;
OSi_AllocateCardBus = 0x20640A0;
OS_UnlockCard = 0x20640B8;
OS_TryLockCard = 0x20640D4;
OSi_FreeCartridgeBus = 0x20640F0;
OSi_AllocateCartridgeBus = 0x2064108;
OS_TryLockCartridge = 0x2064120;
OS_UnlockCartridge = 0x2064140;
OSi_DoTryLockByWord = 0x2064160;
OS_UnlockByWord = 0x20641E0;
OSi_DoUnlockByWord = 0x20641F0;
OS_TryLockByWord = 0x2064280;
OS_InitLock = 0x20642E4;
OS_VSNPrintf = 0x20643D4;
OS_SNPrintf = 0x20643D4;
OS_VSPrintf = 0x2064C9C;
OS_SPrintf = 0x2064CB4;
OS_GetThreadParameter = 0x2064DD8;
OS_SetThreadParameter = 0x2064DE0;
OS_SetThreadDestructor = 0x2064DE8;
OS_EnableScheduler = 0x2064DF0;
OS_DisableScheduler = 0x2064E28;
OS_SetSwitchThreadCallback = 0x2064E60;
OS_GetThreadPriority = 0x2064E94;
OS_SetThreadPriority = 0x2064E9C;
OS_SetThreadStackWarningOffset = 0x2064F50;
OS_GetStackStatus = 0x2064F6C;
OS_WakeupThreadDirect = 0x2064FCC;
OS_SleepThread = 0x2065000;
OS_IsThreadTerminated = 0x2065054;
OS_JoinThread = 0x2065068;
OSi_ExitThread_Destroy = 0x20650A4;
OSi_ExitThread = 0x2065104;
OSi_ExitThread_ArgSpecified = 0x2065148;
OS_ExitThread = 0x20651B8;
OS_CreateThread = 0x20651E4;
OS_InitThread = 0x20652EC;
OSi_RemoveThreadFromList = 0x2065448;
OSi_InsertThreadToList = 0x2065490;
OSi_RemoveMutexLinkFromQueue = 0x20654F8;
OSi_RemoveSpecifiedLinkFromQueue = 0x2065528;
OSi_InsertLinkToQueue = 0x206557C;
OSi_GetUnusedThreadId = 0x20655F4;
OS_InitContext = 0x206560C;
OSi_IsRunOnDebugger = 0x2065670;
OSi_GetDeviceType = 0x20656A4;
OS_GetConsoleType = 0x2065778;
OS_JamMessage = 0x20657F0;
OS_ReceiveMessage = 0x20658A4;
OS_SendMessage = 0x2065950;
OS_InitMessageQueue = 0x20659F8;
OSi_DequeueItem = 0x2065A28;
OSi_EnqueueTail = 0x2065A4C;
OS_TryLockMutex = 0x2065A70;
OSi_UnlockAllMutex = 0x2065AE4;
OS_UnlockMutex = 0x2065B2C;
OS_LockMutex = 0x2065B9C;
OS_InitMutex = 0x2065C28;
DC_InvalidateAll = 0x2065C44;
DC_StoreAll = 0x2065C50;
DC_FlushAll = 0x2065C7C;
DC_InvalidateRange = 0x2065CB0;
DC_StoreRange = 0x2065CCC;
DC_FlushRange = 0x2065CE8;
DC_WaitWriteBufferEmpty = 0x2065D0C;
IC_InvalidateAll = 0x2065D18;
IC_InvalidateRange = 0x2065D24;
OS_Init = 0x2065D40;
OS_AllocFromArenaLo = 0x2065D90;
OS_SetArenaLo = 0x2065E18;
OS_SetArenaHi = 0x2065E2C;
OS_GetInitArenaLo = 0x2065E40;
OS_GetInitArenaHi = 0x2065F2C;
OS_GetArenaLo = 0x206605C;
OS_GetArenaHi = 0x2066070;
OS_InitArenaEx = 0x2066084;
OS_InitArena = 0x2066104;
OS_GetDTCMAddress = 0x206621C;
OS_EnableProtectionUnit = 0x2066230;
OS_DisableProtectionUnit = 0x2066240;
OS_SetProtectionRegion1 = 0x2066250;
OS_SetProtectionRegion2 = 0x2066258;
OSi_ExceptionHandler = 0x2066260;
OSi_GetAndDisplayContext = 0x20662D4;
OSi_SetExContext = 0x20662E8;
OSi_DisplayExContext = 0x2066378;
OS_SetUserExceptionHandler = 0x20663E4;
OS_InitException = 0x2066400;
OSi_SetTimerReserved = 0x2066490;
OS_GetTickLo = 0x20664AC;
OSi_CountUpTick = 0x20664BC;
OS_InitTick = 0x2066544;
OS_InitAlarm = 0x20665E0;
OS_InitVAlarm = 0x2066638;
OS_ResetSystem = 0x20666A8;
OSi_SendToPxi = 0x2066728;
OSi_CommonCallback = 0x2066758;
OS_InitReset = 0x206679C;
OS_GetOwnerInfo = 0x2066804;
OS_GetMacAddress = 0x2066880;
OsCountZeroBits = 0x206689C;
OSi_UnlockVram = 0x20668A4;
OSi_InitVramExclusive = 0x206692C;
OS_GetLowEntropyData = 0x2066960;
MI_SetWramBank = 0x2066A50;
MI_DmaCopy32Async = 0x2066A60;
MI_DmaFill32Async = 0x2066B08;
MI_DmaCopy16 = 0x2066BE0;
MI_DmaCopy32 = 0x2066C58;
MI_DmaFill32 = 0x2066CD4;
MIi_DMAFastCallback = 0x2066D64;
MI_SendGXCommandAsyncFast = 0x2066DA4;
MIi_CpuClear16 = 0x2066E64;
MIi_CpuCopy16 = 0x2066E7C;
MIi_CpuClear32 = 0x2066E98;
MIi_CpuCopy32 = 0x2066EAC;
MIi_CpuSend32 = 0x2066EC4;
MIi_CpuClearFast = 0x2066EDC;
MIi_CpuCopyFast = 0x2066F28;
MI_Copy32B = 0x2066F60;
MI_Copy36B = 0x2066F7C;
MI_Copy48B = 0x2066F98;
MI_Copy64B = 0x2066FBC;
MI_CpuFill8 = 0x2066FE8;
MI_CpuCopy8 = 0x206707C;
MI_Zero36B = 0x20671AC;
MI_SwapWord = 0x20671BC;
MI_UncompressLZ8 = 0x20671C4;
MI_UncompressLZ16 = 0x2067258;
MIi_CardDmaCopy32 = 0x2067330;
MI_ReadUncompLZ8 = 0x20673BC;
MI_InitUncompContextLZ = 0x20674BC;
MI_Init = 0x20674EC;
SNDi_SetSurroundDecay = 0x2067568;
SNDi_SetTrackParam = 0x2067594;
SNDi_SetPlayerParam = 0x20675C8;
SND_SetOutputSelector = 0x20675FC;
SND_InvalidateWaveData = 0x2067630;
SND_InvalidateBankData = 0x206765C;
SND_InvalidateSeqData = 0x2067688;
SND_SetupChannelPcm = 0x20676B4;
SND_SetChannelVolume = 0x206770C;
SND_UnlockChannel = 0x2067740;
SND_LockChannel = 0x206776C;
SND_SetTrackPan = 0x2067798;
SND_SetupAlarm = 0x20677CC;
SND_SetupCapture = 0x2067810;
SND_StopTimer = 0x206785C;
SND_StartTimer = 0x20678CC;
SND_SetTrackAllocatableChannel = 0x2067900;
SND_SetTrackPan_0 = 0x2067934;
SND_SetTrackPitch = 0x206795C;
SND_SetTrackVolume = 0x2067984;
SND_SetPlayerGlobalVariable = 0x20679AC;
SND_SetPlayerLocalVariable = 0x20679D8;
SND_SetPlayerChannelPriority = 0x2067A0C;
SND_SetPlayerVolume = 0x2067A24;
SND_SetPlayerTempoRatio_0 = 0x2067A3C;
SND_SetPlayerTempoRatio = 0x2067A54;
SND_StartPreparedSeq = 0x2067A80;
SND_PrepareSeq = 0x2067AAC;
SND_StopSeq = 0x2067AE0;
SND_Init = 0x2067B34;
SND_CountWaitingCommand = 0x2067CC0;
SND_CountReservedCommand = 0x2067CE0;
SND_CountFreeCommand = 0x2067D20;
SND_IsFinishedCommandTag = 0x2067D60;
SND_GetCurrentCommandTag = 0x2067DB4;
SND_WaitForCommandProc = 0x2067DF4;
SND_FlushCommand = 0x2067E84;
SND_PushCommand = 0x2068044;
SND_AllocCommand = 0x206808C;
SND_RecvCommandReply = 0x2068128;
SND_CommandInit = 0x206825C;
SNDi_SetAlarmHandler = 0x2068374;
SNDi_IncAlarmId = 0x20683A4;
SND_AlarmInit = 0x20683C4;
SNDi_InitSharedWork = 0x20683F4;
SNDi_GetFinishedCommandTag = 0x2068474;
SND_GetPlayerLocalVariable = 0x20684A8;
SND_GetPlayerStatus = 0x20684FC;
SND_CalcChannelVolume = 0x2068534;
SND_GetWaveDataAddress = 0x20685A8;
SND_SetWaveDataAddress = 0x20685F0;
SND_GetWaveDataCount = 0x2068628;
SND_GetNextInstData = 0x2068630;
SND_GetFirstInstDataPos = 0x2068808;
SND_DestroyWaveArc = 0x2068828;
SND_DestroyBank = 0x2068874;
SND_AssignWaveArc = 0x2068914;
PXI_SendWordByFifo = 0x20689FC;
PXI_IsCallbackReady = 0x2068AB0;
PXI_SetFifoRecvCallback = 0x2068AD8;
PXI_InitFifo = 0x2068B44;
FSi_TranslateCommand = 0x2068C50;
FSi_ReleaseCommand = 0x2068DCC;
FSi_OpenFileDirectCommand = 0x2068E38;
FSi_OpenFileFastCommand = 0x2068E60;
FSi_GetPathCommand = 0x2068EDC;
FSi_FindPathCommand = 0x206929C;
FSi_ReadDirCommand = 0x20694B8;
FSi_SeekDirCommand = 0x20695C8;
FSi_WriteFileCommand = 0x2069660;
FSi_ReadFileCommand = 0x2069698;
FSi_SeekDirDirect = 0x20696D0;
FSi_ReadTable = 0x2069704;
FSi_StrNICmp = 0x20697A8;
FS_NotifyArchiveAsyncEnd = 0x206980C;
FS_SetArchiveProc = 0x206988C;
FS_ResumeArchive = 0x20698AC;
FS_SuspendArchive = 0x2069928;
FS_UnloadArchive = 0x20699B8;
FS_LoadArchive = 0x2069A80;
FS_ReleaseArchiveName = 0x2069AF8;
FS_RegisterArchiveName = 0x2069B90;
FS_FindArchive = 0x2069C50;
FS_InitArchive = 0x2069CA0;
FSi_SendCommand = 0x2069CD8;
FSi_ExecuteSyncCommand = 0x2069E94;
FSi_ExecuteAsyncCommand = 0x2069EDC;
FSi_NextCommand = 0x2069F80;
FSi_WriteMemCallback = 0x206A178;
FSi_ReadMemCallback = 0x206A1A4;
FSi_GetPackedName = 0x206A1CC;
FS_ChangeDir = 0x206A230;
FS_SeekFile = 0x206A284;
FS_ReadFile = 0x206A2F0;
FS_ReadFileAsync = 0x206A300;
FS_WaitAsync = 0x206A310;
FS_CloseFile = 0x206A3E0;
FS_OpenFile = 0x206A428;
FS_OpenFileFast = 0x206A478;
FS_OpenFileDirect = 0x206A4F4;
FS_ConvertPathToFileID = 0x206A54C;
FSi_ReadFileCore = 0x206A590;
FSi_FindPath = 0x206A618;
FS_InitFile = 0x206A778;
FS_Init = 0x206A7A8;
FS_CreateFileFromRom = 0x206A7E4;
FSi_InitRom = 0x206A820;
FSi_EmptyArchiveProc_0 = 0x206A9C0;
FSi_RomArchiveProc = 0x206A9D0;
FSi_WriteRomCallback = 0x206AA60;
FSi_ReadRomCallback = 0x206AA68;
FSi_OnRomReadDone = 0x206AAB4;
FS_AttachOverlayTable = 0x206AAC4;
FS_UnloadOverlay = 0x206AB48;
FS_LoadOverlay = 0x206AB9C;
FS_UnloadOverlayImage = 0x206ABF8;
FS_EndOverlay = 0x206AC14;
FS_StartOverlay = 0x206AD18;
FSi_CompareDigest = 0x206AE18;
FS_LoadOverlayImage = 0x206AEBC;
FS_LoadOverlayInfo = 0x206AF5C;
FSi_LoadOverlayInfoCore = 0x206B070;
FS_GetOverlayFileID = 0x206B180;
FS_ClearOverlayImage = 0x206B1A8;
FSi_GetOverlayBinarySize = 0x206B1EC;
DGT_Hash2CalcHmac = 0x206B208;
DGTi_Hash2ProcessMessageBlock = 0x206B394;
DGT_Hash2GetDigest = 0x206B410;
DGT_Hash2SetSource = 0x206B60C;
DGT_Hash2Reset = 0x206B768;
DGT_SetOverlayTableMode = 0x206B7B8;
DGT_DoSomethingWtf = 0x206B80C;
TP_CheckError = 0x206BA8C;
TP_WaitBusy = 0x206BAA0;
TP_GetCalibratedPoint = 0x206BAB8;
TP_CalcCalibrateParam = 0x206BBE8;
TP_GetLatestIndexInAuto = 0x206BE58;
TP_RequestAutoSamplingStartAsync = 0x206BE68;
TP_SetCalibrateParam = 0x206BF7C;
TP_GetUserInfo = 0x206C0C4;
TP_Init = 0x206C170;
TPi_TpCallback = 0x206C200;
MicWaitBusy = 0x206C4C0;
MicGetResultCallback = 0x206C4D8;
MicStopAutoSampling = 0x206C4E8;
MicStartAutoSampling = 0x206C51C;
MicCommonCallback = 0x206C648;
OS_IsThreadAvailable_14 = 0x206C788;
MIC_StopAutoSampling = 0x206C798;
MIC_StopAutoSamplingAsync = 0x206C7DC;
MIC_StartAutoSampling = 0x206C84C;
MIC_StartAutoSamplingAsync = 0x206C890;
MIC_Init = 0x206CA00;
PM_AppendPostSleepCallback = 0x206CABC;
PM_PrependPreSleepCallback = 0x206CAD4;
PMi_ExecuteList = 0x206CAEC;
PMi_DeleteList = 0x206CB1C;
PMi_AppendList = 0x206CB68;
PMi_PrependList = 0x206CBB0;
PM_GetLCDPower = 0x206CBC4;
PM_SetLCDPower = 0x206CBE0;
PMi_SetLCDPower = 0x206CC00;
PM_GoSleepMode = 0x206CCF0;
PMi_SendPxiData = 0x206CF30;
PM_GetBackLight = 0x206CF60;
PM_SetAmpGain = 0x206CFD8;
PM_SetAmp = 0x206CFF0;
PM_ForceToPowerOff = 0x206D008;
PM_ForceToPowerOffAsync = 0x206D044;
PM_SetBackLight = 0x206D05C;
PM_SetBackLightAsync = 0x206D098;
PMi_SetLED = 0x206D128;
PMi_SetLEDAsync = 0x206D164;
PMi_WriteRegister = 0x206D1CC;
PMi_WriteRegisterAsync = 0x206D208;
PMi_ReadRegister = 0x206D288;
PMi_ReadRegisterAsync = 0x206D2C4;
PM_SendUtilityCommandAsync = 0x206D33C;
PMi_SendSleepStart = 0x206D3B0;
PMi_CommonCallback = 0x206D468;
PM_Init = 0x206D554;
PMi_CallCallbackAndUnlock = 0x206D618;
PMi_DummyCallback_2 = 0x206D66C;
PMi_WaitBusy = 0x206D674;
PMi_Lock = 0x206D68C;
RTC_GetTime = 0x206DD08;
RTC_GetTimeAsync = 0x206DD4C;
RTC_Init = 0x206DDC8;
RTCi_WriteRawStatus2Async = 0x206DE84;
RTCi_ReadRawTimeAsync = 0x206DE94;
RTC_GetDayOfWeek = 0x206DEA4;
CARD_UnlockBackup = 0x206DF7C;
CARD_LockBackup = 0x206DF8C;
CARD_UnlockRom = 0x206DF9C;
CARD_LockRom = 0x206DFBC;
CARDi_WaitAsync = 0x206DFDC;
CARD_CheckEnabled = 0x206E048;
CARDi_InitCommon = 0x206E084;
CARDi_UnlockResource = 0x206E184;
CARDi_LockResource = 0x206E228;
CARDi_SetTask = 0x206E2C4;
CARDi_IdentifyBackupCore = 0x206E30C;
CARD_IdentifyBackup = 0x206E4FC;
CARD_GetBackupTotalSize = 0x206E644;
CARDi_RequestStreamCommand = 0x206E658;
CARDi_RequestStreamCommandCore = 0x206E74C;
CARDi_ReadRomCore = 0x206E908;
CARDi_WaitAsync_1 = 0x206E914;
CARD_Init = 0x206E920;
CARDi_ReadRom = 0x206E9A4;
CARDi_ReadRomSyncCore = 0x206EACC;
CARDi_ReadRomIDCore = 0x206EB78;
CARDi_ReadCard = 0x206EBDC;
CARDi_TryReadCardDma = 0x206ECDC;
CARDi_OnReadCard = 0x206EE38;
CARDi_SetCardDma = 0x206EF18;
CARDi_SetRomOp = 0x206EF70;
CARDi_ReadFromCache = 0x206F010;
CARDi_Request = 0x206F0A8;
CARDi_TaskThread = 0x206F1FC;
CARDi_OnFifoRecv = 0x206F258;
CARDi_SendtoPxi = 0x206F2A8;
CARDi_CheckPulledOutCore = 0x206F30C;
CARD_TerminateForPulledOut = 0x206F37C;
CARD_IsPulledOut = 0x206F3BC;
CARD_SetPulledOutCallback = 0x206F3CC;
CARDi_PulledOutCallback = 0x206F3DC;
CARD_InitPulledOutCallback = 0x206F448;
WMi_GetMPReadyAIDs = 0x206F480;
WM_GetConnectedAIDs = 0x206F4D4;
WM_GetAID = 0x206F508;
WMi_CheckStateEx = 0x206F93C;
WMi_CheckIdle = 0x206F9E4;
WMi_CheckInitialized = 0x206FA40;
WMi_GetSystemWork = 0x206FA5C;
WMi_SendCommandDirect = 0x206FA6C;
WMi_SendCommand = 0x206FAE4;
WMi_SetCallbackTable = 0x206FC10;
WM_Finish = 0x206FC28;
WM_Init = 0x206FE90;
WM_GetNextTgid = 0x206FEC4;
WM_GetDispersionScanPeriod = 0x206FF3C;
WM_GetDispersionBeaconPeriod = 0x206FFE0;
WM_GetLinkLevel = 0x2070084;
WM_GetAllowedChannel = 0x207012C;
WM_ReadMPData = 0x2070158;
WM_GetMPReceiveBufferSize = 0x207025C;
WM_GetMPSendBufferSize = 0x2070344;
WM_ReadStatus = 0x20703BC;
WM_SetPortCallback = 0x2070424;
WM_SetIndCallback = 0x2070504;
WM_Disconnect = 0x2070550;
WM_StartConnectEx = 0x2070658;
WM_EndScan = 0x2070734;
WM_StartScan = 0x207077C;
WM_EndParent = 0x207087C;
WM_StartParent = 0x20708C4;
WMi_StartParentEx = 0x20708D4;
WM_SetParentParameter = 0x2070994;
WM_End = 0x2070A9C;
WM_Reset = 0x2070AE4;
WM_Initialize = 0x2070B24;
WM_Disable = 0x2070B8C;
WM_Enable = 0x2070BD4;
WM_EndMP = 0x2070C40;
WM_SetMPDataToPortEx = 0x2070CCC;
WM_SetMPFrequency = 0x2070E48;
WM_SetMPParameter = 0x2070E90;
WM_StartMP = 0x2070F0C;
WM_StartMPEx = 0x2070F78;
WMi_StartMP = 0x207101C;
WM_GetSharedDataAddress = 0x20711DC;
WM_StepDataSharing = 0x2071880;
WM_EndDataSharing = 0x2071C00;
WM_StartDataSharing = 0x2071C74;
WM_EndDataSharing_0 = 0x2071EF0;
WM_StartKeySharing = 0x2071EFC;
WM_SetEntry = 0x2071F28;
WM_MeasureChannel = 0x2071F88;
WM_SetLifeTime = 0x2072008;
WM_SetBeaconIndication = 0x2072074;
WM_SetGameInfo = 0x20720E4;
WM_SetWEPKey = 0x20721AC;
WBTi_next_user_request = 0x2072230;
WBTi_current_user_request = 0x2072498;
WBTi_token_check_req_get_blockinfo2 = 0x20725FC;
WBTi_token_check_req_get_blockinfo = 0x207269C;
WBTi_token_check_req_get_block = 0x2072740;
WBTi_token_check_req_user_data = 0x2072890;
WBTi_token_check_req_get_block_done = 0x20728F4;
WBTi_token_check_req_sync = 0x207295C;
WBTi_get_token_from_recv_buffer = 0x20729FC;
WBTi_MakeResUserDataCommand = 0x2073598;
WBTi_MakeReqUserDataCommand = 0x2073604;
WBTi_MakeResBlockDoneCommand = 0x207369C;
WBTi_MakeReqBlockDoneCommand = 0x207371C;
WBTi_MakeResBlockInfoCommand = 0x207379C;
WBTi_MakeReqBlockInfoCommand = 0x2073864;
WBTi_MakeResBlockCommand = 0x20738F8;
WBTi_MakeReqBlockCommand = 0x20739C0;
WBTi_MakeResSyncCommand = 0x2073A54;
WBTi_MakeReqSyncCommand = 0x2073AFC;
WBTi_MakeReqWaitCommand = 0x2073B90;
WBT_MpChildRecvHook = 0x2073BF8;
WBT_MpChildSendHook = 0x2073C48;
WBT_MpParentRecvHook = 0x2073C80;
WBT_MpParentSendHook = 0x2073CE0;
WBT_End = 0x2073D18;
WBT_InitChild = 0x2073DDC;
WBT_InitParent = 0x2073EA4;
WBT_CancelCurrentCommand = 0x20742D4;
WBT_PutUserData = 0x207439C;
WBT_GetBlock = 0x20743F8;
WBT_GetBlockInfo = 0x2074450;
WBT_RequestSync = 0x2074498;
WBT_UnregisterBlock = 0x20744C4;
WBT_RegisterBlock = 0x2074588;
WBT_NumOfRegisteredBlock = 0x2074650;
WBT_SetPacketSize = 0x2074680;
WBT_CalcPacketbitmapSize = 0x20746D8;
WBT_AidbitmapToAid = 0x207472C;
WBT_GetOwnAid = 0x2074754;
WBT_SetOwnAid = 0x2074764;
WBTi_get_block_info_list = 0x2074774;
WBTi_set_block_info_list_header = 0x20747B0;
WBTi_get_block_info_list_header = 0x20747C0;
WBTi_SetUserCommand = 0x20747D0;
WBTi_GetUserCommand = 0x2074868;
WBTi_GetCommandParameter = 0x2074874;
WBTi_set_my_data_packet_size = 0x2074880;
WBTi_set_peer_data_packet_size = 0x2074890;
WBTi_get_my_data_packet_size = 0x20748A0;
WBTi_get_peer_data_packet_size = 0x20748B0;
WBTi_reset_my_user_command_counter = 0x20748C0;
WBTi_increment_my_user_command_counter = 0x20748D4;
WBTi_get_my_user_command_counter_1 = 0x20748FC;
MBi_CommCallParentError = 0x207490C;
MBi_calc_nextsendblock = 0x207494C;
MBi_calc_sendblock = 0x207495C;
MBi_CommParentSendData = 0x20749E0;
MBi_CommParentSendBlock = 0x2074B6C;
MBi_ReloadCache = 0x2074E30;
MBi_CommParentSendDLFileInfo = 0x2074ECC;
MBi_CommParentSendMsg = 0x207507C;
MBi_CommParentRecvData = 0x20750C0;
MBi_CommParentRecvDataPerChild = 0x2075178;
MBi_CommParentCallback = 0x2075688;
MBi_CommChangeParentStateCallbackOnly = 0x2075B50;
MBi_CommChangeParentState = 0x2075B8C;
MB_CommResponseRequest = 0x2075BDC;
MB_CommIsBootable = 0x2075CD8;
MB_CommGetChildUser = 0x2075D34;
MB_CommSetParentStateCallback = 0x2075DD0;
MBi_IsAbleToRecv = 0x2075F10;
MBi_get_blockinfo = 0x2075FC0;
MBi_MakeBlockInfoTable = 0x2076094;
MBi_SetSegmentInfo = 0x2076170;
MBi_MakeDownloadFileInfo = 0x2076328;
MB_RegisterFile = 0x20763AC;
MBi_ReadSegmentHeader = 0x2076684;
MB_ReadSegment = 0x2076718;
MB_GetSegmentLength = 0x2076B84;
MBi_calc_cksum = 0x2076C08;
MBi_BlockHeaderEnd = 0x2076C50;
MB_GetGameInfoRecvList = 0x2076C8C;
MB_DeleteRecvGameInfoWithoutBssdesc = 0x2076CBC;
MB_DeleteRecvGameInfo = 0x2076D50;
MBi_UnlockScanTarget = 0x2076DA8;
MBi_LockScanTarget = 0x2076E18;
MBi_RecvVolatBeacon = 0x2076EA0;
MBi_RecvFixedBeacon = 0x20770CC;
MBi_InvalidateGameInfoBssID = 0x20771B4;
MBi_CheckSeqNoVolat = 0x2077274;
MBi_CheckSeqNoFixed = 0x20772C4;
MBi_CheckTGID = 0x2077340;
MBi_AnalyzeBeacon = 0x20773B0;
MB_CountGameInfoLifetime = 0x20774E4;
MBi_CheckCompleteGameInfoFlagments = 0x2077670;
MBi_GetStoreElement = 0x2077768;
MBi_SetSSIDToBssDesc = 0x2077918;
MBi_CheckMBParent = 0x2077944;
MB_RecvGameInfoBeacon = 0x207796C;
MB_InitRecvGameInfoStatus = 0x2077A34;
MBi_SendVolatBeacon = 0x2077A74;
MBi_InitSendVolatBeacon = 0x2077D18;
MBi_SendFixedBeacon = 0x2077D48;
MBi_InitSendFixedBeacon = 0x2077EC0;
MBi_ReadyBeaconSendStatus = 0x2077F0C;
MB_SendGameInfoBeacon = 0x2077FB8;
MBi_ClearSendStatus = 0x2078060;
MB_InitSendGameInfoStatus = 0x2078084;
MB_AddGameInfo = 0x20780B8;
MB_UpdateGameInfoMember = 0x2078124;
MBi_ReadIconInfo = 0x20781A8;
MBi_MakeGameInfo = 0x207825C;
MBi_SetScanLockFunc = 0x2078358;
MBi_SetBeaconRecvStatusBuffer = 0x2078374;
MBi_CheckWmErrcode = 0x2078384;
MBi_IsStarted = 0x20783DC;
MBi_GetAttribute = 0x20783FC;
MBi_GetGgid = 0x2078470;
MBi_SendMP = 0x2078484;
MBi_SetMPData = 0x2078588;
MBi_SetMaxScanTime = 0x20785D8;
MB_DisconnectChild = 0x20785E8;
MB_End = 0x2078794;
MBi_CommEnd = 0x20787D4;
MBi_CallReset_0 = 0x207885C;
MBi_CallReset = 0x2078868;
MB_StartParent = 0x20788A4;
MBi_StartCommon = 0x2078ADC;
MB_SetParentCommParam = 0x2078BDC;
MBi_IsCommSizeValid = 0x2078C80;
MB_Init = 0x2078CF0;
MBi_GetBeaconPeriodDispersion = 0x2078ED8;
MBi_ChildCallback = 0x2078F50;
MBi_ChildPortCallback = 0x20797EC;
MBi_ParentCallback = 0x20798C4;
MBi_OnInitializeDone = 0x207A13C;
MBi_IsSendEnabled = 0x207A1B0;
MBi_ReadFromCache = 0x207A294;
MBi_AttachCacheBuffer = 0x207A338;
MBi_InitCache = 0x207A3AC;
MBi_EndTaskThread = 0x207A3C0;
MBi_SetTask = 0x207A414;
MBi_IsTaskBusy = 0x207A5A4;
MBi_InitTaskInfo = 0x207A5BC;
MBi_IsTaskAvailable = 0x207A5D0;
MBi_InitTaskThread = 0x207A5EC;
MBi_TaskThread = 0x207A674;
MB_FakeGetParentBssDesc = 0x207A78C;
MB_FakeGetParentGameInfo = 0x207A7F8;
MBFi_CommChildSendData = 0x207A860;
MBFi_CommChildRecvData = 0x207AA2C;
MBFi_WMCallback = 0x207ABFC;
MB_FakeEntryToParent = 0x207AF04;
MBFi_StateOutEndScan = 0x207AF9C;
MBFi_StateInEndScan = 0x207B018;
MB_FakeEndScan = 0x207B058;
MBFi_CommBeaconRecvCallback = 0x207B124;
MBFi_ScanUnlock = 0x207B174;
MBFi_ScanLock = 0x207B190;
MBFi_ScanErrorCallback = 0x207B1EC;
MBFi_ScanCallback = 0x207B238;
MBFi_StateOutStartScanParent = 0x207B298;
MBFi_StateInStartScan = 0x207B37C;
MB_FakeStartScanParent = 0x207B474;
MBFi_CommChangeChildState = 0x207B4E8;
MB_FakeSetCStateCallback = 0x207B548;
MB_FakeGetWorkSize = 0x207B570;
MBFi_EndComplete = 0x207B57C;
MB_FakeEnd = 0x207B5C4;
MB_FakeInit = 0x207B6E4;
MBi_WMClearCallback = 0x207B798;
MBi_MPSendToParent = 0x207B868;
MBi_WMStateOutReset = 0x207BA28;
MBi_WMReset = 0x207BAB8;
MBi_WMStateOutDisconnect = 0x207BB24;
MBi_WMStateInDisconnect = 0x207BBB8;
MBi_WMStateOutEndMP = 0x207BC34;
MBi_WMDisconnect = 0x207BCC0;
MBi_ChildStartMP = 0x207BEB0;
MBi_WMStateOutStartConnect = 0x207BFD4;
MBi_WMStartConnect = 0x207C0D4;
MBi_WMSetCallback = 0x207C1BC;
MBi_WMSetBuffer = 0x207C1E4;
MBi_SetRecvBufferFromParent = 0x207C234;
MBi_SendRequestDataPiece = 0x207C2B4;
MBi_MakeChildSendBuffer = 0x207C318;
MBi_ReceiveRequestDataPiece = 0x207C474;
MBi_SetRecvBufferFromChild = 0x207C524;
MBi_MakeParentSendBuffer = 0x207C660;
MBi_ClearParentPieceBuffer = 0x207C6E8;
MBi_SetParentPieceBuffer = 0x207C734;
MBi_SetChildMPMaxSize = 0x207C754;
CTRDGi_SendtoPxi = 0x207C790;
CTRDGi_UnlockByProcessor = 0x207C7F4;
CTRDGi_LockByProcessor = 0x207C81C;
CTRDGi_RestoreAccessCycle = 0x207C89C;
CTRDGi_ChangeLatestAccessCycle = 0x207C8D0;
CTRDG_IsExisting = 0x207C918;
CTRDGi_InitCommon = 0x207CA34;
CTRDG_TerminateForPulledOut = 0x207CA74;
CTRDGi_PulledOutCallback = 0x207CA94;
CTRDGi_CallbackForInitModuleInfo = 0x207CAF4;
CTRDGi_InitModuleInfo = 0x207CB30;
CTRDG_Init = 0x207CCFC;
MATH_CountPopulation = 0x207CD98;
MATH_CalcSHA1 = 0x207CDDC;
CHT_IsPictochatParent = 0x207CE20;
__call_static_initializers = 0x207FCA4;
NNS_G3dGeBuffer = 0x2092BB0;
NNS_G3dFlagGXDmaAsync = 0x2092BB4;
NNS_SoundCaptureThread = 0x2093684;
OSi_LauncherThread = 0x2094384;
CARDi_IsPulledOutFlag = 0x2096B40;
CARD_UserCallback = 0x2096B44;
ENV_SetResourceSet = 0x238A2B4;
SND_GetWaveDataAddress_0 = 0x238A6B8;
CARDi_WaitPrevCommand = 0x238BB24;
PMi_SendPxiData_0 = 0x238DA30;
OS_IsThreadAvailable_20 = 0x238DF40;
CTRDGi_UnlockByProcessor_0 = 0x238EDC0;
CTRDGi_ChangeLatestAccessCycle_0 = 0x238EE8C;
WFSi_EndTaskThread = 0x02047CAC;
WFSi_CreateTaskThread = 0x02047CF0;
WFSi_TaskThread = 0x02047D48;
WFSi_NotifyBusy = 0x02047E94;
WFS_EnableSync = 0x02047EA8;
WFS_GetCurrentBitmap = 0x02047ED4;
WFS_GetStatus = 0x02047F14;
WFS_End = 0x02047F30;
WFS_Start = 0x020480A4;
WFS_InitChild = 0x02048120;
WFS_InitParent = 0x02048204;
WFSi_InitCommon = 0x02048404;
WFSi_OnChildSystemCallback = 0x020484B0;
WFSi_ReallocBitmap = 0x020487C0;
WFSi_OnParentSystemCallback = 0x02048890;
WFSi_PortCallback = 0x02048C50;
WFSi_OnSetMPDataDone = 0x02048DB4;
WFSi_SetMPData = 0x02048DFC;
WFSi_ReadRequest = 0x02048ED4;
WFSi_FromBusyToFree = 0x02048F3C;
WFSi_FromAliveToBusy = 0x02048F84;
WFSi_FromBusyToAlive = 0x02048FBC;
WFSi_FromFreeToBusy = 0x02048FF4;
WFSi_MoveList = 0x02049044;
WFSi_FindAliveForID = 0x020490BC;
WFSi_FindBusy = 0x020490F4;
WFSi_FindAlive = 0x0204916C;
WFSi_SendOpenAck = 0x020491B4;
WFSi_SendAck = 0x020492A0;
WFSi_SendMessage = 0x020494F8;
WFSi_OnSendMessageDone = 0x02049578;
WFSi_ReplaceRomArchive = 0x020495E0;
WFSi_LoadTables = 0x020496C0;
WFSi_RomArchiveProc = 0x02049A74;
WFSi_WriteRomCallback = 0x02049AF8;
WFSi_ReadRomCallback = 0x02049B00;
MBP_GetChildMacAddress = 0x02049B20;
MBP_GetPlayerNo = 0x02049B5C;
MBP_GetChildInfo = 0x02049C84;
MBP_GetChildState = 0x02049CB8;
MBP_GetChildBmp = 0x02049D80;
MBP_GetState = 0x02049D94;
MBP_ChangeState = 0x02049DA4;
ParentStateCallback = 0x02049DB4;
MBPi_CheckAllReboot = 0x0204A090;
MBP_Cancel = 0x0204A0D0;
MBP_StartRebootAll = 0x0204A0EC;
MBP_IsBootableAll = 0x0204A1CC;
MBP_StartDownloadAll = 0x0204A230;
MBP_StartDownload = 0x0204A2E4;
MBP_KickChild = 0x0204A3A8;
MBP_AcceptChild = 0x0204A46C;
MBP_RegistFile = 0x0204A500;
MBP_Start = 0x0204A5E8;
MBP_Init = 0x0204A640;
WH_GetCurrentAid = 0x0204A76C;
WH_End = 0x0204A77C;
WH_Finalize = 0x0204A7BC;
WH_Reset = 0x0204A8B0;
WH_StepDS = 0x0204A8D8;
WH_GetSharedDataAdr = 0x0204A940;
WH_SetJudgeAcceptFunc = 0x0204A960;
WH_ChildConnect = 0x0204A970;
WH_ParentConnect = 0x0204AA18;
WH_StateOutInitialize = 0x0204AAE4;
WH_StateInInitialize = 0x0204AB44;
WH_IndicateHandler = 0x0204AB94;
WH_Initialize = 0x0204ABC0;
SelectChannel = 0x0204AC4C;
WH_GetMeasureChannel = 0x0204AD28;
WHi_MeasureChannel = 0x0204AD60;
WH_StateOutMeasureChannel = 0x0204AD88;
WH_StateInMeasureChannel = 0x0204AE54;
WH_StartMeasureChannel = 0x0204AEF8;
WH_GetSystemState = 0x0204AFCC;
WH_GetBitmap = 0x0204AFDC;
WH_SetUserGameInfo = 0x0204AFEC;
WH_SetGgid = 0x0204B000;
WH_StateOutEnd = 0x0204B010;
WH_StateOutReset = 0x0204B044;
WH_StateInReset = 0x0204B078;
WH_StateOutEndChild = 0x0204B0B4;
WH_StateInEndChild = 0x0204B0E4;
WH_StateOutEndChildMP = 0x0204B128;
WH_StateInEndChildMP = 0x0204B16C;
WH_StateInEndChildKeyShare = 0x0204B1A8;
WH_StateInStartChildKeyShare = 0x0204B210;
WH_StateOutStartChildMP = 0x0204B27C;
WH_StateInStartChildMP = 0x0204B39C;
WH_StateOutStartChild = 0x0204B414;
WH_StateInStartChild = 0x0204B504;
WH_StateOutSetChildWEPKey = 0x0204B594;
WH_StateInSetChildWEPKey = 0x0204B5DC;
WH_StateOutEndScan = 0x0204B648;
WH_StateInEndScan = 0x0204B6DC;
WH_EndScan = 0x0204B710;
WH_StateOutStartScan = 0x0204B748;
WH_StateInStartScan = 0x0204B898;
WH_StartScan = 0x0204B978;
WH_TurnOnPictoCatch = 0x0204B9FC;
WH_StateOutEndParent = 0x0204BA10;
WH_StateInEndParent = 0x0204BA40;
WH_StateOutEndParentMP = 0x0204BA74;
WH_StateInEndParentMP = 0x0204BAB4;
WH_StateInEndParentKeyShare = 0x0204BAF0;
WH_StateInStartParentKeyShare = 0x0204BB40;
WH_StateOutStartParentMP = 0x0204BB80;
WH_StateInStartParentMP = 0x0204BC8C;
WH_StateOutStartParent = 0x0204BD2C;
WH_StateInStartParent = 0x0204BE88;
WH_StateOutSetParentWEPKey = 0x0204BEFC;
WH_StateInSetParentWEPKey = 0x0204BF44;
WH_StateOutSetParentParam = 0x0204BFB0;
WH_StateInSetParentParam = 0x0204C02C;
WH_SetError = 0x0204C078;
WH_ChangeSysState = 0x0204C09C;

NNS_G3dGlbFlush = 0x02019928;
NNS_G3dGlbSetBaseTrans = 0x02058120;
NNS_G3dGlbSetBaseScale = 0x020580F8;
NNS_G3dGlbLightVector = 0x020580C4;
NNS_G3dGlbLightColor = 0x020580B0;
NNS_G3dGlbMaterialColorDiffAmb = 0x0205808C;
NNS_G3dGlbMaterialColorSpecEmi = 0x02058068;
NNS_G3dGlbPolygonAttr = 0x0205803C;
NNS_G3dAnmObjCalcSizeRequired = 0x02057EC0;
NNSi_G3dSendJointSRTBasic = 0x0205BF08;
NNS_G3dGetAnmByIdx = 0x0205A70C;
NNSi_G3dGetTexPatAnmTexNameByIdx = 0x0205A6FC;
NNSi_G3dGetTexPatAnmPlttNameByIdx = 0x0205A6EC;
NNSi_G3dGetTexPatAnmFV = 0x0205A670;
NNSi_G3dGetTexPatAnmDataByIdx = 0x0205A654;
NNS_G3dAnmObjInit = 0x02057E20;
addLink_ = 0x02057D08;
NNS_G3dRenderObjRemoveAnmObj = 0x02057BA8;
removeLink_ = 0x02057C08;
NNS_SndPlayerSetTrackPan_0 = 0x0205DC74;
NNSi_G3dGetJointScaleBasic = 0x0205BECC;
NNSi_G3dSendTexSRTXsi = 0x0205CB10;
NNSi_G3dSendTexSRT3dsMax = 0x0205C4A0;
texmtxCalc_flagTRS_ = 0x0205C5E8;
texmtxCalc_flagTR_ = 0x0205C60C;
texmtxCalc_flagTS_ = 0x0205C65C;
texmtxCalc_flagT_ = 0x0205C73C;
texmtxCalc_flagRS_ = 0x0205C83C;
texmtxCalc_flagR_ = 0x0205C884;
texmtxCalc_flagS_ = 0x0205C908;
texmtxCalc_flag_ = 0x0205C9FC;
NNSi_G3dSendJointSRTSi3d = 0x0205C370;
NNSi_G3dGetJointScaleSi3d = 0x0205C148;
NNSi_G3dSendTexSRTSi3d = 0x0205BF84;
NNSi_G3dModifyPolygonAttrMask = 0x0205A270;
NNSi_G3dModifyMatFlag = 0x0205a2d8;
NNS_G3dMdlSetMdlDiff = 0x0205A22C;
NNS_G3dMdlSetMdlAmb = 0x0205A1E8;
NNS_G3dMdlSetMdlEmi = 0x0205A1A4;
NNS_G3dMdlSetMdlLightEnableFlag = 0x0205A160;
NNS_G3dMdlSetMdlPolygonMode = 0x0205A11C;
NNS_G3dMdlSetMdlPolygonID = 0x0205A0D8;
NNS_G3dMdlSetMdlAlpha = 0x0205A094;
NNS_G3dMdlSetMdlAmbAll = 0x02059FD0;
NNS_G3dMdlSetMdlDiffAll = 0x0205A010;
NNS_G3dMdlSetMdlLightEnableFlagAll = 0x02059F90;
NNS_G3dMdlSetMdlPolygonModeAll = 0x02059F50;
NNS_G3dMdlSetMdlAlphaAll = 0x02059ED0;
NNSi_G3dFuncSbc_NODEMIX = 0x02058BB4;
NNSi_G3dFuncSbc_CALLDL = 0x02058AD4;
NNSi_G3dFuncSbc_ENVMAP = 0x020587B4;
NNSi_G3dFuncSbc_PRJMAP = 0x02058424;

FreeCommandBuffer = 0x2060330;
RemoveCommandByPlayer = 0x2060364;
FreeChannel = 0x20603D4;
ShutdownPlayer = 0x2060410;
ForceStopStrm = 0x2060474;
FreePlayer = 0x2060510;

PushCommand_impl = 0x2067510;

NNS_GfdInitFrmTexVramManager = 0x2056f40;
NNS_GfdResetFrmTexVramState = 0x2056ec4;
NNS_GfdSetFrmTexVramState = 0x2056c9c;
NNS_GfdGetFrmTexVramState = 0x2056ce8;
NNS_GfdFreeFrmTexVram = 0x2056d34;
NNS_GfdAllocFrmTexVram = 0x2056d3c;
NNSi_GfdSetTextNrmSearchArray = 0x2056fe0;
NNS_GfdInitFrmPlttVramManager = 0x20571c4;
NNS_GfdResetFrmPlttVramState = 0x2057030;
NNS_GfdSetFrmPlttVramState = 0x205704c;
NNS_GfdGetFrmPlttVramState = 0x2057068;
NNS_GfdFreeFrmPlttVram = 0x2057084;
NNS_GfdAllocFrmPlttVram = 0x205708c;

NNS_GfdDefaultFuncAllocTexVram = 0x02085338;
NNS_GfdDefaultFuncFreeTexVram = 0x0208533C;
NNS_GfdDefaultFuncAllocPlttVram = 0x02085340;
NNS_GfdDefaultFuncFreePlttVram = 0x02085344;

NNS_G3dRenderObjAddAnmObj = 0x02057C7C;
updateHintVec_ = 0x01FF8BE0;
NNS_G3dGeUseFastDma = 0x02059B58;
NNSi_G2dSplitCharUTF16 = 0x02057678;
MBi_StartParentCore = 0x020788C8;
MBi_GetTgid = 0x0207845C;
CARD_IsEnabled = 0x0206E074;
CARD_Enable = 0x0206E038;
NNSi_SndSeqArcGetSeqInfo = 0x02060C40;
GXS_BeginLoadBGExtPltt = 0x0206320C;
NNS_G3dRenderObjSetInitFunc = 0x02057B8C;
OSi_DoLockByWord = 0x02064290;
FSi_CloseFileCommand = 0x02068E30;
FSi_ReadDummyCallback = 0x0206A9C8;


/* DATA/BSS */

FX_SinCosTable_ = 0x2080304;
NNS_G3dGlb = 0x027e00c8;
fsi_default_dma_no = 0x02096100;


/* MSL */

__destroy_global_chain = 0x0207FC54;
__call_static_initializers = 0x207fca4;
__throw_catch_compare = 0x0207FCD4;
__register_global_object = 0x0207FEC0;
__cxa_vec_ctor = 0x02080050;
__cxa_vec_cleanup = 0x0207FF4C;
DestroyArrayRange = 0x020801C4;
__cxa_vec_new = 0x02080104;
FindExceptionHandler = 0x0207EA9C;
CurrentAction = 0x0207FAC4;
terminate = 0x0207FEE0;
thandler = 0x02085864;
dthandler = 0x0207FF00;
abs = 0x0207D0E4;
strncmp = 0x0207D2A4;
strcpy = 0x0207D428;
strlen = 0x0207D4F0;
exit = 0x0207CFFC;
__exit = 0x0207CECC;
__stdio_exit = 0x02098184;
abort = 0x0207D04C;
__aborting = 0x0209818C;
raise = 0x0207D2E4;
signal_funcs = 0x020986B0;
IsInSpecification = 0x0207ECE0;
__ThrowHandler = 0x0207E954;
FindExceptionRecord = 0x0207FAE0;
__FindExceptionTable = 0x0207E5F4;
__exception_table_start__ = 0x02025924;
__exception_table_end__ = 0x02025A44;
BinarySearch = 0x0207FBF0;
__SkipUnwindInfo = 0x0207E5C4;
__DecodeUnsignedNumber = 0x0207E7E8;
__throw = 0x0207E578;
__SetupFrameInfo = 0x0207E614;
FindMostRecentException = 0x0207ED64;
__DecodeSignedNumber = 0x0207E880;
NextAction = 0x0207F730;
__PopStackFrame = 0x0207E6B4;
UnwindStack = 0x0207EEB4;
SetupCatchInfo = 0x0207EA34;
__TransferControl = 0x0207E548;
HandleUnexpected = 0x0207EC78;
sys_readc = 0x0207E728;
sys_exit = 0x0207E73C;
sys_writec = 0x0207E714;
__write_console = 0x0207E754;
__read_console = 0x0207E788;
__console_exit = 0x02098180;
atexit_curr_func = 0x02098188;
atexit_funcs = 0x02098190;
fflush = 0x0207D1BC;
__flush_all = 0x0207D078;
__files = 0x02085780;
__flush_buffer = 0x0207D0F0;
__convert_from_newlines = 0x0207D1B8;
__prep_buffer = 0x0207D184;
_ExitProcess = 0x0207E53C;
__cxa_vec_delete = 0x0207FF0C;
__cxa_vec_dtor = 0x0207FFB4;
__end__catch = 0x0207E918;
__close_console = 0x0207E74C;

_s32_div_f = 0x0207E138;
_u32_div_f = 0x0207E344;
_u32_div_not_0_f = 0x0207E34C;

__global_destructor_chain = 0x020986CC;



/*----------------------------------------------------------------*/
/*------------------------- filesystem ---------------------------*/
/*----------------------------------------------------------------*/

_ZN2FS10unloadFileEPv = 0x020087C0;
_ZN2FS23getDecompressedFileSizeEm = 0x02009ACC;
_ZN2FS11getFileSizeEm = 0x02009AF0;
_ZN2FS11loadExtFileEm = 0x020087F0;
_ZN2FS11loadExtFileEmPv = 0x02008934;
_ZN2FS11loadExtFileEmPvl = 0x020088FC;
_ZN2FS11loadExtFileEmb = 0x02008810;
_ZN2FS11setReadModeENS_8ReadModeE = 0x02008990;
_ZN2FS12fileIDOffsetE = 0x02085D04;
_ZN2FS10romArchiveE = 0x02085D08;
_ZN2FS12loadFileLZ77Em = 0x0200869C;
_ZN2FS12loadFileLZ77EmPv = 0x02008784;
_ZN2FS12readFileFastEP6FSFileb = 0x020089A0;
_ZN2FS12readFileSafeEP6FSFileb = 0x02008A6C;
_ZN2FS12setFileCountEt = 0x02009410;
_ZN2FS13hasLZ77HeaderEPv = 0x02008E00;
_ZN2FS13loadBGPaletteEmmb = 0x02009918;
_ZN2FS14loadOBJPaletteEmmb = 0x02009A30;
_ZN2FS15setFileIDOffsetEbt = 0x020093F8;
_ZN2FS15setReadModeFastEv = 0x02008970;
_ZN2FS15setReadModeSafeEv = 0x02008980;
_ZN2FS16loadBGSubPaletteEmm = 0x02009878;
_ZN2FS17loadOBJExtPaletteEmmb = 0x020099C8;
_ZN2FS17readFunctionTableE = 0x0203A390;
_ZN2FS18loadFileToOBJVramAEmm = 0x02009A98;
_ZN2FS20loadExtFileUnflushedEm = 0x02008800;
_ZN2FS22loadBGExtPaletteCachedEmm = 0x020098CC;
_ZN2FS23getLZ77DecompressedSizeEPv = 0x02009478;
_ZN2FS23loadOBJExtPaletteCachedEmm = 0x02009980;
_ZN2FS4initEv = 0x02009424;

_ZN2FS5Cache10CacheEntry17loadFileToOverlayEmb = 0x0200A194;
_ZN2FS5Cache10CacheEntry6unloadEv = 0x0200A10C;
_ZN2FS5Cache10CacheEntry8loadDataEm = 0x0200A138;
_ZN2FS5Cache10CacheEntry8loadFileEmb = 0x0200A234;

_ZN2FS5Cache10CacheEntryC1Ev = 0x0200A358;
_ZN2FS5Cache10CacheEntryC2Ev = 0x0200A358;
_ZN2FS5Cache10CacheEntryD0Ev = 0x0200A2B0;
_ZN2FS5Cache10CacheEntryD1Ev = 0x0200A308;
_ZN2FS5Cache10CacheEntryD2Ev = 0x0200A308;

_ZN2FS5Cache10unloadFileEm = 0x02009B94;
_ZN2FS5Cache15activeFileCacheE = 0x02085E0C;
_ZN2FS5Cache15overlayFileDestE = 0x02085E10;
_ZN2FS5Cache15overlayFileSizeE = 0x02085E14;
_ZN2FS5Cache17loadFileToOverlayEmb = 0x02009C14;
_ZN2FS5Cache17setupCacheEntriesEv = 0x0200A0B4;
_ZN2FS5Cache5clearEv = 0x02009B64;
_ZN2FS5Cache7getFileEm = 0x02009CB4;
_ZN2FS5Cache8Internal10unloadFileEmPNS0_10CacheEntryEm = 0x02009D6C;
_ZN2FS5Cache8Internal11setup3DFileEPvb = 0x02009DEC;
_ZN2FS5Cache8Internal16getFileInOverlayEmPNS0_10CacheEntryEmbb = 0x02009F8C;
_ZN2FS5Cache8Internal17loadFileToOverlayEmPNS0_10CacheEntryEmb = 0x02009E7C;
_ZN2FS5Cache8Internal5clearEPNS0_10CacheEntryEm = 0x02009D30;
_ZN2FS5Cache8Internal7getDataEmPNS0_10CacheEntryEm = 0x02009F2C;
_ZN2FS5Cache8Internal7getFileEmPNS0_10CacheEntryEmbb = 0x0200A020;
_ZN2FS5Cache8Internal8findFileEm = 0x02009CD4;
_ZN2FS5Cache8Internal8loadDataEmPNS0_10CacheEntryEm = 0x02009DC0;
_ZN2FS5Cache8Internal8loadFileEmPNS0_10CacheEntryEmb = 0x02009ED4;
_ZN2FS5Cache8loadDataEm = 0x02009BC8;
_ZN2FS5Cache8loadFileEmb = 0x02009C64;

_ZN2FS8Internal11crashReasonE = 0x02085CF8;
_ZN2FS8Internal11loadOverlayE11MIProcessorm = 0x02008594;
_ZN2FS8Internal12pathToFileIDEP8FSFileIDPKc = 0x02008648;
_ZN2FS8Internal13unloadOverlayE11MIProcessorm = 0x02008588;
_ZN2FS8Internal9terminateEPKc = 0x02008670;
_ZN2FS8Internal15loadOverlayInfoEP13FSOverlayInfo11MIProcessorm = 0x020085A0;
_ZN2FS8Internal8openFileEP6FSFile8FSFileID = 0x0200860C;
_ZN2FS8Internal8openFileEP6FSFilePKc = 0x020085E4;
_ZN2FS8Internal8readFileEP6FSFilePvl = 0x020085AC;
_ZN2FS8Internal9getFileIDEm = 0x02008E2C;
_ZN2FS8InternalL13openFileCrashE = 0x0203A280;
_ZN2FS8InternalL13readFileCrashE = 0x0203A290;
_ZN2FS8InternalL17readFileFastCrashE = 0x0203A2A0;
_ZN2FS8InternalL24convertPathToFileIDCrashE = 0x0203A2B4;

_ZN2FS7Archive10mountFrontEmP4Heap = 0x0200917C;
_ZN2FS7Archive10unmountAllEv = 0x02009084;
_ZN2FS7Archive11unmountListEPm = 0x020090D0;
_ZN2FS7Archive14unmountCurrentEv = 0x02008FF4;
_ZN2FS7Archive16currentArchiveIDE = 0x0203A2CC;
_ZN2FS7Archive16mainGameArchivesE = 0x020262D0;
_ZN2FS7Archive16minigameArchivesE = 0x020262DC;
_ZN2FS7Archive20loadMainGameArchivesEv = 0x020097D0;
_ZN2FS7Archive20loadMinigameArchivesEv = 0x02009800;
_ZN2FS7Archive20unmountAndMountListsEPmS1_bP4Heap = 0x0200902C;
_ZN2FS7Archive22unloadMinigameArchivesEv = 0x020097EC;
_ZN2FS7Archive5mountEPKcS2_P4Heapl = 0x020092B0;
_ZN2FS7Archive5mountEmbP4Heap = 0x020091A4;
_ZN2FS7Archive7getFileEt = 0x02008F50;
_ZN2FS7Archive7unmountEP13NNSFndArchiveP4Heap = 0x02009288;
_ZN2FS7Archive7unmountEm = 0x020090F8;
_ZN2FS7Archive8archivesE = 0x0203A6C0;
_ZN2FS7Archive9mountBackEmP4Heap = 0x02009190;
_ZN2FS7Archive9mountListEPmbP4Heap = 0x02009134;

_ZN2FS7Overlay12trackAndLoadEm = 0x02009560;
_ZN2FS7Overlay14loadedOverlaysE = 0x02085D0C;
_ZN2FS7Overlay22initLoadedOverlayTableEv = 0x02009484;
_ZN2FS7Overlay4loadEm = 0x02009510;
_ZN2FS7Overlay5flushEP13FSOverlayInfo = 0x02009798;
_ZN2FS7Overlay7untrackEm = 0x020094B8;

_ZN2FS8loadFileE8FSFileIDPvl = 0x02008D14;
_ZN2FS8loadFileEPKcPvl = 0x02008CD8;
_ZN2FS8loadFileEt = 0x020087E0;
_ZN2FS8loadFileEtb = 0x02008828;
_ZN2FS8openFileEP6FSFilet = 0x02008E54;
_ZN2FS8readFileEP6FSFilePvl = 0x02008D80;
_ZN2FS8readFileEP6FSFileb = 0x02008944;
_ZN2FS8readModeE = 0x02085CFC;
_ZN2FS8toFileIDEm = 0x02009394;
_ZN2FS9fileCountE = 0x02085D00;
_ZN2FS9getFileIDEPKc = 0x0200936C;


/*----------------------------------------------------------------*/
/*---------------------------- heap ------------------------------*/
/*----------------------------------------------------------------*/

_ZN4HeapC1EPvmPS_ = 0x020455A0;
_ZN4HeapD1Ev = 0x02045538;
_ZN4HeapD2Ev = 0x02045508;
_ZN4HeapD0Ev = 0x02045518;

_ZN4Heap10vLockMutexEv = 0x020451D8;
_ZN4Heap12vUnlockMutexEv = 0x020451D4;
_ZN4Heap13vTryLockMutexEv = 0x020451CC;
_ZN4Heap8allocateEml = 0x02045040;
_ZN4Heap10deallocateEPv = 0x02044D94;
_ZN4Heap7disposeEv = 0x02045128;
_ZN4Heap7destroyEv = 0x02045134;
_ZN4Heap17forcePo2AlignmentElm = 0x02045014;
_ZN4Heap9lockMutexEv = 0x020451F8;
_ZN4Heap18maxAllocatableSizeEl = 0x02044EA4;
_ZN4Heap21maxAllocationUnitSizeEv = 0x02044F34;
_ZN4Heap10reallocateEPvm = 0x02044E20;
_ZN4Heap11resizeToFitEv = 0x02044BF4;
_ZN4Heap10setGroupIDEt = 0x02044C70;
_ZN4Heap6sizeOfEPv = 0x02044CC8;
_ZN4Heap4testEv = 0x02044F74;
_ZN4Heap8setFlagsEm = 0x02044B78;
_ZN4Heap11unlockMutexEv = 0x020451DC;
_ZN4Heap10setCurrentEPS_ = 0x02044B48;

_ZN12ExpandedHeapC1EPvmP4HeapS0_ = 0x02045570;
_ZN12ExpandedHeapD1Ev = 0x020454E8;
_ZN12ExpandedHeapD0Ev = 0x020454C0;

_ZN12ExpandedHeap10vLockMutexEv = 0x020451BC;
_ZN12ExpandedHeap12vUnlockMutexEv = 0x020451AC;
_ZN12ExpandedHeap13vTryLockMutexEv = 0x0204519C;
_ZN12ExpandedHeap8vDestroyEv = 0x0204510C;
_ZN12ExpandedHeap9vAllocateEml = 0x02044FE0;
_ZN12ExpandedHeap11vDeallocateEPv = 0x02044D70;
_ZN12ExpandedHeap14vDeallocateAllEv = 0x02044D1C;
_ZN12ExpandedHeap7vIntactEv = 0x02044FA4;
_ZN12ExpandedHeap5vTestEv = 0x02044F70;
_ZN12ExpandedHeap11vReallocateEPvm = 0x02044E10;
_ZN12ExpandedHeap7vSizeOfEPv = 0x02044CB8;
_ZN12ExpandedHeap22vMaxAllocationUnitSizeEv = 0x02044F20;
_ZN12ExpandedHeap19vMaxAllocatableSizeEv = 0x02044EF8;
_ZN12ExpandedHeap19vMaxAllocatableSizeEl = 0x02044E94;
_ZN12ExpandedHeap11vMemoryLeftEv = 0x02044E74;
_ZN12ExpandedHeap11vSetGroupIDEt = 0x02044C60;
_ZN12ExpandedHeap11vGetGroupIDEv = 0x02044C48;
_ZN12ExpandedHeap12vResizeToFitEv = 0x02044BEC;
_ZN12ExpandedHeap6createEmP4Heap = 0x02045338;
_ZN12ExpandedHeap16invokeDeallocateEPvS0_m = 0x02044D38;

_ZN9FrameHeapC1EPvmP4HeapS0_ = 0x02045548;
_ZN9FrameHeapD1Ev = 0x020454A0;
_ZN9FrameHeapD0Ev = 0x02045478;

_ZN9FrameHeap8vDestroyEv = 0x020450F0;
_ZN9FrameHeap9vAllocateEml = 0x02044FAC;
_ZN9FrameHeap11vDeallocateEPv = 0x02044D50;
_ZN9FrameHeap14vDeallocateAllEv = 0x02044D08;
_ZN9FrameHeap7vIntactEv = 0x02044F9C;
_ZN9FrameHeap5vTestEv = 0x02044F6C;
_ZN9FrameHeap11vReallocateEPvm = 0x02044E00;
_ZN9FrameHeap7vSizeOfEPv = 0x02044CB0;
_ZN9FrameHeap22vMaxAllocationUnitSizeEv = 0x02044F0C;
_ZN9FrameHeap19vMaxAllocatableSizeEv = 0x02044EE4;
_ZN9FrameHeap19vMaxAllocatableSizeEl = 0x02044E84;
_ZN9FrameHeap11vMemoryLeftEv = 0x02044E60;
_ZN9FrameHeap11vSetGroupIDEt = 0x02044C58;
_ZN9FrameHeap11vGetGroupIDEv = 0x02044C40;
_ZN9FrameHeap12vResizeToFitEv = 0x02044BA0;
_ZN9FrameHeap6createEmP4Heap = 0x02045230;
_ZN9FrameHeap6createEmP4Heapl = 0x02045240;

_ZN6Memory25defaultHeapAllocatorFlagsE = 0x020850E8;
_ZN6Memory15rootHeapCreatedE = 0x0208B718;
_ZN6Memory19rootHeapInitialSizeE = 0x0208B71C;
_ZN6Memory11gameHeapPtrE = 0x0208B720;
_ZN6Memory15rootHeapArenaIDE = 0x0208B724;
_ZN6Memory14currentHeapPtrE = 0x0208B72C;
_ZN6Memory11rootHeapPtrE = 0x0208B730;
_ZN6Memory24heapDeallocationFunctionE = 0x0208B734;
_ZN6Memory22heapAllocationFunctionE = 0x0208B738;
_ZN6Memory25isHeapListHeadInitializedE = 0x0208FE8C;
_ZN6Memory8heapListE = 0x0208FE90;
_ZN6Memory24prevSwitchThreadCallbackE = 0x0208B728;
_ZN6Memory12initRootHeapEv = 0x020455D8;
_ZN6Memory13setupRootHeapEPvm = 0x02045650;
_ZN6Memory13setupGameHeapEPvm = 0x02044AD8;
_ZN6Memory21tryCreateExpandedHeapEPvm = 0x0204540C;
_ZN6Memory24heapSwitchThreadCallbackEP9_OSThreadS1_ = 0x020456F8;
_ZN6Memory13setThreadHeapEP9_OSThreadP4Heap = 0x020456C0;
_ZN6Memory27setHeapSwitchThreadCallbackEv = 0x02045690;

_ZN6Memory8allocateEP4Heapml		= 0x02044B3C;
_ZN6Memory8allocateEP4Heapm			= 0x02044B2C;
_ZN6Memory10deallocateEP4HeapPv		= 0x02044B20;
_ZN6Memory6sizeOfEP4HeapPv			= 0x02044B14;
_ZN6Memory10reallocateEP4HeapPvm	= 0x02044AF8;
_ZN6Memory10deallocateEPvP4Heap		= 0x02044AB0;
_ZN6Memory8allocateEml				= 0x02044A8C;
_ZN6Memory8allocateEm				= 0x02044A6C;
_ZN6Memory10deallocateEPv			= 0x02044A50;

_Z6mallocj	= 0x0204C0F8;
_Z6mallocm	= 0x0204C0F8;
_Z4freePv	= 0x0204C0DC;
_Znwj		= 0x0204C0D0;
_Znwm		= 0x0204C0D0;
_Znaj		= 0x0204C0C4;
_Znam		= 0x0204C0C4;
_ZdlPv		= 0x0204C0B8;
_ZdlPvj		= 0x0204C0B8;
_ZdlPvm		= 0x0204C0B8;
_ZdaPv		= 0x0204C0AC;

_ZTV9FrameHeap = 0x02085144;
_ZTV12ExpandedHeap = 0x020850EC;
_ZTV4Heap = 0x0208519C;


/*----------------------------------------------------------------*/
/*-------------------------- text/font ---------------------------*/
/*----------------------------------------------------------------*/

_ZN13FontLinkStackC1Ev = 0x020171A0;
_ZN13FontLinkStackD1Ev = 0x020171C0;
_ZN13FontLinkStack5emptyEv = 0x020171C4;
_ZN13FontLinkStack4pushEPPt = 0x020171D8;
_ZN13FontLinkStack4peekEv = 0x020171F4;
_ZN13FontLinkStack3popEv = 0x02017204;
_ZN13FontLinkStack5clearEv = 0x02017224;

_ZN14UTF16CharacterC1EPt = 0x02016C7C;
_ZN14UTF16Character6decodeEv = 0x02016BA0;

_ZN14EscapeSequenceC1EPh = 0x02016B34;
_ZN14EscapeSequence5parseEPh = 0x02016AC8;
_ZN14EscapeSequence12getParameterEv = 0x02016A90;
_ZN14EscapeSequence13readParameterEPt = 0x02016AAC;
_ZN14EscapeSequence8buildU16EPhm = 0x02016B6C;

_ZN8FontBaseC2Ev = 0x02016A4C;
_ZN8FontBaseD1Ev = 0x02016A24;
_ZN8FontBaseD2Ev = 0x020169CC;
_ZN8FontBaseD0Ev = 0x020169F4;

_ZN8FontBase7prepareEv = 0x020169C8;
_ZN8FontBase18onStringDispatchedEv = 0x020169C4;
_ZN8FontBase11processCharEP14UTF16Character = 0x020169C0;
_ZN8FontBase19parseEscapeSequenceEP14EscapeSequence = 0x020169BC;
_ZN8FontBase5resetEv = 0x02016A78;
_ZN8FontBase7addLinkEPt = 0x02016818;
_ZN8FontBase11restoreLinkEv = 0x020167F4;
_ZN8FontBase4copyEPS_ = 0x02016848;
_ZN8FontBase10setCharPtrEPt = 0x02016890;
_ZN8FontBase15processNextCharEb = 0x020168B0;

_ZN9FontCacheC1Ev = 0x020167C8;
_ZN9FontCacheD1Ev = 0x020167A8;
_ZN9FontCacheD2Ev = 0x02016760;
_ZN9FontCacheD0Ev = 0x02016780;

_ZN9FontCache18onStringDispatchedEv = 0x02016614;
_ZN9FontCache13processStringEPt = 0x02016744;
_ZN9FontCache13processStringEPS_ = 0x02016714;
_ZN9FontCache13processStringEmPt = 0x020166BC;

_ZN11StringCacheC1Ev = 0x020165F4;
_ZN11StringCacheD1Ev = 0x020165D4;
_ZN11StringCacheD0Ev = 0x020165AC;

_ZN11StringCache12getCacheSizeEv = 0x020165A4;
_ZN11StringCache11getCachePtrEv = 0x0201659C;

_ZN13NicknameCacheC1Ev = 0x0201657C;
_ZN13NicknameCacheD1Ev = 0x0201655C;
_ZN13NicknameCacheD0Ev = 0x02016534;

_ZN13NicknameCache12getCacheSizeEv = 0x02016430;
_ZN13NicknameCache11getCachePtrEv = 0x02016428;
_ZN13NicknameCache17stringifyNicknameEv = 0x020164B4;
_ZN13NicknameCache18stringifyOtherNameEPtm = 0x02016438;

_ZN11NumberCacheC1Ev = 0x02016390;
_ZN11NumberCacheD1Ev = 0x02016370;
_ZN11NumberCacheD0Ev = 0x02016348;

_ZN11NumberCache12getCacheSizeEv = 0x02016260;
_ZN11NumberCache11getCachePtrEv = 0x02016258;
_ZN11NumberCache15stringifyNumberEm = 0x02016268;
_ZN11NumberCache11numberTableE = 0x02026670;

_ZN12GenericCacheC1Ev = 0x02016408;
_ZN12GenericCacheD1Ev = 0x020163E8;
_ZN12GenericCacheD0Ev = 0x020163C0;

_ZN12GenericCache12getCacheSizeEv = 0x020163B8;
_ZN12GenericCache11getCachePtrEv = 0x020163B0;

_ZN10FontBoundsC1EP12FontRenderer = 0x02015EC0;
_ZN10FontBoundsD1Ev = 0x02015EA0;
_ZN10FontBoundsD0Ev = 0x02015E78;

_ZN10FontBounds11processCharEP14UTF16Character = 0x02015C6C;
_ZN10FontBounds19parseEscapeSequenceEP14EscapeSequence = 0x02015B38;
_ZN10FontBounds16getNextLineWidthEP8FontBaseP10NNSG2dFonth = 0x02015E18;
_ZN10FontBounds19getIndexedLineWidthEPtP10NNSG2dFonthm = 0x02015DA4;
_ZN10FontBounds12getLineCountEPt = 0x02015D48;
_ZN10FontBounds17getCharacterWidthEt = 0x02015CF4;
_ZN10FontBounds17linkNicknameCacheEP14EscapeSequence = 0x02015B04;
_ZN10FontBounds15linkNumberCacheEP14EscapeSequence = 0x02015AD0;
_ZN10FontBounds17linkGenericCache0EP14EscapeSequence = 0x02015A9C;
_ZN10FontBounds17linkGenericCache1EP14EscapeSequence = 0x02015A68;
_ZN10FontBounds17linkGenericCache2EP14EscapeSequence = 0x02015A34;
_ZN10FontBounds17linkGenericCache3EP14EscapeSequence = 0x02015A00;
_ZN10FontBounds19escapeSequenceTableE = 0x0203C184;
_ZN10FontBounds24sequenceTableInitializedE = 0x02089514;
_ZN10FontBounds14linkNicknameCBE = 0x0203BFEC;
_ZN10FontBounds12linkNumberCBE = 0x0203C014;
_ZN10FontBounds14linkGeneric0CBE = 0x0203BFCC;
_ZN10FontBounds14linkGeneric1CBE = 0x0203C00C;
_ZN10FontBounds14linkGeneric2CBE = 0x0203BFF4;
_ZN10FontBounds14linkGeneric3CBE = 0x0203BFE4;

_ZN8FontTile6decodeEPmS0_m = 0x02014DBC;

_ZN10FontStringC1Ev = 0x02016104;
_ZN10FontStringD1Ev = 0x020160DC;
_ZN10FontStringD0Ev = 0x020160AC;

_ZN10FontString5setupEPhmmP10NNSG2dFont = 0x02016000;
_ZN10FontString15setFontTileListEP8FontTilem = 0x020161D8;
_ZN10FontString12getLineCountEv = 0x020161B0;
_ZN10FontString19getIndexedLineWidthEm = 0x02016170;
_ZN10FontString15allocateBuffersEv = 0x02015F8C;
_ZN10FontString11freeBuffersEv = 0x02015F48;
_ZN10FontString12clearBuffersEv = 0x02015F08;
_ZN10FontString12deleteTargetEv = 0x02015FE8;

_ZN12FontRendererC1Ev = 0x020156B0;
_ZN12FontRendererD1Ev = 0x02015624;
_ZN12FontRendererD0Ev = 0x02015590;

_ZN12FontRenderer7prepareEv = 0x02015438;
_ZN12FontRenderer18onStringDispatchedEv = 0x020153EC;
_ZN12FontRenderer11processCharEP14UTF16Character = 0x020153E0;
_ZN12FontRenderer19parseEscapeSequenceEP14EscapeSequence = 0x02015294;
_ZN12FontRenderer14setupAndRenderEPhmmPvm = 0x0201596C;
_ZN12FontRenderer14setupAndRenderEPhmmP9FontCacheP10NNSG2dFont = 0x020158E4;
_ZN12FontRenderer25loadAndRenderGenericCacheEmPvm = 0x020158A0;
_ZN12FontRenderer18renderGenericCacheEmP9FontCache = 0x02015874;
_ZN12FontRenderer17clearGenericCacheEm = 0x020157B0;
_ZN12FontRenderer18resetSpecialCachesEv = 0x02015524;
_ZN12FontRenderer12uploadBufferEv = 0x02015474;
_ZN12FontRenderer21getNextFreeFontStringEv = 0x02015258;
_ZN12FontRenderer13convertBufferEP8FontTile = 0x02014EC8;
_ZN12FontRenderer18calculateAlignmentEv = 0x02014D24;
_ZN12FontRenderer10renderCharEP14UTF16Character = 0x0201518C;
_ZN12FontRenderer11renderGlyphEP11NNSG2dGlyph = 0x02014FE8;
_ZN12FontRenderer16renderFontStringEP10FontString = 0x02014C08;
_ZN12FontRenderer17renderFontStringsEv = 0x020154DC;
_ZN12FontRenderer17linkNicknameCacheEP14EscapeSequence = 0x02014BD8;
_ZN12FontRenderer15linkNumberCacheEP14EscapeSequence = 0x02014BA8;
_ZN12FontRenderer17linkGenericCache0EP14EscapeSequence = 0x02014B78;
_ZN12FontRenderer17linkGenericCache1EP14EscapeSequence = 0x02014B48;
_ZN12FontRenderer17linkGenericCache2EP14EscapeSequence = 0x02014B18;
_ZN12FontRenderer17linkGenericCache3EP14EscapeSequence = 0x02014AE8;
_ZN12FontRenderer16setColorSelectorEP14EscapeSequence = 0x02014ACC;
_ZN12FontRenderer19escapeSequenceTableE = 0x0203C244;
_ZN12FontRenderer24sequenceTableInitializedE = 0x02089510;
_ZN12FontRenderer14linkNicknameCBE = 0x0203BFDC;
_ZN12FontRenderer12linkNumberCBE = 0x0203BFFC;
_ZN12FontRenderer14linkGeneric0CBE = 0x0203BFC4;
_ZN12FontRenderer14linkGeneric1CBE = 0x0203C01C;
_ZN12FontRenderer14linkGeneric2CBE = 0x0203BFBC;
_ZN12FontRenderer14linkGeneric3CBE = 0x0203BFD4;
_ZN12FontRenderer13colorSelectCBE = 0x0203C004;

_ZN9BMGReaderC1Ev = 0x020170AC;
_ZN9BMGReaderD1Ev = 0x0201709C;
_ZN9BMGReaderD0Ev = 0x0201707C;

_ZN9BMGReader14parseBMGHeaderEv = 0x02016E98;
_ZN9BMGReader12parseBMGInfoEv = 0x02016DC8;
_ZN9BMGReader12parseBMGDataEv = 0x02016D70;
_ZN9BMGReader5resetEPvm = 0x02016F68;
_ZN9BMGReader14parseBMGStringEv = 0x02016CD0;
_ZN9BMGReader16processBMGStringEP9FontCache = 0x02016CA4;
_ZN9BMGReader6renderEP9FontCachePvm = 0x02016FD4;
_ZN9BMGReader13renderClearedEP9FontCachePvm = 0x020161E4;

_ZN4Font8mainFontE = 0x02089524;
_ZN4Font11loadingFontE = 0x02089530;
_ZN4Font9bmgReaderE = 0x0208953C;
_ZN4Font12fontRendererE = 0x02089594;
_ZN4Font16scriptFileIDListE = 0x0202665C;
_ZN4Font15selectFileTilesE = 0x020266C8;
_ZN4Font16gameTextboxTilesE = 0x0203C1E4;
_ZN4Font16yesNoOptionTilesE = 0x0203C044;
_ZN4Font17mvslModeMenuTilesE = 0x02026698;
_ZN4Font19mvslSelectMenuTilesE = 0x02026734;
_ZN4Font16mvslLoadingTilesE = 0x0202668C;
_ZN4Font21mvslResultScreenTilesE = 0x020266F8;
_ZN4Font11getMainFontEv = 0x02014AC0;
_ZN4Font14getLoadingFontEv = 0x02014AB4;
_ZN4Font12getBMGReaderEv = 0x02014AA8;
_ZN4Font15getFontRendererEv = 0x02014A9C;
_ZN4Font15getScriptFileIDEm = 0x02017190;
_ZN4Font13initMainFontsEv = 0x02014A58;
_ZN4Font8loadFontEP10NNSG2dFontm = 0x02017184;
_ZN4Font16loadFontInternalEP10NNSG2dFontm = 0x02017164;
_ZN4Font12renderBufferEv = 0x02014A30;
_ZN4Font10updateFontEv = 0x02014A44;

_ZN4Util7reverseEPm = 0x02017134;
_ZN4Util11dereferenceEPm = 0x0201712C;
_ZN4Util11dereferenceEPt = 0x02017124;
_ZN4Util11dereferenceEPh = 0x0201711C;
_ZN4Util11dereferenceEPhm = 0x02016B98;

_ZTV9BMGReader = 0x0203C024;
_ZTV12FontRenderer = 0x0203C05C;
_ZTV10FontString = 0x0203C034;
_ZTV10FontBounds = 0x0203C07C;
_ZTV12GenericCache = 0x0203C0E4;
_ZTV11NumberCache = 0x0203C0BC;
_ZTV13NicknameCache = 0x0203C134;
_ZTV11StringCache = 0x0203C15C;
_ZTV9FontCache = 0x0203C10C;
_ZTV8FontBase = 0x0203C09C;


/*----------------------------------------------------------------*/
/*---------------------------- sound -----------------------------*/
/*----------------------------------------------------------------*/

_ZN3SND9stopFlagsE = 0x02088b54;

_ZN3SND22loadToadHouseLevelSeqsEv = 0x02011988;
_ZN3SND21clearAndLoadLevelSeqsEv = 0x020119E8;
_ZN3SND17loadLevelThemeSeqEv = 0x02011ACC;
_ZN3SND19clearAndLoadSFXSet1Ev = 0x02011B64;
_ZN3SND15loadLevelSoundsEv = 0x02011B84;
_ZN3SND16clearAndLoadSeqsEPl = 0x02011BF8;
_ZN3SND21clearAndLoadSingleSeqEl = 0x02011C34;
_ZN3SND28loadMvsLSFXSetAndSetSeqCountEv = 0x02011C64;
_ZN3SND26clearAndLoadSeqsAndSFXSetsEPlS0_ = 0x02011C84;
_ZN3SND30clearAndLoadSingleSeqAndSFXSetEll = 0x02011CE4;
_ZN3SND24clearAndLoadSingleSFXSetEl = 0x02011D24;
_ZN3SND13stopAllSoundsEv = 0x02011D40;
_ZN3SND24setTempoRatioIfDifferentEl = 0x02011D60;
_ZN3SND19stopSpecialLevelSeqEl = 0x02011D94;
_ZN3SND20startSpecialLevelSeqEl = 0x02011DC4;
_ZN3SND18playerDoesNotExistEv = 0x02011DD4;
_ZN3SND18stopSeqForEntranceEl = 0x02011DF4;
_ZN3SND7stopSeqEl = 0x02011E3C;
_ZN3SND8startSeqEll = 0x02011E7C;
_ZN3SND18startLevelThemeSeqEl = 0x02011F04;
_ZN3SND14updateSFXRangeEv = 0x02011F5C;
_ZN3SND27playArcSFXAtPosIfInPosRangeEllP4Vec3ll = 0x02012038;
_ZN3SND7playSFXEl = 0x020121E4;
_ZN3SND15playEntranceSFXElPK4Vec3 = 0x0201220C;
_ZN3SND15playSFXChannel2ElPK4Vec3l = 0x0201224C;
_ZN3SND15playSFXChannel2ElPK4Vec3 = 0x02012290;
_ZN3SND15playSFXChannel1ElPK4Vec3l = 0x020122D0;
_ZN3SND15playSFXChannel1ElPK4Vec3 = 0x02012314;
_ZN3SND15playSFXChannel0ElPK4Vec3l = 0x02012354;
_ZN3SND15playSFXChannel0ElPK4Vec3 = 0x02012398;
_ZN3SND4loopEv = 0x020123D8;
_ZN3SND19setCurrentSoundArc0Ev = 0x020125C4;
_ZN3SND7initDLPEv = 0x020125D4;
_ZN3SND4initEv = 0x020125E8;
_ZN3SND9resetVarsEv = 0x02012638;
_ZN3SND17setupForSeqCount1Ev = 0x02012714;
_ZN3SND8Internal20setTrackPanForWorld8Eb = 0x0204D98C;
_ZN3SND8Internal21allocBossSndHeapStateEv = 0x0204DA18;
_ZN3SND8Internal18setCurrentSoundArcEl = 0x0204DA6C;
_ZN3SND8Internal17setUseLuigiSoundsEb = 0x0204DAD8;
_ZN3SND8Internal19setPlayableSeqCountEl = 0x0204DAE8;
_ZN3SND8Internal11updateBahpsEPv = 0x0204DB48;
_ZN3SND8Internal7inRangeElll = 0x0204DC2C;
_ZN3SND8Internal3absEl = 0x0204DC48;
_ZN3SND8Internal5clampElll = 0x0204DC54;
_ZN3SND8Internal9wrapRangeElll = 0x0204DC6C;
_ZN3SND8Internal15setOutputEffectE29NNSSndCaptureOutputEffectType = 0x0204DC98;
_ZN3SND8Internal10moveVolumeEll = 0x0204DCB4;
_ZN3SND8Internal10stopAllSFXEl = 0x0204DD00;
_ZN3SND8Internal10playArcSFXEll = 0x0204DD74;
_ZN3SND8Internal15playArcSFXAtPosEllPNS0_11SFXPlayInfoEl = 0x0204DE10;
_ZN3SND8Internal18getHandleForArcSFXEll = 0x0204E304;
_ZN3SND8Internal25getHandleForArcSFXInRangeEb = 0x0204E358;
_ZN3SND8Internal12playerExistsEv = 0x0204E3F8;
_ZN3SND8Internal7stopSeqEl = 0x0204E420;
_ZN3SND8Internal8pauseSeqEb = 0x0204E47C;
_ZN3SND8Internal22setTempoRatioForPlayerEPPvl = 0x0204E4D0;
_ZN3SND8Internal13setTempoRatioEl = 0x0204E52C;
_ZN3SND8Internal8startSeqEl = 0x0204E5AC;
_ZN3SND8Internal13stopSFXAndSeqEll = 0x0204E87C;
_ZN3SND8Internal12updateSoundsEv = 0x0204E924;
_ZN3SND8Internal16loadArcForSFXSetEl = 0x0204ECBC;
_ZN3SND8Internal10loadSFXSetEl = 0x0204EDA8;
_ZN3SND8Internal13loadHeapStateEv = 0x0204EE14;
_ZN3SND8Internal22loadHeapStateAndChangeEb = 0x0204EE84;
_ZN3SND8Internal15resetHeapStatesEv = 0x0204EF04;
_ZN3SND8Internal8initSDATEv = 0x0204EF5C;
_ZN3SND8Internal7loadSeqEl = 0x0204F194;
_ZN3SND8Internal17startOutputEffectEPvm = 0x0204F1DC;
_ZN3SND8Internal12initSDAT_DLPEPv = 0x0204F20C;
_ZN3SND8Internal5setupEPvl = 0x0204F2E0;


/*----------------------------------------------------------------*/
/*---------------------------- math ------------------------------*/
/*----------------------------------------------------------------*/

_ZN14SpringFunction24processExponentialSmoothElllll	= 0x0201DA28;
_ZN14SpringFunction13processSpringElb				= 0x0201DA70;
_ZN14SpringFunction6createEllll						= 0x0201DBCC;


/*----------------------------------------------------------------*/
/*---------------------------- vector ----------------------------*/
/*----------------------------------------------------------------*/

_ZN4Vec3C1Ev = 0x02003180;
_ZN4Vec3C2Ev = 0x02003180;
_ZN4Vec3D1Ev = 0x02003080;
_ZN4Vec3D0Ev = 0x02003190;

_ZN4Vec2C1Ev = 0x02003160;
_ZN4Vec2C2Ev = 0x02003160;
_ZN4Vec2D1Ev = 0x020030D8;
_ZN4Vec2D0Ev = 0x020031D0;

_ZN5Vec3sC1Ev = 0x02003170;
_ZN5Vec3sC2Ev = 0x02003170;
_ZN5Vec3sD1Ev = 0x02003070;
_ZN5Vec3sD0Ev = 0x020031B0;

_ZN4Vec310applyRotXZEs = 0x02045760;
_ZN4Vec310applyRotYZEs = 0x02045808;
_ZN4Vec39normalizeEv = 0x020458B0;
_ZN4Vec39normalizeERS_S0_ = 0x02045908;
_ZN4Vec35crossERS_S0_RK7VecFx32S3_ = 0x02045958;
_ZN4Vec35crossERS_RKS_RK7VecFx32 = 0x020459AC;
_ZN4Vec38distanceERKS_RK7VecFx32 = 0x020459FC;
_ZNK4Vec3neERK7VecFx32 = 0x02045A40;
_ZNK4Vec3eqERK7VecFx32 = 0x02045A80;
_ZN4Vec3mLEl =	0x02045ABC;
_ZN4Vec33mulERS_RKS_l = 0x02045B24;
_ZN4Vec33subERS_RKS_RK7VecFx32 = 0x02045B90;
_ZN4Vec33addERS_RKS_RK7VecFx32 = 0x02045BDC;
_ZN4Vec310applyRotXYEs = 0x02045C28;

_ZN4Vec212tryNormalizeEv = 0x02045CD0;
_ZN4Vec29normalizeERS_RKS_ = 0x02045D1C;
_ZN4Vec211crossLengthERKS_RK7VecFx32 = 0x02045D74;
_ZNK4Vec216magnitudeSquaredEv = 0x02045DBC;
_ZN4Vec28distanceERKS_RK7VecFx32 = 0x02045DDC;
_ZNK4Vec26lengthEv = 0x02045E10;
_ZNK4Vec2neERK7VecFx32 = 0x02045E2C;
_ZNK4Vec2eqERK7VecFx32 = 0x02045E5C;
_ZN4Vec23divERS_RKS_l = 0x02045E88;
_ZN4Vec2mLEl = 0x02045F14;
_ZN4Vec23mulERS_RKS_l = 0x02045F60;
_ZN4Vec23subERS_RKS_RK7VecFx32 = 0x02045FB8;
_ZN4Vec23addERS_RKS_RK7VecFx32 = 0x02045FF4;

_ZTV4Vec3 = 0x02039200;
_ZTV4Vec2 = 0x020391E0;
_ZTV5Vec3s = 0x020391F0;


/*----------------------------------------------------------------*/
/*---------------------------- math ------------------------------*/
/*----------------------------------------------------------------*/

_ZN4Math4lerpER4Vec3RKS0_l = 0x02043e30;
_ZN4Math8lerpFx32ERllll = 0x020437a4;
_ZN4Math8lerpFx32ERlllll = 0x020437f4;
_ZN4Math4lerpER4Vec2RKS0_l = 0x02043d5c;
_ZN4Math6sqrt64Emm = 0x02046030;
_ZN4Math5atan2Ell = 0x02043b6c;
_ZN4Math7inRangeElll = 0x02043750;
_ZN4Math8distanceEss = 0x02043790;

_ZN4Math10atan2TableE = 0x020848e4;
_ZN4Math13unusedCounterE = 0x0208b66c;
_ZN4Math12frameCounterE = 0x0208b668;


/*----------------------------------------------------------------*/
/*---------------------------- save ------------------------------*/
/*----------------------------------------------------------------*/

_ZN4Save11setupBackupE14CARDBackupTypePKc = 0x0204C7F4;
_ZN4Save10readBackupEPvmm = 0x0204C114;
_ZN4Save11writeBackupEPvmm = 0x0204C568;
_ZN4Save12writeMGScoreEmmm = 0x02012788;
_ZN4Save11readMGScoreEmm = 0x02012824;
_ZN4Save11writeMGSaveEP12MinigameSave = 0x0201289C;
_ZN4Save10readMGSaveEP12MinigameSave = 0x020128C4;
_ZN4Save11clearMGSaveEP12MinigameSave = 0x020128D8;
_ZN4Save12createMGSaveEv = 0x020128FC;
_ZN4Save18getWorldmapSceneIDEv = 0x02012934;
_ZN4Save27disableCurrentWorldmapActorEN8MainSave13WorldmapActor4TypeE = 0x0201293C;
_ZN4Save15animationPlayedEv = 0x020129B0;
_ZN4Save17getStarCoinAmountEv = 0x02012A20;
_ZN4Save19isStarCoinCollectedEm = 0x02012A3C;
_ZN4Save24getCurrentLevelStarCoinsEv = 0x02012A58;
_ZN4Save17getLevelStarCoinsEmh = 0x02012A78;
_ZN4Save17setLevelStarCoinsEmhh = 0x02012A98;
/*02012ABC*/
_ZN4Save10onGameOverEmP8MainSave = 0x02012D6C;
_ZN4Save15onStoryFinishedEmP8MainSave = 0x02012D70;
_ZN4Save9writeSaveEmP8MainSave = 0x02012D98;
_ZN4Save14loadPlayerDataEv = 0x02012DA4;
_ZN4Save12loadMainSaveEmmP8MainSave = 0x02012E08;
_ZN4Save14createMainSaveEmP8MainSave = 0x02012EE0;
_ZN4Save13writeMainSaveEmP8MainSave = 0x02012F24;
_ZN4Save12readMainSaveEmP8MainSave = 0x02012F64;
_ZN4Save13clearMainSaveEP8MainSave = 0x02012F9C;
_ZN4Save16createOptionSaveEP10OptionSave = 0x02012FF0;
_ZN4Save15writeOptionSaveEP10OptionSave = 0x0201301C;
_ZN4Save14readOptionSaveEP10OptionSave = 0x02013050;
_ZN4Save15clearOptionSaveEP10OptionSave = 0x02013064;
_ZN4Save18generateOptionSaveEv = 0x02013090;
_ZN4Save10resetSavesEv = 0x020130B4;
_ZN4Save15clearLoadedSaveEv = 0x02013100;

_ZN4Save10optionSaveE = 0x02088f18;
_ZN4Save8mainSaveE = 0x02088bdc;


/*----------------------------------------------------------------*/
/*----------------------------- oam ------------------------------*/
/*----------------------------------------------------------------*/

_ZN3OAM14unused_2087708E = 0x02087708;
_ZN3OAM8_2087710E = 0x02087710;
_ZN3OAM8_208770CE = 0x0208770C;
_ZN3OAM8_20876FCE = 0x020876FC;
_ZN3OAM13curTileOffsetE = 0x02087700;
_ZN3OAM10objBuffer1E = 0x020877E0;
_ZN3OAM10objBuffer2E = 0x02087BE0;
_ZN3OAM12affineBufferE = 0x02087760;
_ZN3OAM12objsFromHeadE = 0x020876F4;
_ZN3OAM12objsFromTailE = 0x020876E8;
_ZN3OAM12objSlotsLeftE = 0x020876E4;
_ZN3OAM13affineSetSlotE = 0x02087704;
_ZN3OAM13objBuffer1SubE = 0x02087FE0;
_ZN3OAM13objBuffer2SubE = 0x020883E0;
_ZN3OAM15affineBufferSubE = 0x020877A0;
_ZN3OAM15objsFromHeadSubE = 0x020876F0;
_ZN3OAM15objsFromTailSubE = 0x020876E0;
_ZN3OAM15objSlotsLeftSubE = 0x020876EC;
_ZN3OAM16affineSetSlotSubE = 0x020876F8;

_ZN3OAM13updateCounterEPK9GXOamAttrPPS0_llNS_12CounterFlagsE = 0x0200B580;
_ZN3OAM9loadFilesEPNS_4FileE = 0x0200B708;
_ZN3OAM9loadFilesEm = 0x0200B740;
_ZN3OAM9setupFileEPNS_4FileEm = 0x0200B758;
_ZN3OAM15loadFilesToVRAMEPNS_4FileE = 0x0200B7D0;
_ZN3OAM15loadFilesToVRAMEm = 0x0200B83C;
_ZN3OAM16setFilesUnloadedEv = 0x0200B87C;
_ZN3OAM7copyMtxEP7MtxFx22S1_ = 0x0200B8A4;
_ZN3OAM8fillDataEttP9GXOamAttrm = 0x0200B358;
_ZN3OAM4drawEPK9GXOamAttrllNS_5FlagsEhhNS_8SettingsE = 0x0200D2A4;
_ZN3OAM4drawEPK9GXOamAttrllNS_5FlagsEhhPK4Vec2sPKsNS_8SettingsE = 0x0200D87C;
_ZN3OAM7drawMtxEPK9GXOamAttrllNS_5FlagsEhhPK7MtxFx22lNS_8SettingsE = 0x0200CE10;
_ZN3OAM7drawMtxEPK9GXOamAttrllNS_5FlagsEhhPK7MtxFx22lsPKsNS_8SettingsE = 0x0200C7D4;
_ZN3OAM10drawSpriteEPK9GXOamAttrllNS_5FlagsEhhPK4Vec2sPKsNS_8SettingsE = 0x0200D578;
_ZN3OAM7drawSubEPK9GXOamAttrllNS_5FlagsEhhNS_8SettingsE = 0x0200C32C;
_ZN3OAM7drawSubEPK9GXOamAttrllNS_5FlagsEhhPK4Vec2sPKsNS_8SettingsE = 0x0200C600;
_ZN3OAM10drawMtxSubEPK9GXOamAttrllNS_5FlagsEhhPK7MtxFx22NS_8SettingsE = 0x0200BED4;
_ZN3OAM10drawMtxSubEPK9GXOamAttrllNS_5FlagsEhhPK7MtxFx22sPKsNS_8SettingsE = 0x0200B8C8;
_ZN3OAM4Anim4initEPKNS0_10FrameEntryEmhlt = 0x0200B510;
_ZN3OAM4Anim6updateEv = 0x0200B44C;
_ZN3OAM4Anim10drawSpriteEllmhhP4Vec2sPsm = 0x0200B3F4;
_ZN3OAM4Anim7drawSubEllmhhP4Vec2sPsm = 0x0200B39C;


/*----------------------------------------------------------------*/
/*--------------------------- particle ---------------------------*/
/*----------------------------------------------------------------*/

_ZN8Particle7Emitter5startEmmPK7VecFx32PK7VecFx16PKlPKsPNS_14ControllerBaseE								= 0x02021c10;
_ZN8Particle7Emitter3endEv																					= 0x02021bf0;

_ZN8Particle13EmitterSystemC2Ev																				= 0x02021bac;

_ZN8Particle13EmitterSystem18destroyAllEmittersEv															= 0x02021ae8;
_ZN8Particle13EmitterSystem21unregisterAllEmittersEv														= 0x02021a88;
_ZN8Particle13EmitterSystem10getEmitterEm																	= 0x02021a48;
_ZN8Particle13EmitterSystem12startEmitterEmPK7VecFx32PK7VecFx16PKlPKsPNS_14ControllerBaseE					= 0x0202194c;
_ZN8Particle13EmitterSystem15registerEmitterEPNS_7EmitterE													= 0x02021920;
_ZN8Particle13EmitterSystem17unregisterEmitterEPNS_7EmitterE												= 0x020218e0;

_ZN8Particle14ControllerBase5spawnEP10SPLEmitter															= 0x02021f08;
_ZN8Particle14ControllerBase7destroyEP10SPLEmitterb															= 0x02021f00;

_ZN8Particle10ControllerC2Ev																				= 0x02021eb8;
_ZN8Particle10Controller5spawnEP10SPLEmitter																= 0x02021e8c;
_ZN8Particle10Controller7destroyEP10SPLEmitterb																= 0x02021e7c;

_ZN8Particle16ControllerLiquid7destroyEP10SPLEmitterb														= 0x02021e00;

_ZN8Particle22ControllerManualLiquid7destroyEP10SPLEmitterb													= 0x02021d78;

_ZN8Particle16ControllerManual7destroyEP10SPLEmitterb														= 0x02021d20;
_ZN8Particle16ControllerManual20getHandlerControllerEv														= 0x02021cfc;

_ZN8Particle7HandlerC2Ev																					= 0x02023180;
_ZN8Particle7HandlerD2Ev																					= 0x02023118;
_ZN8Particle7HandlerD1Ev																					= 0x02023118;
_ZN8Particle7HandlerD0Ev																					= 0x020230a8;

_ZN8Particle7Handler8allocateEm																				= 0x0202308c;
_ZN8Particle7Handler4initEm																					= 0x02022dd0;
_ZN8Particle7Handler19getBossParticleInfoEm																	= 0x02022d98;
_ZN8Particle7Handler21getBossParticleFileIDEm																= 0x02022d68;
_ZN8Particle7Handler8initBossEv																				= 0x02022cb4;
_ZN8Particle7Handler15updateParticlesEv																		= 0x02022c3c;
_ZN8Particle7Handler15renderParticlesEv																		= 0x02022be4;
_ZN8Particle7Handler14createParticleEmRK4Vec3																= 0x02022b64;
_ZN8Particle7Handler16createParticleExEmRK4Vec3PvPFvP10SPLEmitterzE											= 0x02022aac;
_ZN8Particle7Handler15setAxisCallbackEP10SPLEmitterRK7VecFx16												= 0x02022a90;
_ZN8Particle7Handler18createParticleAxisEmRK4Vec3RK7VecFx16													= 0x02022a7c;
_ZN8Particle7Handler27setSimpleCollisionYCallbackEP10SPLEmitterRKl											= 0x02022a70;
_ZN8Particle7Handler17setRadiusCallbackEP10SPLEmitterRKl													= 0x02022a64;
_ZN8Particle7Handler20createParticleRadiusEmRK4Vec3RKl														= 0x02022a50;
_ZN8Particle7Handler23setParticleLifeCallbackEP10SPLEmitterRKt												= 0x02022a44;
_ZN8Particle7Handler18createParticleLifeEmRK4Vec3RKt														= 0x02022a30;
_ZN8Particle7Handler13getSPLEmitterEm																		= 0x02022a04;
_ZN8Particle7Handler10runEmitterEmmRK4Vec3RK7VecFx16RKlRKsPNS_14ControllerBaseE								= 0x02022890;
_ZN8Particle7Handler14runEmitterBossEmmRK4Vec3RK7VecFx16RKlRKsPNS_14ControllerBaseE							= 0x02022824;
_ZN8Particle7Handler22runEmitterManualLiquidEmmlllRK7VecFx16												= 0x020227bc;
_ZN8Particle7Handler16runEmitterManualEmmlllRK7VecFx16														= 0x02022754;
_ZN8Particle7Handler15createSmokePuffElll																	= 0x020226e4;
_ZN8Particle7Handler15createRockSmokeElll																	= 0x02022674;
_ZN8Particle7Handler18createBigRockSmokeElll																= 0x020226fc;
_ZN8Particle7Handler19createRockExplosionElll																= 0x02022528;
_ZN8Particle7Handler22createBigRockExplosionElll															= 0x0202245c;
_ZN8Particle7Handler17createLittleSmokeElll																	= 0x020223e4;
_ZN8Particle7Handler22createLittleWhiteSmokeElll															= 0x02022364;
_ZN8Particle7Handler18createGlitterStarsElll																= 0x020222ec;
_ZN8Particle7Handler13createBubblesElll																		= 0x02022274;
_ZN8Particle7Handler18createBigSmokePuffERK4Vec3															= 0x02022244;
_ZN8Particle7Handler15createSmokePuffERK4Vec3																= 0x02022220;
_ZN8Particle7Handler20createWaterParticlesERK4Vec3															= 0x020221fc;
_ZN8Particle7Handler19createLavaParticlesERK4Vec3															= 0x020221d8;
_ZN8Particle7Handler28createPoisonedWaterParticlesERK4Vec3													= 0x020221b4;
_ZN8Particle7Handler18createParticleBossEmRK4Vec3															= 0x02022134;
_ZN8Particle7Handler34createParticleBossSimpleCollisionYEmRK4Vec3RKl										= 0x020220d8;
_ZN8Particle7Handler17getSPLEmitterSafeEm																	= 0x020220a4;
_ZN8Particle7Handler21stopEmitterGenerationEm																= 0x02022074;
_ZN8Particle7Handler25stopEmitterGenerationBossEm															= 0x02022020;
_ZN8Particle7Handler24setEmitterGenerationRateEmm															= 0x02022008;
_ZN8Particle7Handler22setEmitterParticleLifeEmt																= 0x02021ff0;
_ZN8Particle7Handler29runEmitterInitialVelocityAxisEmmRK4Vec3RK7VecFx16RKlRKsSA_PNS_14ControllerBaseE		= 0x02021f7c;
_ZN8Particle7Handler23setPolygonAttributeBossEm																= 0x02021f58;
_ZN8Particle7Handler25resetPolygonAttributeBossEm															= 0x02021f30;
_ZN8Particle7Handler7disableEv																				= 0x02021f0c;

_ZN8Particle7Handler17bParticlesEnabledE																	= 0x203cf80;

_ZN8Particle7Handler16nMaxSPLParticlesE																		= 0x208b4f8;
_ZN8Particle7Handler20nMaxSPLParticlesBossE																	= 0x208b4fc;
_ZN8Particle7Handler15nMaxSPLEmittersE																		= 0x208b500;
_ZN8Particle7Handler19nMaxSPLEmittersBossE																	= 0x208b504;
_ZN8Particle7Handler18nMaxSystemEmittersE																	= 0x208b508;

_ZN8Particle7Handler16pParticleHeapBegE																		= 0x208b50C;
_ZN8Particle7Handler16pParticleHeapCurE																		= 0x208b510;
_ZN8Particle7Handler16pParticleHeapEndE																		= 0x208b514;

_ZN8Particle7Handler13pMiniGamesSPAE																		= 0x208b518;
_ZN8Particle7Handler14pCurSPLManagerE																		= 0x208b51c;
_ZN8Particle7Handler8pHandlerE																				= 0x208b520;
_ZN8Particle7Handler12pMainGameSPAE																			= 0x208b524;

_ZTVN8Particle14ControllerBaseE																				= 0x0203cfd4;
_ZTVN8Particle10ControllerE																					= 0x0203cfb4;
_ZTVN8Particle16ControllerLiquidE																			= 0x0203cfc4;
_ZTVN8Particle22ControllerManualLiquidE																		= 0x0203cfa4;
_ZTVN8Particle16ControllerManualE																			= 0x0203cf94;
_ZTVN8Particle7HandlerE																						= 0x0203cf84;


/*----------------------------------------------------------------*/
/*------------------------- blend color --------------------------*/
/*----------------------------------------------------------------*/

_ZN10BlendColorC1Ev						= 0x020e91a0;
_ZN10BlendColorC2Ev						= 0x020e91a0;
_ZN10BlendColorD0Ev						= 0x020e9170;
_ZN10BlendColorD1Ev						= 0x020e9190;
_ZN10BlendColorD2Ev						= 0x020e9190;
_ZN10BlendColor12blendChannelERttt		= 0x020e9120;
_ZN10BlendColor5blendEtm				= 0x020e9018;


/*----------------------------------------------------------------*/
/*----------------------------- list -----------------------------*/
/*----------------------------------------------------------------*/

_ZN11ProcessNode6unlinkEv					= 0x0204d57c;

_ZN12PriorityNode6unlinkEv					= 0x0204d560;

_ZN9SceneNodeC2Ev							= 0x02043b58;
_ZN9SceneNode5resetEv						= 0x02043b40;
_ZN9SceneNode7getNextEv						= 0x02043a2c;
_ZN9SceneNode13getParentNextEv				= 0x020439f0;

_ZN10LinkedList6appendEP11ProcessNode		= 0x020438e8;
_ZN10LinkedList6removeEP11ProcessNode		= 0x02043920;
_ZN10LinkedList7prependEP11ProcessNode		= 0x020438b0;
_ZN10LinkedList6insertEP11ProcessNodeS1_	= 0x02043990;
_ZN10LinkedList11getNodeByIDEm				= 0x0204d428;

_ZN11ProcessList7executeEv					= 0x0204d46c;

_ZN10ProcessSet3addEP12PriorityNode			= 0x0204d4e4;

_ZN10SceneGraph8addChildEP9SceneNodeS1_		= 0x02043acc;
_ZN10SceneGraph11removeChildEP9SceneNode	= 0x02043a54;


/*----------------------------------------------------------------*/
/*--------------------------- process ----------------------------*/
/*----------------------------------------------------------------*/

_ZN14ProcessManager18updateProcessListsEv									= 0x0204d598;
_ZN14ProcessManager19getNextObjectByTypeE10ObjectTypeP4Base					= 0x0204d630;
_ZN14ProcessManager23getNextObjectByObjectIDEtP4Base						= 0x0204d66c;
_ZN14ProcessManager13getObjectByIDEm										= 0x0204d6a8;
_ZN14ProcessManager10getIDIndexEP11ProcessLink								= 0x0204d6dc;
_ZN14ProcessManager18getProcessListNameE15ProcessListType					= 0x0204d6ec;
_ZN14ProcessManager17getNextNodeByTypeEP10SceneGraph10ObjectTypeP9SceneNode	= 0x0204d6fc;
_ZN14ProcessManager21getNextNodeByObjectIDEP10SceneGraphtP9SceneNode		= 0x0204d758;


/*----------------------------------------------------------------*/
/*----------------------------- base -----------------------------*/
/*----------------------------------------------------------------*/

_ZN4BaseC2Ev											= 0x0204d2ac;
_ZN4Base13processCreateEv								= 0x0204cba0;
_ZN4Base13processUpdateEv								= 0x01ffd22c;
_ZN4Base13processRenderEv								= 0x01ffd1c8;
_ZN4Base14processDestroyEv								= 0x0204cb20;
_ZN4Base7processEMS_FlvEMS_FbvEMS_FvNS_11ReturnStateEE	= 0x01ffd524;
_ZN4Base8onCreateEv										= 0x0204d234;
_ZN4Base9preCreateEv									= 0x0204d22c;
_ZN4Base10postCreateE15BaseReturnState					= 0x0204d1b8;
_ZN4Base9onDestroyEv									= 0x0204d1b0;
_ZN4Base10preDestroyEv									= 0x0204d174;
_ZN4Base11postDestroyE15BaseReturnState					= 0x0204d0e0;
_ZN4Base8onUpdateEv										= 0x01ffd51c;
_ZN4Base9preUpdateEv									= 0x01ffd4f4;
_ZN4Base10postUpdateE15BaseReturnState					= 0x01ffd4f0;
_ZN4Base8onRenderEv										= 0x01ffd4e8;
_ZN4Base9preRenderEv									= 0x01ffd4c0;
_ZN4Base10postRenderE15BaseReturnState					= 0x01ffd4bc;
_ZN4Base14pendingDestroyEv								= 0x0204d0dc;
_ZN4Base16createUserHeapExEmP4Heap						= 0x0204cdbc;
_ZN4Base14createUserHeapEmP4Heap						= 0x0204ccec;
_ZN4Base17onUserHeapCreatedEv							= 0x0204cce4;
_ZN4Base6createEv										= 0x0204cc04;
_ZN4Base7destroyEv										= 0x0204d08c;
_ZN4Base18hasChildNotCreatedEv							= 0x0204cac0;
_ZN4BaseD2Ev											= 0x0204d23c;
_ZN4BaseD1Ev											= 0x00000000; /* TODO */
_ZN4BaseD0Ev											= 0x0204d270;
_ZN4Base9getParentEv									= 0x0204d078;
_ZN4BasenwEj											= 0x0204cc98;
_ZN4BasedlEPv											= 0x0204cc7c;
_ZN4Base14setSpawnParamsEtP9SceneNodemNS_10ObjectTypeE	= 0x0204ca80;
_ZN4Base16loadSceneOverlayEt							= 0x0204c974;
_ZN4Base18unloadSceneOverlayEt							= 0x0204c948;
_ZN4Base5spawnEtP9SceneNodemNS_10ObjectTypeE			= 0x0204c9a4;
_ZN4Base10spawnChildEtPS_mNS_10ObjectTypeE				= 0x0204c920;
_ZN4Base11spawnParentEtmNS_10ObjectTypeE				= 0x0204c908;

_ZN4Base16debugProfileStepE								= 0x0208fae8;
_ZN4Base15spawnObjectTypeE								= 0x0208faec;
_ZN4Base13debugObjectIDE								= 0x0208faf0;
_ZN4Base13spawnObjectIDE								= 0x0208faf4;
_ZN4Base15spawnParentNodeE								= 0x0208faf8;
_ZN4Base11loadOverlayE									= 0x0208fafc;
_ZN4Base13unloadOverlayE								= 0x0208fb00;
_ZN4Base13spawnSettingsE								= 0x0208fb04;

_ZTV4Base												= 0x02085258;


/*----------------------------------------------------------------*/
/*--------------------------- object -----------------------------*/
/*----------------------------------------------------------------*/

_ZN6ObjectD0Ev										= 0x0201313c;
_ZN6ObjectD1Ev										= 0x0201311c;
_ZN6ObjectD2Ev										= 0x0201311c;
_ZN6Object10postCreateE15BaseReturnState			= 0x020131a8;

_ZN6Object10spawnSceneEtm10ObjectType				= 0x02013168;
_ZN6Object11spawnObjectEtP4Basem10ObjectType		= 0x02013188;

_ZTV6Object											= 0x0203bcd8;

/*----------------------------------------------------------------*/
/*---------------------------- scene -----------------------------*/
/*----------------------------------------------------------------*/

_ZN5SceneC2Ev									= 0x02013b2c;
_ZN5SceneD0Ev									= 0x020138dc;
_ZN5SceneD1Ev									= 0x02013a08;
_ZN5SceneD2Ev									= 0x020137b8;
_ZN5Scene9preCreateEv							= 0x02013764;
_ZN5Scene10postCreateE15BaseReturnState			= 0x02013718;
_ZN5Scene10preDestroyEv							= 0x020136e8;
_ZN5Scene11postDestroyE15BaseReturnState		= 0x020136c8;
_ZN5Scene9preUpdateEv							= 0x02013500;
_ZN5Scene10postUpdateE15BaseReturnState			= 0x020134f4;
_ZN5Scene9preRenderEv							= 0x020134c4;
_ZN5Scene10postRenderE15BaseReturnState			= 0x020134b8;
_ZN5Scene17prepareFirstSceneEv					= 0x020133a4;
_ZN5Scene14tryChangeSceneEv						= 0x020132a0;
_ZN5Scene11switchSceneEtm						= 0x020131fc;
_ZN5Scene26switchToFileCorruptedSceneEm			= 0x020131d8;

_ZN5Scene13isSceneActiveE						= 0x0203bd28;
_ZN5Scene15previousSceneIDE						= 0x0203bd2c;
_ZN5Scene11nextSceneIDE							= 0x0203bd30;
_ZN5Scene14currentSceneIDE						= 0x0203bd34;
_ZN5Scene17nextSceneSettingsE					= 0x02088f38;

_ZTV5Scene										= 0x0203bd38;


/*----------------------------------------------------------------*/
/*---------------------------- actor -----------------------------*/
/*----------------------------------------------------------------*/

_ZN5ActorC2Ev									= 0x020a0edc;
_ZN5ActorD0Ev									= 0x020a0e04;
_ZN5ActorD1Ev									= 0x020a0e74;
_ZN5ActorD2Ev									= 0x020a0d9c;
_ZN5Actor9preCreateEv							= 0x020a0d7c;
_ZN5Actor10postCreateE15BaseReturnState			= 0x020a0d70;
_ZN5Actor10preDestroyEv							= 0x020a0d50;
_ZN5Actor11postDestroyE15BaseReturnState		= 0x020a0d44;
_ZN5Actor9preUpdateEv							= 0x020a0cac;
_ZN5Actor10postUpdateE15BaseReturnState			= 0x020a0ca0;
_ZN5Actor9preRenderEv							= 0x020a0c48;
_ZN5Actor10postRenderE15BaseReturnState			= 0x020a0c3c;
_ZN5Actor4setXEl								= 0x0201ff68;
_ZN5Actor5moveXEl								= 0x0201ff70;
_ZN5Actor13getActorCountEt						= 0x020a0bf8;
_ZN5Actor14setSpawnParamsEPK4Vec3PK5Vec3sPKlPKa	= 0x020a0bb8;
_ZN5Actor10spawnActorEtmPK4Vec3PK5Vec3sPKlPKa	= 0x020a0b64;
_ZN5Actor10linkPlayerEa							= 0x020a0b5c;
_ZNK5Actor17applyAccelerationERK4Vec3			= 0x020a0acc;
_ZN5Actor23applyVelocityToPositionERK4Vec3		= 0x020a0aac;
_ZN5Actor13applyVelocityEv						= 0x020a0a70;
_ZN5Actor24applyDirectionalVelocityEt			= 0x020a09ac;
_ZN5Actor24setDirectionalVelocity3DEv			= 0x020a0908;
_ZN5Actor24updateHorizontalVelocityEv			= 0x020a08c4;
_ZN5Actor22updateVerticalVelocityEv				= 0x020a08a4;
_ZN5Actor29updateVerticalVelocityClampedEv		= 0x020a085c;
_ZN5Actor31updateHorizontalVelocityClampedEv	= 0x020a0814;
_ZN5Actor21updateVelocityClampedEv				= 0x020a07f4;
_ZN5Actor26applyDirectionalVelocity3DEv			= 0x020a07dc;
_ZN5Actor21attenuateAccelerationEv				= 0x020a0774;
_ZNK5Actor19getCenteredPositionEv				= 0x020a0728;

_ZN5Actor13spawnPositionE						= 0x020ca85c;
_ZN5Actor13spawnRotationE						= 0x020ca860;
_ZN5Actor15spawnPlayerLinkE						= 0x020ca864;
_ZN5Actor10spawnScaleE							= 0x020ca868;

_ZTV5Actor										= 0x020c6c2c;


/*----------------------------------------------------------------*/
/*------------------------- stage actor --------------------------*/
/*----------------------------------------------------------------*/

_ZN10StageActorC2Ev									= 0x020a127c;
_ZN10StageActorD2Ev									= 0x020a11a8;
_ZN10StageActorD1Ev									= 0x020a1238;
_ZN10StageActorD0Ev									= 0x020a11ec;
_ZN10StageActor9preUpdateEv							= 0x020a1154;
_ZN10StageActor10postUpdateEN4Base11ReturnStateE	= 0x020a10f0;
_ZNK10StageActor14isInActiveViewEv					= 0x020a10a0;
_ZNK10StageActor19isOutOfViewVerticalEv				= 0x020a06dc;
_ZNK10StageActor19getDistanceToPlayerEPlS0_			= 0x020a069c;
_ZN10StageActor26calcDistanceToPlayerNoWrapEmmPlS0_	= 0x020a05f8;
_ZN10StageActor24calcDistanceToPlayerWrapEmmPlS0_	= 0x020a0500;
_ZN10StageActor31setCalcDistanceToPlayerFunctionEm	= 0x020a04e4;
_ZN10StageActor12wrapPositionER4Vec3R5Vec3sb		= 0x020a04c0;
_ZN10StageActor23setWrapPositionFunctionEm			= 0x020a04b4;
_ZNK10StageActor14isBehindTargetERKS_				= 0x020a047c;
_ZNK10StageActor17isInFrontOfTargetERKS_			= 0x020a0444;
_ZN10StageActor20isBehindTargetNoWrapEll			= 0x020a0434;
_ZN10StageActor18isBehindTargetWrapEll				= 0x020a03e8;
_ZN10StageActor25setIsBehindTargetFunctionEm		= 0x020a03cc;
_ZN10StageActor17initWrapFunctionsEm				= 0x020a03ac;

_ZTV10StageActor									= 0x020c6c84;


/*----------------------------------------------------------------*/
/*------------------------- stage entity -------------------------*/
/*----------------------------------------------------------------*/

_ZN11StageEntityC2Ev												= 0x0209dee0;
_ZN11StageEntityD1Ev												= 0x020986e0;
_ZN11StageEntityD0Ev												= 0x02098730;
_ZN11StageEntity8onUpdateEv											= 0x0209ef98;
_ZN11StageEntity9preUpdateEv										= 0x0209dab8;
_ZN11StageEntity10postUpdateE15BaseReturnState						= 0x0209da90;
_ZN11StageEntity9preRenderEv										= 0x0209da58;
_ZN11StageEntity10assignViewERK4Vec3								= 0x020988f0;
_ZNK11StageEntity14isPlayerInZoneERK6Playerm						= 0x02098908;
_ZN11StageEntity20damagePlayerCallbackER14ActiveColliderS1_			= 0x02098c78;
_ZN11StageEntity13isBelowCameraElR14ActiveColliderh					= 0x02098dd8;
_ZN11StageEntity23setGroundPoundCollisionERK6Player					= 0x02098e08;
_ZNK11StageEntity13checkSquishedEv									= 0x02098fbc;
_ZN11StageEntity17updateSideSensorsEv								= 0x02099040;
_ZN11StageEntity18updateBottomSensorEv								= 0x020990d4;
_ZNK11StageEntity18checkLavaCollisionEv								= 0x0209917c;
_ZN11StageEntity22updateCollisionSensorsEv							= 0x020991f8;
_ZNK11StageEntity20checkPlayersInOffsetEll							= 0x02099250;
_ZNK11StageEntity20checkPlayersInOffsetEl							= 0x02099354;
_ZN11StageEntity14rotateToTargetEPsS0_								= 0x020993ec;
_ZN11StageEntity19applyFireballWiggleEv								= 0x02099440;
_ZN11StageEntity10getActorIDEt										= 0x02099590;
_ZN11StageEntity13setTimedEventEmlbbb								= 0x020995a4;
_ZN11StageEntity7destroyEb											= 0x02099884;
_ZN11StageEntity12updateBounceElll									= 0x020998e4;
_ZN11StageEntity20damageEntityCallbackER14ActiveColliderS1_			= 0x0209997c;
_ZN11StageEntity13shellCallbackER14ActiveColliderS1_				= 0x02099b6c;
_ZN11StageEntity20simplePlayerCallbackER14ActiveColliderS1_			= 0x02099fb4;
_ZN11StageEntity9getRandomEv										= 0x0209a0e8;
_ZN11StageEntity22tryAttachToPlayerHandsElll						= 0x0209a0f4;
_ZN11StageEntity19attachToPlayerHandsElll							= 0x0209a144;
_ZN11StageEntity25updateSolidActiveColliderEmmh						= 0x0209a23c;
_ZN11StageEntity13onPlayerStompER6Playerlb							= 0x0209a5bc;
_ZN11StageEntity17updatePlayerStompER14ActiveColliderlmb			= 0x0209a80c;
_ZNK11StageEntity18getScorePointsSetBEmlll							= 0x0209a938;
_ZN11StageEntity18getScorePointsSetBERK4Vec3ml						= 0x0209a990;
_ZNK11StageEntity18getScorePointsSetCEmlll							= 0x0209aa04;
_ZN11StageEntity18getScorePointsSetCERK4Vec3ml						= 0x0209aa5c;
_ZN11StageEntity18spawnRedCoinNumberERK4Vec3ml						= 0x0209aad0;
_ZN11StageEntity20getCollectablePointsEml							= 0x0209ab04;
_ZNK11StageEntity18getScorePointsSetAEmlll							= 0x0209ab90;
_ZN11StageEntity18getScorePointsSetAERK4Vec3ml						= 0x0209ac0c;
_ZNK11StageEntity28getVerticalDirectionToPlayerERK4Vec3				= 0x0209ac8c;
_ZNK11StageEntity30getHorizontalDirectionToPlayerERK4Vec3			= 0x0209acd4;
_ZN11StageEntity15destroyInactiveEm									= 0x0209adb0;
_ZN11StageEntity11isOutOfViewERK4Vec3RK6FxRecth						= 0x0209ae88;
_ZN11StageEntity20checkLiquidCollisionERK4Vec3S2_lb					= 0x0209c590;
_ZN11StageEntity19updateLiquidPhysicsERK4Vec3l						= 0x0209c6d4;
_ZN11StageEntity21updateLiquidCollisionERK4Vec3l					= 0x0209c7a0;
_ZN11StageEntity13updateLiquidsEl									= 0x0209c820;
_ZN11StageEntity13applyMovementEv									= 0x0209c85c;
_ZN11StageEntity21setBlueShellCollisionERK6Player					= 0x0209ccd0;
_ZN11StageEntity17setStompCollisionERK6Player						= 0x0209cfc4;
_ZN11StageEntity16setMegaCollisionERK6Player						= 0x0209d3d0;
_ZN11StageEntity9spawnCoinEv										= 0x0209d694;
_ZN11StageEntity19setSlidingCollisionERK6Player						= 0x0209d774;
_ZN11StageEntity19setStarmanCollisionERK6Player						= 0x0209d7e0;
_ZN11StageEntity7tryGrabER6Player									= 0x020a0048;
_ZN11StageEntity12fenceTurningEv									= 0x020a01b4;
_ZN11StageEntity10updateMainEv										= 0x020a03a4;
_ZN11StageEntity10skipRenderEv										= 0x0209ad1c;
_ZN11StageEntity12updateState1Ev									= 0x020a039c;
_ZN11StageEntity14updateDefeatedEv									= 0x020a0304;
_ZN11StageEntity18updateDefeatedMegaEv								= 0x020a0274;
_ZN11StageEntity12updateState4Ev									= 0x020a01ac;
_ZN11StageEntity13updateGrabbedEv									= 0x0209fb3c;
_ZN11StageEntity12updateState6Ev									= 0x0209fa8c;
_ZN11StageEntity12updateState7Ev									= 0x0209f824;
_ZN11StageEntity12updateState8Ev									= 0x0209f6c4;
_ZN11StageEntity12updateState9Ev									= 0x0209f0e4;
_ZN11StageEntity15updateAnimationEv									= 0x0209d9fc;
_ZN11StageEntity6thrownEv											= 0x0209faf4;
_ZN11StageEntity7stoppedEv											= 0x0209faac;
_ZN11StageEntity6virt34Ev											= 0x0209c974;
_ZN11StageEntity7grabbedEv											= 0x020a012c;
_ZN11StageEntity7releaseEv											= 0x020a00ac;
_ZN11StageEntity6virt37ER6Player									= 0x0209f574;
_ZN11StageEntity6virt38Ev											= 0x0209f3d8;
_ZN11StageEntity6virt39Ev											= 0x0209f354;
_ZN11StageEntity20updateFireballWiggleEv							= 0x020994f8;
_ZN11StageEntity10onBlockHitEv										= 0x0209d988;
_ZN11StageEntity11onEntityHitEv										= 0x0209d920;
_ZN11StageEntity13onFireballHitEv									= 0x0209d84c;
_ZN11StageEntity12onStarmanHitEv									= 0x0209d568;
_ZN11StageEntity12onSlidingHitEv									= 0x0209d43c;
_ZN11StageEntity9onMegaHitEv										= 0x0209d2a0;
_ZN11StageEntity12onMegaKickedEv									= 0x0209d158;
_ZN11StageEntity14onSpinDrillHitEv									= 0x0209d014;
_ZN11StageEntity9onStompedEv										= 0x0209cfc0;
_ZN11StageEntity13onGroundPoundEv									= 0x0209ce08;
_ZN11StageEntity14onBlueShellHitEv									= 0x0209cbf8;
_ZN11StageEntity14onFenceSlamHitEv									= 0x0209cad0;
_ZN11StageEntity17onMegaGroundPoundEv								= 0x02098f7c;
_ZN11StageEntity13onStageBeatenER6Player							= 0x02098e7c;
_ZN11StageEntity13onFatalDamageEv									= 0x0209cd3c;
_ZN11StageEntity19onMegaWalkShockwaveEv								= 0x0209cac4;
_ZN11StageEntity26onMegaGroundPoundShockwaveEv						= 0x0209cac0;
_ZN11StageEntity12stopMovementEv									= 0x02099168;
_ZN11StageEntity15playerCollisionER14ActiveColliderS1_				= 0x02098a94;
_ZN11StageEntity15entityCollisionER14ActiveColliderR10StageActor	= 0x02098a90;
_ZN11StageEntity12damagePlayerER14ActiveColliderR6Player			= 0x02098a10;
_ZN11StageEntity6defeatElllh										= 0x0209c9d0;
_ZN11StageEntity10defeatMegaElll									= 0x0209c994;
_ZN11StageEntity21fenceDisableCollisionEv							= 0x020a0268;
_ZN11StageEntity20fenceSwitchDirectionEv							= 0x020a0240;
_ZN11StageEntity12doPlayerJumpER6Playerl							= 0x0209a6d4;

_ZN11StageEntity9layerFlagE											= 0x020c4ec0;
_ZN11StageEntity13unitDirectionE									= 0x020c4ec4;
_ZN11StageEntity20directionalRotationYE								= 0x020c4ec8;
_ZN11StageEntity28directionalRotationYVelocityE						= 0x020c4ed0;
_ZN11StageEntity28directionalDefeatedHVelocityE						= 0x020c4ed4;
_ZN11StageEntity13layerPositionE									= 0x020c4ed8;
_ZN11StageEntity33simplePlayerSpecialCollisionFlagsE				= 0x020c1f4c;
_ZN11StageEntity26simplePlayerCollisionFlagsE						= 0x020c1f48;


_ZTV11StageEntity													= 0x020c4efc;


/*----------------------------------------------------------------*/
/*----------------------- stage entity 3d ------------------------*/
/*----------------------------------------------------------------*/

_ZN13StageEntity3DD0Ev				= 0x020ce83c;
_ZN13StageEntity3DD1Ev				= 0x020ce8b8;
_ZN13StageEntity3D8onRenderEv		= 0x020ce92c;
_ZN13StageEntity3D11preRender3DEv	= 0x020ceac4;
_ZN13StageEntity3D12postRender3DEv	= 0x020ceac0;

_ZTV13StageEntity3D					= 0x02123dbc;


/*----------------------------------------------------------------*/
/*--------------------- stage entity 3d anm ----------------------*/
/*----------------------------------------------------------------*/

_ZN16StageEntity3DAnmC2Ev					= 0x020cee34;
_ZN16StageEntity3DAnmD0Ev					= 0x020ced44;
_ZN16StageEntity3DAnmD1Ev					= 0x020cedc0;
_ZN16StageEntity3DAnmD2Ev					= 0x020cecd0;
_ZN16StageEntity3DAnm8onRenderEv			= 0x020ceae0;
_ZN16StageEntity3DAnm15updateAnimationEv	= 0x020ceac8;
_ZN16StageEntity3DAnm11preRender3DEv		= 0x020ceccc;
_ZN16StageEntity3DAnm12postRender3DEv		= 0x020cecc8;

_ZTV16StageEntity3DAnm						= 0x02123ed8;


/*----------------------------------------------------------------*/
/*----------------------------- view -----------------------------*/
/*----------------------------------------------------------------*/

_ZN4ViewD0Ev		= 0x020a3a88;
_ZN4ViewD1Ev		= 0x020a3a5c;
_ZN4ViewD2Ev		= 0x020a3a5c;
_ZN4View8onRenderEv	= 0x020a3abc;

_ZTV4View			= 0x020c6eac;


/*----------------------------------------------------------------*/
/*------------------------- ortho view ---------------------------*/
/*----------------------------------------------------------------*/

_ZN9OrthoViewD0Ev		= 0x020ce734;
_ZN9OrthoViewD1Ev		= 0x020ce6dc;
_ZN9OrthoViewD2Ev		= 0x020ce6dc;

_ZTV9OrthoView			= 0x02123d08;

/*----------------------------------------------------------------*/
/*------------------------- persp view ---------------------------*/
/*----------------------------------------------------------------*/

_ZN9PerspViewD0Ev		= 0x020CD398;
_ZN9PerspViewD1Ev		= 0x020CD340;
_ZN9PerspViewD2Ev		= 0x020CD340;

_ZTV9PerspView			= 0x020E5938;


/*----------------------------------------------------------------*/
/*------------------------ ending camera -------------------------*/
/*----------------------------------------------------------------*/

_ZN12EndingCameraD0Ev			= 0x020DE16C;
_ZN12EndingCameraD1Ev			= 0x020DE104;
_ZN12EndingCameraD2Ev			= 0x020DE104;
_ZN12EndingCamera8onCreateEv	= 0x020DE4F8;
_ZN12EndingCamera8onUpdateEv	= 0x020DE408;
_ZN12EndingCamera8onRenderEv	= 0x020DE424;

_ZN12EndingCamera7profileE		= 0x020E9BF0;

_ZTV12EndingCamera				= 0x02123cb8;


/*----------------------------------------------------------------*/
/*------------------------ stage camera --------------------------*/
/*----------------------------------------------------------------*/

_ZN11StageCameraD0Ev		= 0x020cdd84;
_ZN11StageCameraD1Ev		= 0x020cdd1c;
_ZN11StageCamera8onCreateEv	= 0x020ce540;
_ZN11StageCamera8onUpdateEv	= 0x020ce42c;
_ZN11StageCamera8onRenderEv	= 0x020ce46c;

_ZN11StageCamera7profileE	= 0x02123c80;

_ZTV11StageCamera			= 0x02123cb8;


/*----------------------------------------------------------------*/
/*------------------------ world camera --------------------------*/
/*----------------------------------------------------------------*/

_ZN11WorldCameraD0Ev			= 0x020CCC68;
_ZN11WorldCameraD1Ev			= 0x020CCC04;
_ZN11WorldCameraD2Ev			= 0x020CCC04;
_ZN11WorldCamera8onCreateEv		= 0x020CD040;
_ZN11WorldCamera8onUpdateEv		= 0x020CCD7C;
_ZN11WorldCamera8onRenderEv		= 0x020CCF6C;
_ZN11WorldCamera11enterState0Ev	= 0x020CCD78;
_ZN11WorldCamera5state0Ev		= 0x020CCD74;
_ZN11WorldCamera8setStateEm		= 0x020CCD48;
_ZN11WorldCamera11updateStateEv	= 0x020CCCD4;

_ZN11WorldCamera7profileE		= 0x020E58D0;

_ZTV11WorldCamera				= 0x020E58E8;


/*----------------------------------------------------------------*/
/*----------------------- worldmap camera ------------------------*/
/*----------------------------------------------------------------*/

_ZN14WorldMapCameraD0Ev				= 0x020D15B4;
_ZN14WorldMapCameraD1Ev				= 0x020D1544;
_ZN14WorldMapCameraD2Ev				= 0x020D1544;
_ZN14WorldMapCamera8onCreateEv		= 0x020D1CCC;
_ZN14WorldMapCamera8onUpdateEv		= 0x001575CC;
_ZN14WorldMapCamera8onRenderEv		= 0x020D1BF8;
_ZN14WorldMapCamera8setStateEm		= 0x020D16A0;
_ZN14WorldMapCamera11updateStateEv	= 0x020D162C;

_ZN14WorldMapCamera7profileE		= 0x020E8BEC;

_ZTV14WorldMapCamera				= 0x020E8C3C;


/*----------------------------------------------------------------*/
/*----------------------- fixed ortho view -----------------------*/
/*----------------------------------------------------------------*/

_ZN14FixedOrthoViewD0Ev	= 0x020D3E4C;
_ZN14FixedOrthoViewD1Ev	= 0x020D3DF4;
_ZN14FixedOrthoViewD2Ev	= 0x020D3DF4;

_ZTV14FixedOrthoView	= 0x020DAB34;


/*----------------------------------------------------------------*/
/*---------------------- titlescreen camera ----------------------*/
/*----------------------------------------------------------------*/

_ZN17TitleScreenCameraD0Ev				= 0x020D3938;
_ZN17TitleScreenCameraD1Ev				= 0x020D38D4;
_ZN17TitleScreenCameraD2Ev				= 0x020D38D4;
_ZN17TitleScreenCamera8onCreateEv		= 0x020D3B68;
_ZN17TitleScreenCamera8onUpdateEv		= 0x020D3A50;
_ZN17TitleScreenCamera8onRenderEv		= 0x020D3A94;
_ZN17TitleScreenCamera8setOrthoEllll	= 0x020D39A4;

_ZN17TitleScreenCamera7profileE			= 0x020DAADC;

_ZTV17TitleScreenCamera					= 0x020DAAE4;


/*----------------------------------------------------------------*/
/*-------------------------- fade mask ---------------------------*/
/*----------------------------------------------------------------*/

_ZN8FadeMaskC1Ev								= 0x02014170;
_ZN8FadeMaskC2Ev								= 0x02014170;
_ZN8FadeMaskD0Ev								= 0x02014100;
_ZN8FadeMaskD1Ev								= 0x0201413c;
_ZN8FadeMaskD2Ev								= 0x0201413c;

_ZN8FadeMask17loadMaskModelFileEv               = 0x02013bdc;

_ZN8FadeMask									= 0x0203bd8c;


/*----------------------------------------------------------------*/
/*---------------------------- fader -----------------------------*/
/*----------------------------------------------------------------*/

_ZN5FaderC1Ev									= 0x02008558;
_ZN5FaderC2Ev									= 0x02008558;
_ZN5FaderD1Ev									= 0x02003090;

_ZN5Fader10staticMaskE							= 0x02085c38;
_ZN5Fader18staticCircleBoundsE					= 0x02039f80;
_ZN5Fader15activeFadeMasksE						= 0x02085a28;
_ZN5Fader10fadeFramesE							= 0x02085c28;
_ZN5Fader19alphaBlendingPlane1E					= 0x02085c24;
_ZN5Fader19alphaBlendingPlane2E					= 0x02085c34;
_ZN5Fader16alphaBlendingEVAE					= 0x02085c30;
_ZN5Fader16alphaBlendingEVBE					= 0x02085c2c;

_ZN5Fader12startFadeOutEmh						= 0x02007c44;
_ZN5Fader22enableMainScreenFadingEv				= 0x02007c44;
_ZN5Fader23disableMainScreenFadingEv			= 0x02007c20;
_ZN5Fader21enableSubScreenFadingEv				= 0x02007bfc;
_ZN5Fader22disableSubScreenFadingEv				= 0x02007bd8;

_ZN5Fader16setupSceneFadingENS_10FadingTypeEbb	= 0x020083cc;
_ZN5Fader7fadedInEv                             = 0x02007CB0;
_ZN5Fader8fadedOutEv                            = 0x02007C68;

_ZN4Game5faderE									= 0x02088f48;

/*----------------------------------------------------------------------*/
/*----------------------------- multiplayer ----------------------------*/
/*----------------------------------------------------------------------*/

_ZN11Multiplayer4initEv = 0x02010A84;
_ZN11Multiplayer13endConnectionEv = 0x0200F3D8;


/*----------------------------------------------------------------*/
/*--------------------------- framectrl --------------------------*/
/*----------------------------------------------------------------*/

_ZN9FrameCtrl6updateEv						= 0x0201feb8;
_ZN9FrameCtrl4initEtNS_4TypeElt				= 0x0201fe9c;
_ZN9FrameCtrl13getFrameCountEv				= 0x0201fe88;
_ZN9FrameCtrl16setAnimationTypeENS_4TypeE	= 0x0201fe74;
_ZN9FrameCtrl8finishedEv					= 0x0201fe34;
_ZN9FrameCtrl7passingEt						= 0x0201fd1c;


/*----------------------------------------------------------------*/
/*--------------------------- model base -------------------------*/
/*----------------------------------------------------------------*/

_ZN9ModelBaseC2Ev								= 0x02019c08;
_ZN9ModelBaseD0Ev								= 0x02019bd8;
_ZN9ModelBaseD1Ev								= 0x02019bf8;
_ZN9ModelBaseD2Ev								= 0x02019bc8;
_ZN9ModelBase9loadModelEPvmPP13NNSG3dResTex_	= 0x02019b7c;

_ZTV9ModelBase									= 0x0203c4b4;

/*----------------------------------------------------------------*/
/*----------------------------- model ----------------------------*/
/*----------------------------------------------------------------*/

_ZN5ModelC1Ev																= 0x02019a30;
_ZN5ModelC2Ev																= 0x02019a5c;
_ZN5ModelD0Ev																= 0x020199e8;
_ZN5ModelD1Ev																= 0x02019a10;
_ZN5ModelD2Ev																= 0x020199c8;
_ZN5Model4nullEv															= 0x02019944;
_ZN5Model6renderEPK7VecFx32													= 0x020198c4;
_ZN5Model6renderEPK7MtxFx43PK7VecFx32										= 0x02019864;
_ZN5Model6renderEv															= 0x02019858;
_ZN5Model6createEPvmm														= 0x02019948;
_ZN5Model11renderModelEv													= 0x02019934;
_ZN5Model18setCommandCallbackEPPFvP9NNSG3dRS_EPhh23NNSG3dSbcCallBackTiming	= 0x02019838;
_ZN5Model15getMaterialDataEm												= 0x0201980c;
_ZN5Model21getMaterialCollectionEv											= 0x020197fc;
_ZN5Model16getMaterialIndexEPK14NNSG3dResName_								= 0x020197e0;
_ZN5Model11getNodeInfoEv													= 0x020197d4;
_ZN5Model12getNodeIndexEPK14NNSG3dResName_									= 0x020197bc;
_ZN5Model21getNodeMatrixInternalEP18NNSG3dResNodeInfo_mP7MtxFx43			= 0x02019740;
_ZN5Model13getNodeMatrixEmP7MtxFx43											= 0x0201972c;
_ZN5Model15getNodePositionEmR4Vec3											= 0x020196dc;
_ZN5Model17restoreNodeMatrixEm												= 0x0201967c;

_ZTV5Model																	= 0x0203c514;


/*----------------------------------------------------------------*/
/*--------------------------- model anm --------------------------*/
/*----------------------------------------------------------------*/

_ZN8ModelAnmC1Ev							= 0x02019644;
_ZN8ModelAnmC2Ev							= 0x02019644;
_ZN8ModelAnmD0Ev							= 0x020195fc;
_ZN8ModelAnmD1Ev							= 0x02019624;
_ZN8ModelAnmD2Ev							= 0x02019624;
_ZN8ModelAnm6renderEPK7VecFx32				= 0x02019518;
_ZN8ModelAnm6renderEPK7MtxFx43PK7VecFx32	= 0x020194f8;
_ZN8ModelAnm6renderEv						= 0x020194e0;
_ZN8ModelAnm6createEPvS0_mmm				= 0x02019530;
_ZN8ModelAnm4initEmN9FrameCtrl4TypeElt		= 0x02019440;

_ZTV8ModelAnm								= 0x0203c4f4;


/*----------------------------------------------------------------*/
/*------------------------- blend model anm ----------------------*/
/*----------------------------------------------------------------*/

_ZN13BlendModelAnmC1Ev														= 0x020193e0;
_ZN13BlendModelAnmC2Ev														= 0x020193e0;
_ZN13BlendModelAnmD0Ev														= 0x020193c0;
_ZN13BlendModelAnmD1Ev														= 0x020193c0;
_ZN13BlendModelAnm6renderEPK7VecFx32										= 0x02019214;
_ZN13BlendModelAnm6renderEPK7MtxFx43PK7VecFx32								= 0x020191cc;
_ZN13BlendModelAnm6renderEv													= 0x0201918c;
_ZN13BlendModelAnm6createEPvS0_mmm											= 0x020192a8;
_ZN13BlendModelAnm13pushAnimationEmmN9FrameCtrl4TypeElt						= 0x02018fb8;
_ZN13BlendModelAnm6updateEv													= 0x02019138;
_ZN13BlendModelAnm15attachAnimationEPNS_14BlendAnimationE					= 0x02019288;
_ZN13BlendModelAnm15detachAnimationEPNS_14BlendAnimationE					= 0x0201925c;

_ZTV13BlendModelAnm															= 0x0203c4d4;

/*----------------------------------------------------------------*/
/*--------------------------- animation --------------------------*/
/*----------------------------------------------------------------*/

_ZN9AnimationC1Ev											= 0x02018f68;
_ZN9AnimationC2Ev											= 0x02018f90;
_ZN9AnimationD0Ev											= 0x02018f38;
_ZN9AnimationD1Ev											= 0x02018f58;
_ZN9AnimationD2Ev											= 0x02018f28;
_ZN9Animation6createEP16NNSG3dRenderObj_PvmP13NNSG3dResTex_	= 0x02018e74;
_ZN9Animation4initEmt										= 0x02018e28;
_ZN9Animation5resetEm										= 0x02018dd8;
_ZN9Animation6attachEv										= 0x02018dc0;
_ZN9Animation6detachEv										= 0x02018da8;

_ZTV9Animation												= 0x0203c4a4;


/*----------------------------------------------------------------*/
/*------------------------- animation ctrl -----------------------*/
/*----------------------------------------------------------------*/

_ZN13AnimationCtrlC1Ev													= 0x02018d88;
_ZN13AnimationCtrlC2Ev													= 0x02018d88;
_ZN13AnimationCtrlD0Ev													= 0x02018d40;
_ZN13AnimationCtrlD1Ev													= 0x02018d68;
_ZN13AnimationCtrl10createCtrlEP16NNSG3dRenderObj_PvmP13NNSG3dResTex_	= 0x02018cf4;
_ZN13AnimationCtrl4initEmN9FrameCtrl4TypeElt							= 0x02018c74;
_ZN13AnimationCtrl6updateEv												= 0x02018c54;
_ZN13AnimationCtrl8setFrameEt											= 0x02018c3c;

_ZTV13AnimationCtrl														= 0x0203c4c4;


/*----------------------------------------------------------------*/
/*---------------------------- texture ---------------------------*/
/*----------------------------------------------------------------*/

_ZN7TextureC1Ev									= 0x02018c2c;
_ZN7TextureC2Ev									= 0x02018c2c;
_ZN7TextureD2Ev									= 0x02018c1c;
_ZN7TextureD1Ev									= 0x02018c1c;
_ZN7TextureD0Ev									= 0x02018bfc;
_ZN7Texture4loadEPv								= 0x02018bc8;
_ZN7Texture16getTextureParamsERmm				= 0x02018b98;
_ZN7Texture28getTexturePaletteDestinationERmm	= 0x02018b68;

_ZTV7Texture									= 0x0203c494;


/*----------------------------------------------------------------*/
/*---------------------------- g3d misc --------------------------*/
/*----------------------------------------------------------------*/

_ZN3GFX10initializeEv										= 0x02019b6c;
_ZN3GFX10terminateEv										= 0x02019b78;
_ZN3GFX16getTextureParamsEP13NNSG3dResTex_mRm				= 0x02019afc;
_ZN3GFX28getTexturePaletteDestinationEP13NNSG3dResTex_mRm	= 0x02019a88;
_ZN3GFX12setRotationZER7MtxFx43s							= 0x020446b4;
_ZN3GFX12setRotationYER7MtxFx43s							= 0x020446f4;
_ZN3GFX12setRotationXER7MtxFx43s							= 0x02044734;
_ZN3GFX11setRotationER7MtxFx43sss							= 0x02044774;
_ZN3GFX14setTranslationER7MtxFx43lll						= 0x02044814;
_ZN3GFX7rotateZER7MtxFx43s									= 0x0204485c;
_ZN3GFX7rotateYER7MtxFx43s									= 0x02044888;
_ZN3GFX7rotateXER7MtxFx43s									= 0x020448b4;
_ZN3GFX6rotateER7MtxFx43sss									= 0x020448e0;
_ZN3GFX14rotateReversedER7MtxFx43sss						= 0x0204496c;
_ZN3GFX5scaleER7MtxFx43lll									= 0x020449f8;
_ZN3GFX9translateER7MtxFx43lll								= 0x02044a24;



/*----------------------------------------------------------------*/
/*------------------------ collision manager ---------------------*/
/*----------------------------------------------------------------*/

_ZN12CollisionMgrC2Ev											= 0x020ab13c;
_ZN12CollisionMgrD0Ev											= 0x020ab0d4;
_ZN12CollisionMgrD1Ev											= 0x020ab110;
_ZN12CollisionMgrD2Ev											= 0x020ab110;

_ZN12CollisionMgr4initEP10StageActorP15CollisionSensorS3_S3_m	= 0x020ab010;
_ZN12CollisionMgr18updateBottomSensorEm							= 0x01FFF93C;
_ZN12CollisionMgr17updateSideSensorsEPlm						= 0x01FFE778;
_ZN12CollisionMgr21updateSidePointSensorEP11PointSensormm		= 0x01FFE730;
_ZN12CollisionMgr20updateSideLineSensorEP11LineSensorVmm		= 0x01FFE660;
_ZN12CollisionMgr21updateGroundCollisionEv						= 0x020A917C;
_ZN12CollisionMgr19updateWallCollisionEv						= 0x020A915C;
_ZN12CollisionMgr15updateTopSensorEm							= 0x020AA990;

_ZN12CollisionMgr21getBottomTileBehaviorEll						= 0x020A6D18;


_ZTV12CollisionMgr												= 0x020c7000;


/*----------------------------------------------------------------*/
/*------------------------- platform mgr -------------------------*/
/*----------------------------------------------------------------*/

_ZN11PlatformMgrC2Ev	= 0x0201da00;
_ZN11PlatformMgrC1Ev	= 0x0201da00;
_ZN11PlatformMgrD2Ev	= 0x0201d9e4;
_ZN11PlatformMgrD1Ev	= 0x0201d9e4;
_ZN11PlatformMgrD0Ev	= 0x0201d9b8;

_ZTV11PlatformMgr		= 0x0203C620;


/*----------------------------------------------------------------*/
/*------------------------- platform base ------------------------*/
/*----------------------------------------------------------------*/

_ZN12PlatformBaseC1Ev					= 0x0201c1a4;
_ZN12PlatformBaseC2Ev					= 0x0201c1a4;
_ZN12PlatformBaseD0Ev					= 0x0201c12c;
_ZN12PlatformBaseD1Ev					= 0x0201c16c;
_ZN12PlatformBaseD2Ev					= 0x0201c0f4;
_ZN12PlatformBase6updateEv				= 0x0201c018;
_ZN12PlatformBase16resolveCollisionEv	= 0x0201be9c;
_ZN12PlatformBase5func5Ev				= 0x0201be98;
_ZN12PlatformBase5resetEv				= 0x0201c0d8;
_ZN12PlatformBase4linkEv				= 0x0201c080;
_ZN12PlatformBase6unlinkEv				= 0x0201c01c;

_ZTV12PlatformBase						= 0x0203c6a0;


/*----------------------------------------------------------------*/
/*----------------------- segment platform -----------------------*/
/*----------------------------------------------------------------*/

_ZN15SegmentPlatformC1Ev							= 0x0201b9e0;
_ZN15SegmentPlatformC2Ev							= 0x0201b9e0;
_ZN15SegmentPlatformD0Ev							= 0x0201afb4;
_ZN15SegmentPlatformD1Ev							= 0x020030a4;
_ZN15SegmentPlatform4initEP10StageActorRK4Vec2S4_	= 0x0201b964;
_ZN15SegmentPlatform4initEP10StageActorllll			= 0x0201b918;
_ZN15SegmentPlatform9setPointsEP4Vec2S1_			= 0x0201b8c0;
_ZN15SegmentPlatform9setPointsEllll					= 0x0201b88c;
_ZN15SegmentPlatform6updateEv						= 0x0201b7c0;

_ZTV15SegmentPlatform								= 0x0203c684;


/*----------------------------------------------------------------*/
/*---------------------- rotating platform -----------------------*/
/*----------------------------------------------------------------*/

_ZN16RotatingPlatformC1Ev												= 0x0201be64;
_ZN16RotatingPlatformC2Ev												= 0x0201be64;
_ZN16RotatingPlatformD0Ev												= 0x0201af80;
_ZN16RotatingPlatformD1Ev												= 0x020030e8;
_ZN16RotatingPlatform6updateEv											= 0x0201ba18;
_ZN16RotatingPlatform4initEP10StageActorlllllshPK4Vec3					= 0x0201bd60;
_ZN16RotatingPlatform4initEP10StageActorP20RotatingPlatformInfoPK4Vec3	= 0x0201bc50;
_ZN16RotatingPlatform9setHeightEll										= 0x0201bc30;
_ZN16RotatingPlatform8setRightEl										= 0x0201bc18;
_ZN16RotatingPlatform7setLeftEl											= 0x0201bc00;
_ZN16RotatingPlatform7setBaseEll										= 0x0201bbe4;
_ZN16RotatingPlatform6updateEv											= 0x0201ba18;

	_ZTV16RotatingPlatform													= 0x0203c64C;


/*----------------------------------------------------------------*/
/*---------------------- deforming platform ----------------------*/
/*----------------------------------------------------------------*/

_ZN17DeformingPlatformC1Ev									= 0x0201b778;
_ZN17DeformingPlatformC2Ev									= 0x0201b778;
_ZN17DeformingPlatformD0Ev									= 0x0201b02c;
_ZN17DeformingPlatformD1Ev									= 0x0201afec;
_ZN17DeformingPlatform4initEP10StageActorRK4Vec2S4_S4_S4_	= 0x0201b6d4;
_ZN17DeformingPlatform9setPointsERK4Vec2S2_					= 0x0201b67c;
_ZN17DeformingPlatform6updateEv								= 0x0201b51c;
_ZN17DeformingPlatform5func5Ev								= 0x0201b514;

_ZTV17DeformingPlatform										= 0x0203c668;


/*----------------------------------------------------------------*/
/*------------------------ round platform ------------------------*/
/*----------------------------------------------------------------*/

_ZN13RoundPlatformC1Ev							= 0x0201b4dc;
_ZN13RoundPlatformC2Ev							= 0x0201b4dc;
_ZN13RoundPlatformD0Ev							= 0x0201b0a8;
_ZN13RoundPlatformD1Ev							= 0x0201b074;
_ZN13RoundPlatform4initEP10StageActorlllllsllb	= 0x0201b420;
_ZN13RoundPlatform6updateEv						= 0x0201b22c;
_ZN13RoundPlatform16resolveCollisionEv			= 0x0201b0e8;
_ZN13RoundPlatform5func5Ev						= 0x0201b0e4;

_ZTV13RoundPlatform								= 0x0203c630;


/*----------------------------------------------------------------*/
/*----------------------- active collider ------------------------*/
/*----------------------------------------------------------------*/

_ZN14ActiveColliderC1Ev												= 0x020a4868;
_ZN14ActiveColliderD0Ev												= 0x020a4820;
_ZN14ActiveColliderD1Ev												= 0x020a484c;
_ZN14ActiveColliderD2Ev												= 0x020a484c;
_ZN14ActiveCollider5resetEv											= 0x020a4808;
_ZN14ActiveCollider4initEP10StageActorRK18ActiveColliderInfob		= 0x020a47a0;
_ZN14ActiveCollider22setPositionAroundPivotEtll						= 0x020a4758;
_ZN14ActiveCollider19resetCollisionStateEv							= 0x020a4714;
_ZN14ActiveCollider4linkEv											= 0x020a46bc;
_ZN14ActiveCollider6unlinkEv										= 0x020a4658;
_ZN14ActiveCollider12manualUpdateEv									= 0x020a44b0;
_ZN14ActiveCollider12unk_020a445cERK4Vec3RK18ActiveColliderInfobm	= 0x020a445c;
_ZN14ActiveCollider10initSystemEv									= 0x020a4434;
_ZN14ActiveCollider17testCollisionRectEPS_							= 0x01ffdd88;
_ZN14ActiveCollider18testCollisionRoundEPS_							= 0x020a4344;
_ZN14ActiveCollider25testCollisionOtherVsVTrpzEPS_					= 0x020a4264;
_ZN14ActiveCollider25testCollisionVTrpzVsOtherEPS_					= 0x020a40a4;
_ZN14ActiveCollider25testCollisionOtherVsHTrpzEPS_					= 0x020a3fc4;
_ZN14ActiveCollider25testCollisionHTrpzVsOtherEPS_					= 0x020a3e04;

_ZTV14ActiveCollider												= 0x020c6f08;


/*----------------------------------------------------------------*/
/*--------------------------- collider ---------------------------*/
/*----------------------------------------------------------------*/

_ZN8ColliderC1Ev													= 0x020ab8e8;
_ZN8ColliderC2Ev													= 0x020ab8e8;
_ZN8ColliderD1Ev													= 0x020ab8b8;
_ZN8Collider5resetEv												= 0x020ab898;
_ZN8Collider6initExEP10StageActorllllPFvRS0_S2_ES4_S4_mhPK4Vec3		= 0x020ab81c;
_ZN8Collider4initEP10StageActorRK12ColliderInfomhPK4Vec3			= 0x020ab7b8;
_ZN8Collider10initRectExEllllPK4Vec3								= 0x020ab6bc;
_ZN8Collider8initRectERK4Vec2S2_PK4Vec3								= 0x020ab560;
_ZN8Collider8initRectERK12ColliderInfoPK4Vec3						= 0x020ab40c;
_ZN8Collider4linkEv													= 0x020ab3b4;
_ZN8Collider6unlinkEv												= 0x020ab350;
_ZN8Collider14updatePositionEv										= 0x020ab2cc;
_ZN8Collider11doSomethingEv											= 0x020ab18c;

_ZN8Collider5firstE													= 0x020cabe4;
_ZN8Collider4lastE													= 0x020cabe8;


/*----------------------------------------------------------------*/
/*--------------------------- fireball ---------------------------*/
/*----------------------------------------------------------------*/

_ZN4Game15fireballHandlerE = 0x02129484;


/*----------------------------------------------------------------*/
/*-------------------------- stage misc --------------------------*/
/*----------------------------------------------------------------*/

_ZN5Stage23addMegaDestructionScoreEhs				= 0x020200d4;
_ZN5Stage23getMegaDestructionScoreEh				= 0x02020114;
_ZN5Stage23setMegaDestructionScoreEht				= 0x02020128;
_ZN5Stage7setZoomElmhh								= 0x020facfc;
_ZN5Stage9getRandomEv								= 0x0200e6f4;

_ZN5Stage14liquidPositionE							= 0x020cae0c; 
_ZN5Stage18lastLiquidPositionE						= 0x020cadac;
_ZN5Stage6eventsE									= 0x0208af3c;
_ZN5Stage7cameraXE									= 0x020cae1c;
_ZN5Stage7cameraYE									= 0x020cad94;
_ZN5Stage11cameraZoomXE								= 0x020cada4;
_ZN5Stage11cameraZoomYE								= 0x020cad8c;
_ZN5Stage20megaInteractionFlagsE					= 0x020ca284;
_ZN5Stage10freezeFlagE								= 0x020ca28c;
_ZN5Stage15fenceFreezeFlagE							= 0x020ca29c;
_ZN5Stage20megaInteractionViewsE					= 0x020ca2bc;
_ZN5Stage22globalCollisionTriggerE					= 0x020ca2c0;
_ZN5Stage20megaGroundPoundViewsE					= 0x020ca2c4;
_ZN5Stage11stageLayoutE								= 0x020cad40;
_ZN5Stage16anmTilesOamTableE						= 0x0212f180;


/*----------------------------------------------------------------*/
/*----------------------- stage layout misc ----------------------*/
/*----------------------------------------------------------------*/

_ZN4Game11stageBlocksE = 0x0208b168;


/*----------------------------------------------------------------*/
/*-------------------------- system misc -------------------------*/
/*----------------------------------------------------------------*/

_ZN4Game14storeDataCacheEPKvm														= 0x0200765c; 
_ZN4Game14flushDataCacheEPKvm														= 0x02007684;
_ZN4Game11taskCleanupEv																= 0x02004c30;
_ZN4Game7runTaskEPFvPvES0_mS0_m														= 0x02004cb8;
_ZN4Game11resetSystemEm																= 0x0200514c;
_ZN4Game14drawBNCLSpriteEhP9GXOamAttrN3OAM5FlagsEhhPK4Vec2sPKsNS2_8SettingsEll		= 0x0200421c;
_ZN4GameL17drawBNCLSpriteSubEhP9GXOamAttrN3OAM5FlagsEhhPK4Vec2sPKsNS2_8SettingsEll	= 0x0200419c;
_ZN4Game15initExtendedIDsEv															= 0x02004dfc;
_ZN4Game14waitVBlankIntrEv															= 0x020058c0;
_ZN4Game16disableVRAMBanksEv														= 0x02004be0;
_ZN4Game12getBootSceneEv															= 0x0200563c;
_ZN4Game12setBootSceneEt															= 0x0200564c;

_ZN4Game16mainProcessTableE                                                         = 0x0203997c;
_ZN4Game19currentProcessTableE                                                      = 0x0208fb98;
_ZN4Game9actorTreeE																	= 0x0208fb0c;

_ZN4Game16visiblePlaneMainE															= 0x02085a88;


/*----------------------------------------------------------------*/
/*-------------------------- game misc ---------------------------*/
/*----------------------------------------------------------------*/

_ZN4Game9loadLevelEtmhhhhhhhhhhhhhhm		= 0x0200696C;   
_ZN4Game20resetStageCheckpointEv			= 0x020066F8;
_ZN4Game18setStageCheckpointEv				= 0x02006740;
_ZN4Game18getStageCheckpointEv				= 0x02006790;
_ZN4Game14getPlayerCountEv					= 0x020202A0;
_ZN4Game14setPlayerCountEm					= 0x020202B0;
_ZN4Game16getCurrentPlayerEv				= 0x020205EC;
_ZN4Game9getPlayerEl						= 0x02020608;
_ZN4Game9setPlayerElP6Player				= 0x02020618;
_ZN4Game26stageObjectBankOverlayProcEPvb	= 0x0200DEE0;
_ZN4Game18getPlayerCharacterEl				= 0x02020260;
_ZN4Game18setPlayerCharacterElh				= 0x02020270;
_ZN4Game14getPlayerLivesEl					= 0x02020570;
_ZN4Game14setPlayerLivesEll					= 0x02020580;
_ZN4Game25getPlayerInventoryPowerupEl		= 0x02020240;
_ZN4Game25setPlayerInventoryPowerupElh		= 0x02020250;
_ZN4Game13getPlayerDeadEl					= 0x02020220;
_ZN4Game13setPlayerDeadElb					= 0x02020230;
_ZN4Game21getPlayerRespawnStateEl			= 0x020200B4;
_ZN4Game21setPlayerRespawnStateEll			= 0x020200C4;

_ZN4Game13localPlayerIDE					= 0x02085A7C;
_ZN4Game6vsModeE							= 0x02085a84;
_ZN4Game9luigiModeE							= 0x02085A50;
_ZN4Game19checkpointCollectedE				= 0x02085a1c;
_ZN4Game19currentWorldmapNodeE				= 0x02085a9c;
_ZN4Game11modelMatrixE						= 0x208b6e8;
_ZN4Game10viewMatrixE						= 0x02085B20;


/*----------------------------------------------------------------*/
/*---------------------------- aeabi -----------------------------*/
/*----------------------------------------------------------------*/

__aeabi_uidiv		= 0x0207e344;
__aeabi_uidivmod	= 0x0207e344;
__aeabi_idiv		= 0x0207e138;
__aeabi_idivmod		= 0x0207e138;

/* __aeabi_uldiv		= 0x0207df30; */
/* __aeabi_uldivmod		= 0x0207df3c; */
/* __aeabi_ldiv			= 0x0207df88; */
/* __aeabi_ldivmod		= 0x0207df78; */

_ull_div = 0x0207df30;
_ull_mod = 0x0207df3c;
_ll_div  = 0x0207df88;
_ll_mod  = 0x0207df78;


/*----------------------------------------------------------------*/
/*------------------------ PipeRenderer --------------------------*/
/*----------------------------------------------------------------*/

_ZN12PipeRenderer12loadTexturesEv										= 0x020f6640;
_ZN12PipeRenderer5setupElmmmmm											= 0x020f6528;
_ZN12PipeRenderer6renderERK4Vec3s										= 0x020f64ac;
_ZN12PipeRenderer17loadPipesGraphicsEv									= 0x020f671c;
_ZN12PipeRenderer16renderHorizontalERK4Vec3s							= 0x020f6798;
_ZN12PipeRenderer14renderVerticalERK4Vec3s								= 0x020f6b7c;
_ZN12PipeRenderer20renderHorizontalMiniERK4Vec3s						= 0x020f6d44;
_ZN12PipeRenderer18renderVerticalMiniERK4Vec3s							= 0x020f6e80;
_ZN12PipeRenderer10renderQuadERK4Vec2RK11TextureInfollS2_				= 0x020f6fb4;
_ZN12PipeRenderer13setupTexturesEv										= 0x020f6528;

_ZN12PipeRenderer20miniPipeExitTLTexIDsE								= 0x021225b8;
_ZN12PipeRenderer20miniPipeExitBRTexIDsE								= 0x021225bc;
_ZN12PipeRenderer18miniPipeBodyTexIDsE									= 0x021225c0;
_ZN12PipeRenderer18brokenPipeTLTexIDsE									= 0x021225c4;
_ZN12PipeRenderer18brokenPipeBRTexIDsE									= 0x021225cc;
_ZN12PipeRenderer16pipeExitBRTexIDsE									= 0x021225d4;
_ZN12PipeRenderer16pipeExitTLTexIDsE									= 0x021225e0;
_ZN12PipeRenderer14pipeBodyTexIDsE										= 0x021225ec;


/*-----------------------------------------------------------------*/
/*--------------------------- MvsL Menu ---------------------------*/
/*-----------------------------------------------------------------*/

_ZN8MvsLMenu18startConsoleSearchEv  = 0x021575A8;


/*----------------------------------------------------------------*/
/*------------------------- player base --------------------------*/
/*----------------------------------------------------------------*/

_ZN10PlayerBase13getRunKeyHeldEv							= 0x0212C7A4;
_ZN10PlayerBase14getLeftKeyHeldEv							= 0x0212C8CC;
_ZN10PlayerBase15getRightKeyHeldEv							= 0x0212C8BC;
_ZN10PlayerBase17getJumpKeyPressedEv						= 0x0212C63C;
_ZN10PlayerBase14setLinkedActorER10StageActor				= 0x0212B26C;
_ZN5Stage23setMegaDestructionScoreEht				= 0x02020128;
_ZN5Stage7setZoomElmhh								= 0x020facfc;
_ZN5Stage9getRandomEv								= 0x0200e6f4;
_ZN5Stage9getAreaIDEhhh								= 0x0201f53c;

_ZN5Stage14liquidPositionE							= 0x020cae0c;
_ZN5Stage18lastLiquidPositionE						= 0x020cadac;
_ZN5Stage6eventsE									= 0x0208af3c;
_ZN5Stage7cameraXE									= 0x020cae1c;
_ZN5Stage7cameraYE									= 0x020cad94;
_ZN5Stage11cameraZoomXE								= 0x020cada4;
_ZN5Stage11cameraZoomYE								= 0x020cad8c;
_ZN5Stage18questionBlockFrameE						= 0x0212944c;
_ZN5Stage15brickBlockFrameE							= 0x0212943c;
_ZN5Stage11stageLayoutE								= 0x020cad40;
_ZN5Stage16anmTilesOamTableE						= 0x0212f180;
_ZN5Stage10freezeFlagE								= 0x020ca850;
_ZN5Stage10stageGroupE								= 0x02085a18;
_ZN5Stage7stageIDE									= 0x02085a14;
_ZN5Stage5actIDE									= 0x02085a4c;


/*----------------------------------------------------------------*/
/*----------------------- climbing koopa -------------------------*/
/*----------------------------------------------------------------*/

_ZN13ClimbingKoopaD0Ev										= 0x02141EE8;
_ZN13ClimbingKoopaD1Ev										= 0x02141E80;
_ZN13ClimbingKoopaD2Ev										= 0x02141E80;
_ZN13ClimbingKoopa8onCreateEv								= 0x021424FC;
_ZN13ClimbingKoopa9onDestroyEv								= 0x02142214;
_ZN13ClimbingKoopa8onRenderEv								= 0x02142220;
_ZN13ClimbingKoopa14pendingDestroyEv						= 0x0214221C;
_ZN13ClimbingKoopa17onUserHeapCreatedEv						= 0x02142F50;
_ZN13ClimbingKoopa10updateMainEv							= 0x021424A0;
_ZN13ClimbingKoopa10onBlockHitEv							= 0x021421A0;
_ZN13ClimbingKoopa9onStompedEv								= 0x02142408;
_ZN13ClimbingKoopa12damagePlayerER14ActiveColliderR6Player	= 0x02142374;
_ZN13ClimbingKoopa6defeatElllh								= 0x02142450;
_ZN13ClimbingKoopa9loadModelEv								= 0x02142FD0;
_ZN13ClimbingKoopa13loadResourcesEv							= 0x02142FA8;
_ZN13ClimbingKoopa11switchStateEMS_FvvE						= 0x02142E5C;
_ZN13ClimbingKoopa11updateStateEv							= 0x02142E20;
_ZN13ClimbingKoopa20horizontalStateClimbEv					= 0x02142C54;
_ZN13ClimbingKoopa18verticalStateClimbEv					= 0x02142AA0;
_ZN13ClimbingKoopa23horizontalStateFlipSideEv				= 0x02142900;
_ZN13ClimbingKoopa22verticalStateFlipSideAEv				= 0x021427F0;
_ZN13ClimbingKoopa22verticalStateFlipSideBEv				= 0x02142660;
_ZN13ClimbingKoopa13checkNextTileERK11PointSensor			= 0x02142138;
_ZN13ClimbingKoopa13changePaletteER8ModelAnmmm				= 0x02142104;
_ZN13ClimbingKoopa17colliderCallbackER14ActiveColliderS1_	= 0x02141F58;

_ZN13ClimbingKoopa7profileE									= 0x02145200;

_ZTV13ClimbingKoopa											= 0x0214520C;


/*----------------------------------------------------------------*/
/*------------------------- player base --------------------------*/
/*----------------------------------------------------------------*/

_ZN10PlayerBase13getRunKeyHeldEv							= 0x0212C7A4;
_ZN10PlayerBase14getLeftKeyHeldEv							= 0x0212C8CC;
_ZN10PlayerBase15getRightKeyHeldEv							= 0x0212C8BC;
_ZN10PlayerBase17getJumpKeyPressedEv						= 0x0212C63C;
_ZN10PlayerBase14setLinkedActorER10StageActor				= 0x0212B26C;
_ZN10PlayerBase17removeLinkedActorIfLinkedER10StageActor	= 0x0212BDE0;
_ZNK10PlayerBase13getShellStateEv							= 0x0212BBA4;


/*----------------------------------------------------------------*/
/*---------------------------- player ----------------------------*/
/*----------------------------------------------------------------*/

_ZN6Player12setAnimationEmbmlt							= 0x02120BB8;
_ZN6Player17setAnimationSpeedEl							= 0x021209E0;
_ZN6Player16setMovementStateEMS_FbPvES0_				= 0x021006AC;
_ZNK6Player20isAnimationCompletedEv						= 0x02120A14;
_ZN6Player15updateAnimationEv							= 0x02120A24;
_ZN6Player6freezeEb										= 0x0211F34C;
_ZN6Player8unfreezeEv									= 0x0211F2EC;
_ZN6Player13enterEntranceEv								= 0x021195E8;

_ZN6Player14tryUnlinkActorEv							= 0x02104C9C;
_ZN6Plater11unlinkActorEv								= 0x02104CCC;

_ZN6Player12starmanTimerE								= 0x0208B350;


/*----------------------------------------------------------------*/
/*---------------------------- input -----------------------------*/
/*----------------------------------------------------------------*/

_ZN5Input17initPlayerMappingEv						= 0x0200a9d0;
_ZN5Input17updatePlayerInputEv						= 0x0200a814;
_ZN5Input16setPlayerMappingEbm						= 0x0200a784;
_ZN5Input24updateVirtualPlayerInputEm				= 0x0200a6e4;
_ZN5Input6updateEv									= 0x0200a594;
_ZN5Input18updateConsoleInputEmt					= 0x0200a508;
_ZN5Input26getFirstConsoleKeysPressedEPmt			= 0x0200a4c8;
_ZN5Input23getFirstConsoleKeysHeldEPmt				= 0x0200a488;
_ZN5Input31updateVerticalSelectionIteratorEPll		= 0x0200a42c;
_ZN5Input33updateHorizontalSelectionIteratorEPll	= 0x0200a3d0;

_ZN5Input16triggerSoftResetE						= 0x02087630;
_ZN5Input14localConsoleIDE							= 0x02087634;
_ZN5Input16consoleKeysTimerE						= 0x02087638;
_ZN5Input13consoleKeysUpE							= 0x02087640;
_ZN5Input19consoleKeysRepeatedE						= 0x02087648;
_ZN5Input11consoleKeysE								= 0x02087650;
_ZN5Input14playerKeysHeldE							= 0x02087660;
_ZN5Input17playerKeysPressedE						= 0x02087664;
_ZN5Input23virtualPlayerInputTimerE					= 0x02087668;
_ZN5Input31virtualPlayerInputPatternSourceE			= 0x0208766c;
_ZN5Input25virtualPlayerInputEnabledE				= 0x02087670;
_ZN5Input16playerKeyStackIDE						= 0x02087674;
_ZN5Input24virtualPlayerInputLengthE				= 0x02087678;
_ZN5Input22playerDirectionalFlagsE					= 0x0208767c;
_ZN5Input16playerRepeatRateE						= 0x02087680;
_ZN5Input17playerRepeatDelayE						= 0x02087684;
_ZN5Input17playerRepeatTimerE						= 0x02087688;
_ZN5Input18playerKeysRepeatedE						= 0x0208768c;
_ZN5Input22playerKeysPressedStackE					= 0x02087690;
_ZN5Input19playerKeysHeldStackE						= 0x020876a0;
_ZN5Input13playerMappingE							= 0x020876b0;

_ZN5Input22unusedDirectionalFlagsE					= 0x020262ec;

/*----------------------------------------------------------------*/
/*--------------------------- effect -----------------------------*/
/*----------------------------------------------------------------*/

_ZN6EffectC1Ev = 0x020e6414;
_ZN6EffectC2Ev = 0x020e6414;
_ZN6EffectD0Ev = 0x020e6334;
_ZN6EffectD1Ev = 0x020e63a8;
_ZN13EffectHandlerD0Ev = 0x020e683c;
_ZN13EffectHandlerD1Ev = 0x020e6888;
_ZN11ChildEffectC1Ev = 0x020e64dc;
_ZN11ChildEffectC2Ev = 0x020e64dc;
_ZN11ChildEffectD1Ev = 0x020e6320;
_ZN6Effect18updateMeteorDebrisEv = 0x020e415c;
_ZN6Effect18renderMeteorDebrisEv = 0x020e4280;
_ZN6Effect16initMeteorDebrisEv = 0x020e4378;
_ZN6Effect21decrementBrickCounterEv = 0x020e4510;
_ZN6Effect21incrementBrickCounterEv = 0x020e4538;
_ZN6Effect12updateBricksEv = 0x020e4550;
_ZN6Effect12renderBricksEv = 0x020e4710;
_ZN6Effect10initBricksEv = 0x020e481c;
_ZN6Effect16updatePipeShardsEv = 0x020e4a6c;
_ZN6Effect16renderPipeShardsEv = 0x020e4b6c;
_ZN6Effect14initPipeShardsEv = 0x020e4c3c;
_ZN6Effect10renderStarEv = 0x020e4d7c;
_ZN6Effect8initStarEv = 0x020e4dcc;
_ZN6Effect11updateShineEv = 0x020e4de8;
_ZN6Effect11renderShineEv = 0x020e4e68;
_ZN6Effect9initShineEv = 0x020e4eb8;
_ZN6Effect19updateFireballTrailEv = 0x020e4ed4;
_ZN6Effect19renderFireballTrailEv = 0x020e4ef8;
_ZN6Effect17initFireballTrailEv = 0x020e4f74;
_ZN6Effect17updateDroppedCardEv = 0x020e4fac;
_ZN6Effect17updateFallingCardEv = 0x020e50b4;
_ZN6Effect17updateCardCollectEv = 0x020e51c8;
_ZN6Effect17updateDisplayCardEv = 0x020e5338;
_ZN6Effect10renderCardEv = 0x020e53dc;
_ZN6Effect8initCardEv = 0x020e5424;
_ZN6Effect14updateSparklesEv = 0x020e5428;
_ZN6Effect14renderSparklesEv = 0x020e54f0;
_ZN6Effect12initSparklesEv = 0x020e553c;
_ZN6Effect15updateRedNumberEv = 0x020e555c;
_ZN6Effect15renderRedNumberEv = 0x020e573c;
_ZN6Effect13initRedNumberEv = 0x020e57c0;
_ZN6Effect12updatePointsEv = 0x020e57c4;
_ZN6Effect12renderPointsEv = 0x020e588c;
_ZN6Effect10initPointsEv = 0x020e58e0;
_ZN6Effect12applyGravityEv = 0x020e58fc;
_ZN6Effect13applyVelocityERK4Vec3 = 0x020e5920;
_ZN6Effect13applyVelocityEv = 0x020e5940;
_ZN6Effect6updateEv = 0x020e5964;
_ZN6Effect6renderEv = 0x020e59a8;
_ZN6Effect7disableEv = 0x020e59ec;
_ZN6Effect12switchUpdateEMS_FvvE = 0x020e59f8;
_ZN6Effect6createEaRK4Vec3mtam = 0x020e5ac4;
_ZN6EffectC2Ev = 0x020e6414;
_ZN13EffectHandlerC2Ev = 0x020e68cc;
_ZN7Effects7destroyEa = 0x020e64f0;
_ZN7Effects6updateEv = 0x020e650c;
_ZN7Effects6renderEv = 0x020e6524;
_ZN7Effects5spawnEaRK4Vec3mtam = 0x020e653c;
_ZN7Effects5spawnEaRK4Vec3a = 0x020e657c;
_ZN7Effects5validEv = 0x020e65b4;
_ZN13EffectHandler7destroyEa = 0x020e65cc;
_ZN13EffectHandler6updateEv = 0x020e66bc;
_ZN13EffectHandler6renderEv = 0x020e6710;
_ZN13EffectHandler5spawnEaRK4Vec3mtam = 0x020e6764;
_ZN13EffectHandler5validEv = 0x020e6834;

_ZN7Effects12activeBricksE = 0x0212a41c;
_ZN7Effects13effectHandlerE = 0x0212a420;
_ZN6Effect22effectTableInitializedE = 0x0212a424;
_ZN6Effect11effectTable = 0x0212a428;

_ZTV6Effect = 0x02126a24;
_ZTV13EffectHandler = 0x02126a04;


/*----------------------------------------------------------------*/
/*----------------------------- bnbl -----------------------------*/
/*----------------------------------------------------------------*/

_ZN4BNBL19getYFromAnchoredPosEtm = 0x020558e8;
_ZN4BNBL19getXFromAnchoredPosEtm = 0x02055930;
_ZN4BNBL19getRectangleIDAtPosEPvll = 0x02055a0c;
_ZN4BNBL17getRectangleCountEPv = 0x02055aD4;


/*----------------------------------------------------------------*/
/*------------------------- stage layout -------------------------*/
/*----------------------------------------------------------------*/

_ZN11StageLayout10changeTileEmmm		= 0x020af30c;
_ZN11StageLayout15getTileBehaviorEmml	= 0x020af8f0;
_ZN11StageLayout10getChunkIDEmm			= 0x020b0308;
_ZN11StageLayout17readTileBehaviourEt	= 0x020afa30;
_ZN11StageLayout13doLayoutResetE		= 0x020cac98;


/*----------------------------------------------------------------*/
/*----------------------------- item -----------------------------*/
/*----------------------------------------------------------------*/

_ZN4Item11switchStateEMS_FbvE = 0x020d4eb8;
_ZN4Item12checkConsumeEv = 0x020d475c;


/*----------------------------------------------------------------*/
/*------------------------ animated tiles ------------------------*/
/*----------------------------------------------------------------*/

_ZN13AnimatedTilesC2Ev								= 0x020e2978;
_ZN13AnimatedTilesD0Ev								= 0x020e2948;
_ZN13AnimatedTilesD1Ev								= 0x020e2968;
_ZN13AnimatedTilesD2Ev								= 0x020e2968;
_ZN13AnimatedTiles6updateEv							= 0x0212944c;
_ZN13AnimatedTiles18questionBlockFrameE				= 0x0212944c;
_ZN13AnimatedTiles9coinFrameE						= 0x02129438;
_ZN13AnimatedTiles10brickFrameE						= 0x0212943c;

_ZTV13AnimatedTiles									= 0x0212675c;


/*----------------------------------------------------------------*/
/*------------------------- view shaker --------------------------*/
/*----------------------------------------------------------------*/

_ZN10ViewShaker6createEv							= 0x020f9a38;
_ZN10ViewShaker7destroyEv							= 0x020f99f4;
_ZN10ViewShaker6updateEv							= 0x020f9900;
_ZN10ViewShaker5resetEv								= 0x020f98f4;
_ZN10ViewShaker9setConfigEhRKNS_6ConfigE			= 0x020f9888;
_ZN10ViewShaker5startEhh							= 0x020f982c;
_ZN10ViewShaker5startEhhh							= 0x020f97dc;
_ZN10ViewShaker5startEhhhb							= 0x020f96a0;


/*----------------------------------------------------------------*/
/*--------------------------- unsorted ---------------------------*/
/*----------------------------------------------------------------*/

Liquid_doWaves = 0x021646E0;
setPlayerStateForWaterBubbles = 0x02102BC4;
IncrementMegaMushroomDestructionCounter = 0x020200D4;


/* arm9_ov24 */

/*----------------------------------------------------------------*/
/*---------------------------- thwomp ----------------------------*/
/*----------------------------------------------------------------*/

_ZN6ThwompD0Ev											= 0x0213DA68;
_ZN6ThwompD1Ev											= 0x0213D9E0;
_ZN6ThwompD2Ev											= 0x0213D9E0;
_ZN6Thwomp8onCreateEv									= 0x0213DB20;
_ZN6Thwomp9onDestroyEv									= 0x0213DAF8;
_ZN6Thwomp17onUserHeapCreatedEv							= 0x0213DCFC;
_ZN6Thwomp10updateMainEv								= 0x0213DB00;
_ZN6Thwomp14updateDefeatedEv							= 0x0213E1B0;
_ZN6Thwomp18updateDefeatedMegaEv						= 0x0213E170;
_ZN6Thwomp10onBlockHitEv								= 0x0213E1F0;
_ZN6Thwomp12onStarmanHitEv								= 0x0213E248;
_ZN6Thwomp9onMegaHitEv									= 0x0213E278;
_ZN6Thwomp12onMegaKickedEv								= 0x0213E260;
_ZN6Thwomp14onBlueShellHitEv							= 0x0213E230;
_ZN6Thwomp13loadResourcesEv								= 0x0213E364;

_ZNK6Thwomp21spawnLandingParticlesEv					= 0x0213DF50;
_ZN6Thwomp11switchStateERKMS_FbvE						= 0x0213E2D8;
_ZN6Thwomp11updateStateEv								= 0x0213E290;
_ZN6Thwomp9idleStateEv									= 0x0213E0CC;
_ZN6Thwomp10alertStateEv								= 0x0213E04C;
_ZN6Thwomp11attackStateEv								= 0x0213DFA8;
_ZN6Thwomp9fallStateEv									= 0x0213DE60;
_ZN6Thwomp9landStateEv									= 0x0213DDEC;
_ZN6Thwomp9riseStateEv									= 0x0213DD74;

_ZN6Thwomp12shakeOffsetsE								= 0x0213F1C0;
_ZN6Thwomp12attackRangesE								= 0x0213F1B8;
_ZN6Thwomp12bottomSensorE								= 0x0213F1D8;
_ZN6Thwomp9topSensorE									= 0x0213F1E8;
_ZN6Thwomp18activeColliderInfoE							= 0x0213F1F8;
_ZN6Thwomp7profileE										= 0x0213F6D0;

_ZN6Thwomp5sIdleE										= 0x0213FAA0;
_ZN6Thwomp6sAlertE										= 0x0213FAA8;
_ZN6Thwomp7sAttackE										= 0x0213FA98;
_ZN6Thwomp5sFallE										= 0x0213FA90;
_ZN6Thwomp5sLandE										= 0x0213FAB8;
_ZN6Thwomp5sRiseE										= 0x0213FAB0;

_ZTV6Thwomp												= 0x0213F6E8;


/*----------------------------------------------------------------*/
/*------------------------- giant thwomp -------------------------*/
/*----------------------------------------------------------------*/

_ZN13GiantThwompD0Ev									= 0x0213E4F0;
_ZN13GiantThwompD1Ev									= 0x0213E45C;
_ZN13GiantThwompD2Ev									= 0x0213E45C;

_ZN13GiantThwomp9topSensorE								= 0x0213F1C8;
_ZN13GiantThwomp18activeColliderInfoE					= 0x0213F214;
_ZN13GiantThwomp7profileE								= 0x0213F6DC;

_ZTV13GiantThwomp										= 0x0213F804;


/* arm9_ov34 */

/*----------------------------------------------------------------*/
/*------------------------- fence koopa --------------------------*/
/*----------------------------------------------------------------*/

_ZN10FenceKoopaD0Ev										= 0x02141EE8;
_ZN10FenceKoopaD1Ev										= 0x02141E80;
_ZN10FenceKoopaD2Ev										= 0x02141E80;
_ZN10FenceKoopa8onCreateEv								= 0x021424FC;
_ZN10FenceKoopa9onDestroyEv								= 0x02142214;
_ZN10FenceKoopa8onRenderEv								= 0x02142220;
_ZN10FenceKoopa14pendingDestroyEv						= 0x0214221C;
_ZN10FenceKoopa17onUserHeapCreatedEv					= 0x02142F50;
_ZN10FenceKoopa10updateMainEv							= 0x021424A0;
_ZN10FenceKoopa10onBlockHitEv							= 0x021421A0;
_ZN10FenceKoopa9onStompedEv								= 0x02142408;
_ZN10FenceKoopa12damagePlayerER14ActiveColliderR6Player	= 0x02142374;
_ZN10FenceKoopa6defeatElllh								= 0x02142450;
_ZN10FenceKoopa9loadModelEv								= 0x02142FD0;
_ZN10FenceKoopa13loadResourcesEv						= 0x02142FA8;

_ZN10FenceKoopa14activeCallbackER14ActiveColliderS1_	= 0x02141F58;
_ZN10FenceKoopa18setMaterialPaletteER8ModelAnmmm		= 0x02142104;
_ZNK10FenceKoopa17checkAdjacentTileERK11PointSensor		= 0x02142138;
_ZN10FenceKoopa11switchStateEMS_FbvE					= 0x02142E5C;
_ZN10FenceKoopa11updateStateEv							= 0x02142E20;

_ZN10FenceKoopa20horizontalClimbStateEv					= 0x02142C54;
_ZN10FenceKoopa18verticalClimbStateEv					= 0x02142AA0;
_ZN10FenceKoopa23horizontalFlipSideStateEv				= 0x02142900;
_ZN10FenceKoopa26verticalClimbOverGrabStateEv			= 0x021427F0;
_ZN10FenceKoopa26verticalClimbOverJumpStateEv			= 0x02142660;

_ZN10FenceKoopa11paletteBaseE							= 0x021454C0;
_ZN10FenceKoopa14paletteOffsetsE						= 0x02144F4C;
_ZN10FenceKoopa15climbVelocitiesE						= 0x02144F50;
_ZN10FenceKoopa19climbFastVelocitiesE					= 0x02144F54;
_ZN10FenceKoopa14layerRotationYE						= 0x02144F58;
_ZN10FenceKoopa10sideSensorE							= 0x02144F5C;
_ZN10FenceKoopa9topSensorE								= 0x02144F68;
_ZN10FenceKoopa12bottomSensorE							= 0x02144F74;
_ZN10FenceKoopa18activeColliderInfoE					= 0x02144F80;
_ZN10FenceKoopa7profileE								= 0x02145200;

_ZTV12FenceKoopa										= 0x0214520C;


/*----------------------------------------------------------------*/
/*---------------------------- whomp -----------------------------*/
/*----------------------------------------------------------------*/

_ZN5WhompD0Ev								= 0x02143090;
_ZN5WhompD1Ev								= 0x02143070;
_ZN5WhompD2Ev								= 0x02143070;
_ZN5Whomp8onCreateEv						= 0x02143268;
_ZN5Whomp8onRenderEv						= 0x021430B8;
_ZN5Whomp17onUserHeapCreatedEv				= 0x0214379C;
_ZN5Whomp10updateMainEv						= 0x0214323C;
_ZN5Whomp19onMegaWalkShockwaveEv			= 0x0214497C;
_ZN5Whomp13loadResourcesEv					= 0x02144EE8;

_ZN5Whomp11switchStateERKMS_FbvE			= 0x02144E5C;
_ZN5Whomp11updateStateEv					= 0x02144E14;
_ZN5Whomp19createLandParticlesEv			= 0x02144D6C;
_ZN5Whomp7doBreakEh							= 0x02144C08;
_ZN5Whomp14playerCollidedEh					= 0x02144A6C;
_ZN5Whomp24walkCheckPlayerCollisionEv		= 0x021449C4;
_ZN5Whomp25stillCheckPlayerCollisionEv		= 0x02144980;
_ZN5Whomp20playerCollidedDamageEh			= 0x02144800;
_ZN5Whomp26checkPlayerCollisionDamageEv		= 0x02144794;
_ZN5Whomp18updateWalkingSoundEv				= 0x021446C4;
_ZNK5Whomp11noTileBelowERK11PointSensor		= 0x0214467C;

_ZN5Whomp10breakStateEv						= 0x021437F4;
_ZN5Whomp15stillRaiseStateEv				= 0x021438B4;
_ZN5Whomp14stillLandStateEv					= 0x021439A8;
_ZN5Whomp14stillFallStateEv					= 0x02143AD0;
_ZN5Whomp14stillJumpStateEv					= 0x02143C40;
_ZN5Whomp14stillIdleStateEv					= 0x02143D08;
_ZN5Whomp14walkRaiseStateEv					= 0x02143DB0;
_ZN5Whomp13walkLandStateEv					= 0x02143F0C;
_ZN5Whomp13walkFallStateEv					= 0x02144030;
_ZN5Whomp13walkJumpStateEv					= 0x021441B0;
_ZN5Whomp12walkRunStateEv					= 0x02144278;
_ZN5Whomp13walkTurnStateEv					= 0x021443B8;
_ZN5Whomp13walkIdleStateEv					= 0x021444B0;

_ZN5Whomp15shakeVelocitiesE					= 0x02144F9C;
_ZN5Whomp13runVelocitiesE					= 0x02144FA0;
_ZN5Whomp14walkVelocitiesE					= 0x02144FA8;
_ZN5Whomp11tileOffsetsE						= 0x02144FB0;
_ZN5Whomp11coinOffsetsE						= 0x02144FB8;
_ZN5Whomp12attackRangesE					= 0x02144FC0;
_ZN5Whomp12bottomSensorE					= 0x02144FC8;
_ZN5Whomp10sideSensorE						= 0x02144FD4;
_ZN5Whomp18activeColliderInfoE				= 0x02144FE0;
_ZN5Whomp7profileE							= 0x02145388;

_ZN5Whomp9sWalkIdleE						= 0x0214550C;
_ZN5Whomp9sWalkTurnE						= 0x021454C4;
_ZN5Whomp8sWalkRunE							= 0x02145524;
_ZN5Whomp9sWalkJumpE						= 0x0214551C;
_ZN5Whomp9sWalkFallE						= 0x02145514;
_ZN5Whomp9sWalkLandE						= 0x02145504;
_ZN5Whomp10sWalkRaiseE						= 0x021454FC;
_ZN5Whomp10sStillIdleE						= 0x021454F4;
_ZN5Whomp10sStillJumpE						= 0x021454EC;
_ZN5Whomp10sStillFallE						= 0x021454E4;
_ZN5Whomp10sStillLandE						= 0x021454CC;
_ZN5Whomp11sStillRaiseE						= 0x021454DC;
_ZN5Whomp6sBreakE							= 0x021454D4;

_ZTV5Whomp									= 0x02145394;


/* arm9_ov68 */

/*----------------------------------------------------------------*/
/*----------------------------- amp ------------------------------*/
/*----------------------------------------------------------------*/

_ZN3AmpD2Ev											= 0x0217853C;
_ZN3AmpD1Ev											= 0x0217853C;
_ZN3AmpD0Ev											= 0x021785D4;
_ZN3Amp9onDestroyEv									= 0x02178674;
_ZN3Amp14pendingDestroyEv							= 0x0217867C;
_ZN3Amp8onRenderEv									= 0x02178680;
_ZN3Amp12damagePlayerER14ActiveColliderR6Player		= 0x0217882C;
_ZN3Amp10updateMainEv								= 0x021788F4;
_ZN3Amp8onCreateEv									= 0x02178918;
_ZN3Amp17onUserHeapCreatedEv						= 0x02178A94;
_ZN3Amp11electrocuteEPv								= 0x02178B9C;
_ZN3Amp4idleEPv										= 0x02178C78;
_ZN3Amp13updateBobbingEv							= 0x02178D24;
_ZN3Amp11updateStateEPv								= 0x02178D5C;
_ZN3Amp11switchStateEMS_FbPvEPv						= 0x02178DC4;
_ZN3Amp13loadResourcesEv							= 0x02178EA8;

_ZN3Amp7profileE									= 0x02179420;

_ZTV3Amp											= 0x0217942C;


/* arm9_ov98 */

/*----------------------------------------------------------------*/
/*--------------------------- manhole ----------------------------*/
/*----------------------------------------------------------------*/

_ZN7ManholeD2Ev										= 0x02188920;
_ZN7ManholeD1Ev										= 0x02188920;
_ZN7ManholeD0Ev										= 0x021889AC;
_ZN7Manhole14activeCallbackER14ActiveColliderS1_	= 0x02188A40;
_ZN7Manhole9onDestroyEv								= 0x02188A7C;
_ZN7Manhole8onRenderEv								= 0x02188AA0;
_ZN7Manhole10updateMainEv							= 0x02188B10;
_ZN7Manhole8onCreateEv								= 0x02188B4C;
_ZN7Manhole12rollBackwardEPv						= 0x02188C88;
_ZN7Manhole11rollForwardEPv							= 0x02188DC4;
_ZN7Manhole9solidIdleEPv							= 0x02188F0C;
_ZN7Manhole18updateRollingSoundEv					= 0x021890D8;
_ZN7Manhole20getPlatformCollisionEv					= 0x02189150;
_ZN7Manhole11updateStateEPv							= 0x02189198;
_ZN7Manhole11switchStateEMS_FbPvEPv					= 0x021891CC;
_ZN7Manhole17onUserHeapCreatedEv					= 0x021892A0;
_ZN7Manhole13loadResourcesEv						= 0x021892D8;

_ZN7Manhole18activeColliderInfoE					= 0x02189358;
_ZN7Manhole7profileE								= 0x02189870;

_ZTV7Manhole										= 0x0218987C;

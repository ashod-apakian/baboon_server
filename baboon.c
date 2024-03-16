/*-----------------------------------------------------------------------*/
 #include "baboon.h"
/*-----------------------------------------------------------------------*/
 _app app={.magic=0};
/*-----------------------------------------------------------------------*/
 PUB H binerr_user_cntr;
 _curly kerly={.magic=0};
 _jsonunit json_unit;
 _jcursor jay_cur;
 _textreader tr={.magic=0};
 _stunner the_stunner;
/*-----------------------------------------------------------------------*/


 C exp_lut[128]={0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};

 I ulaw_decode[256]=
 {
 -32124,-31100,-30076,-29052,-28028,-27004,-25980,-24956,
 -23932,-22908,-21884,-20860,-19836,-18812,-17788,-16764,
 -15996,-15484,-14972,-14460,-13948,-13436,-12924,-12412,
 -11900,-11388,-10876,-10364, -9852, -9340, -8828, -8316,
  -7932, -7676, -7420, -7164, -6908, -6652, -6396, -6140,
  -5884, -5628, -5372, -5116, -4860, -4604, -4348, -4092,
  -3900, -3772, -3644, -3516, -3388, -3260, -3132, -3004,
  -2876, -2748, -2620, -2492, -2364, -2236, -2108, -1980,
  -1884, -1820, -1756, -1692, -1628, -1564, -1500, -1436,
  -1372, -1308, -1244, -1180, -1116, -1052,  -988,  -924,
   -876,  -844,  -812,  -780,  -748,  -716,  -684,  -652,
   -620,  -588,  -556,  -524,  -492,  -460,  -428,  -396,
   -372,  -356,  -340,  -324,  -308,  -292,  -276,  -260,
   -244,  -228,  -212,  -196,  -180,  -164,  -148,  -132,
   -120,  -112,  -104,   -96,   -88,   -80,   -72,   -64,
    -56,   -48,   -40,   -32,   -24,   -16,    -8,     0,
  32124, 31100, 30076, 29052, 28028, 27004, 25980, 24956,
  23932, 22908, 21884, 20860, 19836, 18812, 17788, 16764,
  15996, 15484, 14972, 14460, 13948, 13436, 12924, 12412,
  11900, 11388, 10876, 10364,  9852,  9340,  8828,  8316,
   7932,  7676,  7420,  7164,  6908,  6652,  6396,  6140,
   5884,  5628,  5372,  5116,  4860,  4604,  4348,  4092,
   3900,  3772,  3644,  3516,  3388,  3260,  3132,  3004,
   2876,  2748,  2620,  2492,  2364,  2236,  2108,  1980,
   1884,  1820,  1756,  1692,  1628,  1564,  1500,  1436,
   1372,  1308,  1244,  1180,  1116,  1052,   988,   924,
    876,   844,   812,   780,   748,   716,   684,   652,
    620,   588,   556,   524,   492,   460,   428,   396,
    372,   356,   340,   324,   308,   292,   276,   260,
    244,   228,   212,   196,   180,   164,   148,   132,
    120,   112,   104,    96,    88,    80,    72,    64,
     56,    48,    40,    32,    24,    16,     8,     0};


 I alaw_decode[256]=
 {
  -5504, -5248,  -6016,  -5760, -4480, -4224, -4992, -4736, -7552, -7296,
  -8064, -7808,  -6528,  -6272, -7040, -6784, -2752, -2624, -3008, -2880,
  -2240, -2112,  -2496,  -2368, -3776, -3648, -4032, -3904, -3264, -3136,
  -3520, -3392, -22016, -20992,-24064,-23040,-17920,-16896,-19968,-18944,
 -30208,-29184, -32256, -31232,-26112,-25088,-28160,-27136,-11008,-10496,
 -12032,-11520,  -8960,  -8448, -9984, -9472,-15104,-14592,-16128,-15616,
 -13056,-12544, -14080, -13568,  -344,  -328,  -376,  -360,  -280,  -264,
   -312,  -296,   -472,   -456,  -504,  -488,  -408,  -392,  -440,  -424,
    -88,   -72,   -120,   -104,   -24,    -8,   -56,   -40,  -216,  -200,
   -248,  -232,   -152,   -136,  -184,  -168, -1376, -1312, -1504, -1440,
  -1120, -1056,  -1248,  -1184, -1888, -1824, -2016, -1952, -1632, -1568,
  -1760, -1696,   -688,   -656,  -752,  -720,  -560,  -528,  -624,  -592,
   -944,  -912,  -1008,   -976,  -816,  -784,  -880,  -848,  5504,  5248,
   6016,  5760,   4480,   4224,  4992,  4736,  7552,  7296,  8064,  7808,
   6528,  6272,   7040,   6784,  2752,  2624,  3008,  2880,  2240,  2112,
   2496,  2368,   3776,   3648,  4032,  3904,  3264,  3136,  3520,  3392,
  22016, 20992,  24064,  23040, 17920, 16896, 19968, 18944, 30208, 29184,
  32256, 31232,  26112,  25088, 28160, 27136, 11008, 10496, 12032, 11520,
   8960,  8448,   9984,   9472, 15104, 14592, 16128, 15616, 13056, 12544,
  14080, 13568,    344,    328,   376,   360,   280,   264,   312,   296,
    472,   456,    504,    488,   408,   392,   440,   424,    88,    72,
    120,   104,     24,      8,    56,    40,   216,   200,   248,   232,
    152,   136,    184,    168,  1376,  1312,  1504,  1440,  1120,  1056,
   1248,  1184,   1888,   1824,  2016,  1952,  1632,  1568,  1760,  1696,
    688,   656,    752,    720,   560,   528,   624,   592,   944,   912,
   1008,   976,    816,    784,   880,   848 };




/*-----------------------------------------------------------------------*/



 V UlawEncode                          (IP pcm16,BP uptr,Z pcminc,Z uinc,H len)
 {
 REG Z longsmp,sign,sample,exponent,mantissa,ulawbyte; //,n
 REG IP sp;
 REG BP up;
 //n=len;
 sp=pcm16;
 up=uptr;
 //while(n--)
 while(len--)
  {
  if((longsmp=*sp)<0) { sign=0x80;   longsmp=-longsmp;  }
  else                { sign=0; }
  if(longsmp>ULAW_MUCLIP)  { longsmp=ULAW_MUCLIP; }
  sample=longsmp+ULAW_BIAS;
  exponent=exp_lut[(sample>>8)&0x7F];
  mantissa=(sample>>(exponent+3))&0x0F;
  ulawbyte=~(sign|(exponent<<4)|mantissa );
  if(1&&ulawbyte==0) { ulawbyte=ULAW_MUZERO;  }
  *up=ulawbyte;
  sp+=pcminc;
  up+=uinc;
  }
 }



 V UlawDecode                          (BP uptr,IP pcm16,Z uinc,Z pcminc,H len)
 {
 REG Z u; //,n
 REG IP sp;
 REG BP up;
 //n=len;
 up=uptr+len*(N)uinc;
 sp=pcm16+len*(N)pcminc;
 //while(n--)
 while(len--)
  {
  up-=uinc;
  sp-=pcminc;
  u=*up;
  if(1&&u==ULAW_MUZERO) { u=0; }
  *sp=ulaw_decode[u];
  }
 }



//-----------------------------------------------------


 V AlawEncode                          (IP pcm16,BP alawp,Z pcminc,Z ainc,H len)
 {
 Z linear,seg;
 B aval,mask;
 static I seg_aend[ALAW_NSEGS]={0x1f,0x3f,0x7f,0xff,0x1ff,0x3ff,0x7ff,0xfff};
 H i;
 for(i=0;i<len;++i)
  {
  linear=(*pcm16)>>3;
  if(linear>=0)  {   mask=0xd5;   }
  else           {   mask=0x55;   linear=-linear-1;   }
  for(seg=0;seg<ALAW_NSEGS&&linear>seg_aend[seg];seg++);
  if(seg>=ALAW_NSEGS)  { aval=(B)(0x7F^mask); }
  else
   {
   aval=(B)seg<<ALAW_SEG_SHIFT;
   if(seg<2) { aval|=(linear>>1)&ALAW_QUANT_MASK;    }
   else      { aval|=(linear>>seg)&ALAW_QUANT_MASK;  }
   aval=(aval^mask);
   }
  *alawp=aval;
  alawp+=ainc;
  pcm16+=pcminc;
  }
 }



 V AlawDecode                          (BP alawp,IP pcm16,Z ainc,Z pcminc,H len)
 {
 B alaw;
 H i;
 for(i=0;i<len;++i)
  {
  alaw=*alawp;
  *pcm16=alaw_decode[alaw];
  alawp+=ainc;
  pcm16+=pcminc;
  }
 }


/*-----------------------------------------------------------------------*/


 B trObjInit                           (_trobj*trobj,VP fmt,...)
 {
 aaVargsf256K(fmt);
 aaMemoryFill(trobj,sizeof(_trobj),0);
 trobj->magic=aaHPP(trObjInit);
 aaStringCopyf(trobj->key,"%s",str256k.buf);
 return RET_YES;
 }




 B trValGet                            (_textreader*textreader,VP val,HP li,BP isqtd,VP fmt,...)
 {
 B ret;
 B value[_32K];
 B isq;
 H line;
 aaVargsf256K(fmt);
 if(li)    { *li=0; }
 if(val)   { aaStringNull(val); }
 if(isqtd) { *isqtd=0; }
 if((ret=aaTextReaderLineFind(textreader,0,&line,value,"%s:",str256k.buf))!=YES) { aaNote(0,"%s %s",arets,str256k.buf); return ret; }
 aaStringIsQuoted(value,0,&isq);
 aaStringUnQuote(value,0,0);
 //    if(1) { appLog(0,F32,"%-2i=%-2i [%s] [%s]",li,is_qtd,key,val); }
 if(li)    { *li=line; }
 if(val)   { aaStringCopy(val,value); }
 if(isqtd) { *isqtd=isq; }
 return ret;
 }




 B trKeyValGet                         (_textreader*textreader,H li,BP isqtd,VP key,VP val)
 {
 B ret;
 B tmp[_32K];
 B value[_32K];
 B isq;
 H pos;
 if(val)   { aaStringNull(val); }
 if(isqtd) { *isqtd=0; }
 if(key)   { aaStringNull(key); }
 if((ret=aaTextReaderLineGet(textreader,li,0,tmp))!=YES) { oops; }
 if(aaStringFindChar(tmp,0,&pos,':',YES,0,YES)!=YES) { oof; }
 if(key) {  aaStringNCopy(key,tmp,pos,YES); }
 aaStringCopy(value,&tmp[pos+1]);
 aaStringIsQuoted(value,0,&isq);
 aaStringUnQuote(value,0,0);
 //if(1) { appLog(0,F32,"%-2i=%-2i [%s] [%s]",tr.li,is_qtd,key,val); }
 if(isqtd) { *isqtd=isq; }
 if(val)   { aaStringCopy(val,value); }
 return RET_YES;
 }


/*-----------------------------------------------------------------------*/


 B stunnerNew                          (_stunner*stunner)
 {
 if(stunner==NULL) { return RET_MISSINGPARM; }
 aaMemoryFill(stunner,sizeof(_stunner),0);
 stunner->magic=aaHPP(stunnerNew);
 stunner->stage=100;
 return RET_YES;
 }


 B stunnerDelete                       (_stunner*stunner)
 {
 if(stunner==NULL) { return RET_MISSINGPARM; }
 if(stunner->magic!=aaHPP(stunnerNew)) { return RET_NOTINITIALIZED; }
 if(stunner->dns.handle)     {  aaNetDnsDestroy(stunner->dns.handle);  stunner->dns.handle=0;  }
 if(stunner->stun.handle)    {  aaNetStunClientDestroy(stunner->stun.handle);  stunner->stun.handle=0;  }
 if(stunner->udp[0].handle)  {  aaNetUdpDestroy(stunner->udp[0].handle);  stunner->udp[0].handle=0;  }
 aaMemoryFill(stunner,sizeof(_stunner),0);
 return RET_YES;
 }




 B stunnerYield                        (_stunner*stunner,H ita)
 {
 B ret;
 H i,pos;
 B txt[_1K];
 B etc[8][_1K];

 if(stunner==NULL) { return RET_MISSINGPARM; }
 if(stunner->magic!=aaHPP(stunnerNew)) { return RET_NOTINITIALIZED; }
 if(ita==0) { ita=1; }
 while(ita--)
  {
  switch(stunner->stage)
   {
   case 100:
   stunner->stage=150;
   break;

   case 150:
   if((ret=aaNetDnsCreate(&stunner->dns.handle,"stun.l.google.com",aa_DNS_MODE_A,1))!=YES) { oops; }
   aaNetDnsStatus(stunner->dns.handle,&stunner->dns.status);
   stunner->stage=200;
   break;

   case 200:
   aaNetDnsStatus(stunner->dns.handle,&stunner->dns.status);
   if(stunner->dns.status.is_inprogress==YES) { break; }
   if(stunner->dns.status.is_notfound)  {   aaDebugf("STUNNER: %s not found",stunner->dns.status.query);      stunner->stage=230;    break;    }
   if(stunner->dns.status.is_failed)    {   aaDebugf("STUNNER: %s lookup failed",stunner->dns.status.query);  stunner->stage=230;    break;    }
   stunner->dns_index=0;
   stunner->stage=210;
   break;

   case 210:
   i=stunner->dns_index;
   if(i>=32) { aaDebugf("STUNNER: all dns_index's tested"); stunner->stage=330; break; }
   if(stunner->dns.status.type[i]==0) { stunner->dns_index++; break; }
   aaNetIpToString(stunner->dns.status.ip[i],txt);
   if((ret=aaNetUdpCreateAny(&stunner->udp[0].handle,0,1024,38192))!=YES) { oops; }
   aaNetUdpStatus(stunner->udp[0].handle,&stunner->udp[0].status);
   aaNetAdrToString(&stunner->udp[0].status.local_adr,txt);
   aaDebugf("STUNNER: created udp %s",txt);
   if((ret=aaNetStunClientCreate(&stunner->stun.handle,stunner->udp[0].handle,stunner->dns.status.ip[i],19302))!=YES) { oops; }
   stunner->stage=220;
   break;


   case 220:
   aaNetUdpStatus(stunner->udp[0].handle,&stunner->udp[0].status);
   if((ret=aaNetStunClientStatus(stunner->stun.handle,&stunner->stun.status))!=YES) { oops; }
   if(stunner->stun.status.is_complete!=YES) { break; }
   aaNetAdrToString(&stunner->stun.status.local_adr,etc[0]);
   aaNetAdrToString(&stunner->stun.status.server_adr,etc[1]);
   aaNetAdrToString(&stunner->stun.status.other_adr,etc[2]);
   aaNetAdrToString(&stunner->stun.status.mapped_adr,etc[3]);
   aaNetAdrToString(&stunner->stun.status.remapped_adr,etc[4]);
   aaStringCopy(stunner->dot,etc[4]);
   appLog(0,F32,"STUNNER: type=%i",stunner->stun.status.type);
   appLog(0,F32,"STUNNER: loc=%s",etc[0]);
   appLog(0,F32,"STUNNER: srv=%s",etc[1]);
   appLog(0,F32,"STUNNER: oth=%s",etc[2]);
   appLog(0,F32,"STUNNER: map=%s",etc[3]);
   appLog(0,F32,"STUNNER: rem=%s",etc[4]);
   aaStringFindChar(stunner->dot,0,&pos,':',YES,0,YES);;
   stunner->dot[pos]=0;
   appLog(0,F32,"STUNNER: dot=%s",stunner->dot);
   appLog(0,F32,"STUNNER: completed");
   appLog(0,F32," ");
   ///oof;
   aaNetStunClientDestroy(stunner->stun.handle);
   stunner->stun.handle=0;
   aaNetUdpDestroy(stunner->udp[0].handle);
   stunner->udp[0].handle=0;
   stunner->stage=230;
   break;

   case 230:
   case 330:
   aaNetDnsDestroy(stunner->dns.handle);
   stunner->dns.handle=0;
   stunner->is_finished=YES;
   if(stunner->stage==230) { stunner->is_success=YES; stunner->stage=500; }
   else                    { stunner->is_failure=YES; stunner->stage=666; }
   break;
   }
  }
 return RET_YES;
 }

/*-----------------------------------------------------------------------*/


 B aaSdpParse                          (_sdp*sdp,H bytes,VP data)
 {
 B ch,bufa[_2K],bufb[_2K];
 H count,pos,t,len;
 _offlen offlen[32];
 BP bp;

 if(sdp==NULL)            { return RET_MISSINGPARM;   }
 if(bytes!=0&&data==NULL) { return RET_MISSINGPARM;   }
 if(bytes==0)             { aaStringLen(data,&bytes); }
 aaMemoryFill(sdp,sizeof(_sdp),0);
 aaStringSplitChar(data,bytes,'=',NO,YES,0,YES,bufa,bufb);
 aaStringFirstCharNonVisibleRemove(bufa,0);
 aaStringFirstCharNonVisibleRemove(bufb,0);
 aaStringCopyf(sdp->type,"%s",bufa);
 aaStringCopyf(sdp->value,"%s",bufb);
 aaMemoryFill(&offlen,sizeof(offlen),0);
 count=0;
 if(bufa[1]==NULL_CHAR)
  {
  bp=(BP)sdp->value;
  pos=0;
  sdp->token_offlen[count].off=pos;
  sdp->token_offlen[count].len=0;
  while(1)
   {
   ch=bp[pos];
   len=pos-sdp->token_offlen[count].off;
   if(ch==NULL_CHAR)
    {
    if(len>0) { sdp->token_offlen[count].len=len;   count++;     pos++;     }
    break;
    }
   if(ch!=SPACE_CHAR) { pos++; continue; }
   sdp->token_offlen[count].len=len;
   count++;
   pos++;
   sdp->token_offlen[count].off=pos;
   sdp->token_offlen[count].len=0;
   }
  sdp->token_count=count;
  for(t=0;t<sdp->token_count;t++)  { aaStringNCopy(sdp->token[t],&bp[sdp->token_offlen[t].off],sdp->token_offlen[t].len,YES); }
  }
 return RET_YES;
 }

/*-----------------------------------------------------------------------*/


 B aaNetSipResultReadFromString        (_sipresult*sipresult,H bytes,VP str)
 {
 H chars,val;
 B txt[_2K],token[2][_2K];
 if(sipresult==NULL) { return RET_BADPARM; }
 sipresult->code=0;
 sipresult->is_success=NO;
 sipresult->is_failed=NO;
 if(str==NULL) { return RET_BADPARM; }
 if(bytes==0)  { aaStringLen(str,&bytes); }
 if(bytes==0)  { return RET_BADPARM; }
 chars=bytes;
 aaMemoryFill(sipresult,sizeof(_sipresult),0);
 if(chars>512) { sipresult->is_failed=YES; return RET_FAILED; }
 aaStringCopy(txt,str);
 if(chars>1)
  {
  aaStringReplaceChar(txt,chars,HTAB_CHAR,SPACE_CHAR);
  aaStringRemoveMultipleSpaces(txt,chars,NO);
  aaStringLen(txt,&chars);
  }
 if(chars<11)           {  sipresult->is_failed=YES; return RET_FAILED; }
 if(txt[7]!=SPACE_CHAR) {  sipresult->is_failed=YES; return RET_FAILED; }
 if(aaStringIsNumerical(&txt[8],0,0,3)!=RET_YES)  {      sipresult->is_failed=YES;  return RET_FAILED; }
 aaStringNCopy(&token[0],&txt[0],7,YES);
 aaStringNCopy(&token[1],&txt[8],3,YES);
 aaStringLower(token[0],0,NULL);
 aaStringToNumber(token[1],3,&val,NULL,0,0);
 sipresult->code=val;
 sipresult->is_success=YES;
 return RET_YES;
 }





 B aaNetSipHeaderReadFromString        (_sipheader*sipheader,H bytes,VP str)
 {
 if(sipheader==NULL) { return RET_BADPARM; }
 sipheader->is_success=NO;
 sipheader->is_failed=NO;
 sipheader->field[0]=NULL_CHAR;
 sipheader->data_bytes=0;
 sipheader->data[0]=NULL_CHAR;
 if(str==NULL) { return RET_BADPARM; }
 if(bytes==0)  { aaStringLen(str,&bytes); }
 if(bytes==0)  { sipheader->is_success=YES;  return RET_YES;  }
 aaStringSplitChar(str,bytes,':',NO,YES,0,YES,sipheader->field,sipheader->data);
 aaStringFirstCharNonVisibleRemove(sipheader->data,0);
 aaStringLen(sipheader->data,&sipheader->data_bytes);
 sipheader->is_success=YES;
 return RET_YES;
 }



/*-----------------------------------------------------------------------*/




 V aaMain                              (V)
 {
 appStart();
 curlyStart(&kerly);
 stunnerNew(&the_stunner);
 while(appYield()==YES)
  {
  curlyYield(&kerly);
  if(app.do_quit==2) { break; }
  if(0&&aa_stage!=40&&aa_msrunning>12000) { aaQuit(); break; }
  stunnerYield(&the_stunner,2);
  if(the_stunner.is_finished!=YES) { continue; }
  appEngine();
  }
 stunnerDelete(&the_stunner);
 curlyStop(&kerly);
 appStop();
 }






 B appStart                            (V)
 {
 B ret;
 _size s1;
 _rect r1;
 aaFocusToDbg(0);
 OutputDebugString(".,;DBGVIEWCLEAR");
 if(1) { aaDebugfPrefix(".,;"); }
 aaMemoryFill(&app,sizeof(_app),0);
 app.magic=aaHPP(appStart);
 if((ret=aaSysInfoGet(&app.si))!=YES)        { oops; }
 if((ret=aaDisplayInfoGet(&app.di,88))!=YES) { oops; }
 if((ret=aaInfoGet(&app.info,F32))!=YES)     { oops; }
 app.tray_icon_index=0;
 app.tray_icon_ms=aaMsRunning();
 aaSizeSet(&s1,80,80);
 if((ret=aaSurfaceCreate(&app.surf.handle,&s1))!=YES) { oops; }
 if((ret=aaSurfaceVisualize(app.surf.handle,YES-0,0))!=YES) { oops; }
 if((ret=aaSurfaceIconSetUsingResource(app.surf.handle,1004,0))!=YES) { }//oops; }
 aaSurfaceTitleSet(app.surf.handle,"Baboon Server");
 aaSurfaceStatus(app.surf.handle,&app.surf.status);
 if((ret=aaSurfaceTraySet(app.surf.handle,1003+(app.tray_icon_index%2),"%s %s",app.surf.status.title,DEV_VERSION))!=YES) { oops; }
 aaSurfaceStatus(app.surf.handle,&app.surf.status);
 app.canvas_update_ms=aaMsRunning();
 aaSizeSet(&s1,880,620);
 aaRectSet(&r1,app.di.desktop_rect.w-s1.w-5, app.di.desktop_rect.h-s1.h-5, s1.w,s1.h);
 if((ret=aaSurfaceCreate(&app.canvas.handle,&s1))!=YES) { oops; }
 if((ret=aaSurfaceVisualize(app.canvas.handle,YES-1,0))!=YES) { oops; }
 aaSurfaceTitleSet(app.canvas.handle,"%s %s",app.surf.status.title,DEV_VERSION);
 aaSurfaceRectSet(app.canvas.handle,&r1);
 aaSurfaceFillFrame(app.canvas.handle,0,2,&col_gray[2],&col_pastelblue[24]);
 aaSurfaceShow(app.canvas.handle,YES);
 aaSurfaceFocus(app.canvas.handle);
 if(0) { aaSurfaceTransparencySet(app.canvas.handle,190,0); }
 aaSurfaceStatus(app.canvas.handle,&app.canvas.status);
 if((ret=aaFontCreate(&app.font[0].handle,"consolas",0,-13,172,0,0,6,0))!=YES) { oops; }
 aaFontStatus(app.font[0].handle,&app.font[0].status);
 if((ret=aaNetWebsocketServerNew(&app.the_server,0,8082,SERVER_MAX_CALLS))!=YES) { oops; }
 aaNetStatus(&app.ns);
 app.global_id_counter=100000LL;
 return RET_YES;
 }




 B appStop                             (V)
 {
 if(app.magic!=aaHPP(appStart)) { return RET_NOTINITIALIZED; }
 if(app.surf.handle)             {  aaSurfaceDestroy(app.surf.handle);  }
 if(app.canvas.handle)           {  aaSurfaceDestroy(app.canvas.handle);  }
 if(app.font[0].handle)          {  aaFontDestroy(app.font[0].handle); app.font[0].handle=0; }
 aaNetWebsocketServerDelete(&app.the_server);
 aaFocusToCodeBlocks();
 aaMemoryFill(&app,sizeof(_app),0);
 return RET_YES;
 }







 B appYield                            (V)
 {
 B ret;
 _size s1;
 _rect r1;
 H i;
 B ir;
 Q el;

 if(app.magic!=aaHPP(appStart)) { return RET_NOTINITIALIZED; }
 if((ret=aaYield(1200))!=YES)    { return ret; }
 aaSurfaceStatus(app.canvas.handle,&app.canvas.status);
 aaSurfaceStatus(app.surf.handle,&app.surf.status);
 if(aaMathRand32(0,50)==0)  {  aaNetStatus(&app.ns);  }
 if(app.surf.status.is_systray)
  {
  el=aa_msrunning-app.canvas_update_ms;
  if(el>=450)
   {
   if(1) { appStats(); }
   app.canvas_update_ms=aa_msrunning;
   }
  el=aa_msrunning-app.tray_icon_ms;
  if(el>=409)
   {
   if(aa_display_change_counter)
    {
    if((ret=aaInfoGet(&app.info,F32))!=YES) { oops; }
    aaSizeSet(&s1,app.canvas.status.size.w,app.canvas.status.size.h);
    aaRectSet(&r1,app.info.display_info.tray_rect.x-s1.w-4,app.info.display_info.tray_rect.y-s1.h-4,s1.w,s1.h);
    aaSurfaceRectSet(app.canvas.handle,&r1);
    aaSurfaceStatus(app.canvas.handle,&app.canvas.status);
    aa_display_change_counter=0;
    }
   app.tray_icon_index++;
   if((ret=aaSurfaceTraySet(app.surf.handle,1003+(app.tray_icon_index%2),"%s %s",app.surf.status.title,DEV_VERSION))!=YES)
    {
    aaDebugf("surfacetrayset failure");
    }
   app.tray_icon_ms=aa_msrunning;
   }
  if(aaSurfaceIsTrayClicked(app.surf.handle,0,&ir)==RET_YES)
   {
   if(ir)    {    if(app.do_quit==0) { app.do_quit=1; }    }
   else
    {
    if(app.canvas.status.is_shown)   { aaSurfaceShow(app.canvas.handle,NO);  }
    else                             { aaSurfaceShow(app.canvas.handle,YES); aaSurfaceFocus(app.canvas.handle); }
    aaSurfaceStatus(app.canvas.handle,&app.canvas.status);
    }
   if((ret=aaSurfaceTrayClickClear(app.surf.handle))!=YES) { oops; }
   aaSurfaceStatus(app.surf.handle,&app.surf.status);
   }
  }
 if(the_stunner.is_finished==YES)
  {
  for(i=0;i<16;i++)
   {
   if((i%4)==3) {   aaNetWebsocketServerYield(&app.the_server);  }
   if((i%3)==2) {   serverProcessor();  }
   }
  }
 return RET_YES;
 }





 B appLog                              (H index,H lines,VP fmt,...)
 {
 H till,j;
 aaVargsf128K(fmt);
 if(app.magic!=aaHPP(appStart)) { return RET_NOTINITIALIZED; }
 if(index>=aaElementCount(app.bilboard)) { return RET_BOUNDS; }
 if(lines==F32) { lines=aaElementCount(app.bilboard)-index; }
 if(lines==0)   { return RET_YES; }
 till=index+lines;
 if(till>aaElementCount(app.bilboard)) { return RET_BOUNDS; }
 if(lines>1)
  {
  for(j=(index+1);j<till;j++) { aaStringCopy(app.bilboard[j-1],app.bilboard[j]); }
  }
 aaStringCopyf(app.bilboard[till-1],"%s",str128k.buf);
 aaDebugf("%s",str128k.buf);
 return RET_YES;
 }




 B appStats                            (V)
 {
 _rect r1;
 Q msr;
 D rate;
 B etc[_8K],txt[_2K];
 H i,ecst,shade_throb[4]={0,2,3,2};
 _memorystatus memsta;
 S H this_cycle=0;

 if(app.magic!=aaHPP(appStart)) { return RET_NOTINITIALIZED; }
 aaMemoryStatus(&memsta);
 aaSurfaceStatus(app.canvas.handle,&app.canvas.status);
 aaSurfaceStatus(app.surf.handle,&app.surf.status);
 aaRectSet(&r1,4,4,app.canvas.status.size.w-8,app.canvas.status.size.h-8);
 aaStringNull(etc);
 msr=aa_msrunning;
 if(msr<60000)     {     aaStringCopyf(txt,"secs=%.2f",msr/1000.0);    }   else
 if(msr<3600000)   {     aaStringCopyf(txt,"mins=%.2f",msr/60000.0);   }   else
                   {     aaStringCopyf(txt,"hrs=%.2f",msr/3600000.0);  }
 aaStringCopyf(etc,"%s %-13s ",app.canvas.status.title,txt);
 aaStringAppendf(etc,"Cycle=%-10I64d ",aa_cycle);
 aaStringAppendf(etc,"stage=%-5i ",aa_stage);
 aaStringAppendf(etc,"pid=%u\n",app.info.sys_info.process_id);
 aaStringAppendf(etc,"\n");
 aaStringAppendf(etc,"cur_cpu_load=%-6.2f   ",aa_curcpuload);
 aaStringAppendf(etc,"avg_cpu_load=%-6.2f\n",aa_avgcpuload);
 aaStringAppendf(etc,"cur_app_load=%-6.2f   ",aa_curproload);
 aaStringAppendf(etc,"avg_app_load=%-6.2f\n",aa_avgproload);
 aaStringAppendf(etc,"\n");
 aaStringAppendf(etc,"ask_herz=%-6.1f  ",aa_askhz);
 aaStringAppendf(etc,"cur_herz=%-6.1f  ",aa_curhz);
 aaStringAppendf(etc,"eve_wai=%-3i  bin_err=%i\n",aa_ie_events_waiting,binerr_user_cntr);
 aaStringAppendf(etc,"note:  show_count=%-3i  ",aa_note_show_count);
 aaStringAppendf(etc,"miss_count=%-3i  ",aa_note_miss_count);
 aaStringAppendf(etc,"kill_count=%-3i ",aa_note_kill_count);
 aaStringAppendf(etc,"\n");
 aaStringAppendf(etc,"copied=%.2fG   ",memsta.bytes_copied/1073741824.0);
 rate=((D)memsta.bytes_copied/1048576.0)/aa_secsrunning;
 aaStringAppendf(etc,"copy=%.2fM/s   ",rate);
 aaStringAppendf(etc,"filled=%.2fG   ",memsta.bytes_filled/1073741824.0);
 rate=((D)memsta.bytes_filled/1048576.0)/aa_secsrunning;
 aaStringAppendf(etc,"fill=%.2fM/s  ",rate);
 aaStringAppendf(etc,"\n\n");
 aaStringAppendf(etc,"incoming_tcp_ports_inuse=%i  ",app.ns.incoming_tcp_ports_inuse);
 aaStringAppendf(etc,"max_tcp_calls=%i\n",app.ns.max_tcp_calls);
 aaStringAppendf(etc,"tot_out_tcp_call_count=%i    ",app.ns.total_outgoing_tcp_call_count);
 aaStringAppendf(etc,"tot_in_tcp_call_count=%i   ",app.ns.total_incoming_tcp_call_count);
 aaStringAppendf(etc,"tot_tcp_call_count=%i\n",app.ns.total_tcp_call_count);
 aaStringAppendf(etc,"cur_out_tcp_call_count=%i    ",app.ns.current_outgoing_tcp_call_count);
 aaStringAppendf(etc,"cur_in_tcp_call_count=%i   ",app.ns.current_incoming_tcp_call_count);
 aaStringAppendf(etc,"cur_tcp_calls_connected=%i\n",app.ns.current_tcp_calls_connected);
 aaStringAppendf(etc,"\n");
 aaStringAppendf(etc,"tot_tcp_bytes_in=%.2fM    ",app.ns.total_tcp_bytes_in/1048576.0);
 aaStringAppendf(etc,"tot_tcp_bytes_out=%.2fM\n",app.ns.total_tcp_bytes_out/1048576.0);


 aaStringAppendf(etc,"\n");
 aaStringAppendf(etc,"curl calls=%i/%i/%I64d\n",kerly.cur_calls,kerly.max_calls,kerly.tot_calls);

 for(i=0;i<aaElementCount(app.bilboard);i++)  {  aaStringAppendf(etc,"%s\n",app.bilboard[i]);  }
 ecst=aaElementCount(shade_throb);
 aaSurfaceLabel(app.canvas.handle,&r1,&col_pastelblue[28+shade_throb[this_cycle%ecst]],app.font[0].handle,&col_gray[2],4,4,0,0,0,"%s",etc);
 if(app.canvas.status.is_shown)     {    aaSurfaceUpdateAreaAdd(app.canvas.handle,0,YES);    }
 else                               {    aaSurfaceUpdateAreaAdd(app.canvas.handle,0,NO);     }
 this_cycle++;
 return RET_YES;
 }

/*-----------------------------------------------------------------------*/



 H cix;

 V appEngine                           (V)
 {
 H go,to;
 B ret;
 _curlycall*ccall;
 B call_url[_1K];
 B call_cmd[_1K];


 to=1;
 go=0;
 while((go++)<to)
  {
  if(app.do_quit==1) { app.do_quit=2; break;  }
  if(app.is_paused)  { break; }
  switch(aa_stage)
   {
   default:
   if(app.do_quit==0) { app.do_quit=1; }
   break;

   case 0:
   aaStageSet(10);
   break;

   case 10:
   aaStringNull(call_cmd);
   aaStringAppendf(call_cmd,"meth=GET\n");
   aaStringAppendf(call_cmd,"ua=Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.37 (KHTML, like Gecko) Chrome/68.0.3440.106 Mobile Safari/537.37\n");
   aaStringAppendf(call_cmd,"url=https://www.bibliatodo.com/en/the-bible/king-james-version/job-1\n\n");
   if((ret=curlyCallNew(&kerly,&cix,&ccall,0,"%s",call_cmd))!=RET_YES) { oops; }
   aaStageSet(20);
   break;

   case 20:
   if((ret=curlyCallWait(&kerly,cix,&ccall))==RET_NOTREADY) { break; }
   aaDebugf("%i",ccall->http_code);
   aaStageSet(30);
   break;

   case 30:
   break;
   }
  }
 }



/*-----------------------------------------------------------------------*/




 B curlyStart                          (_curly*curly)
 {
 if(curly==NULL) { return RET_MISSINGPARM; }
 aaMemoryFill(curly,sizeof(_curly),0);
 curly->magic=aaHPP(curlyStart);
 curl_global_init(CURL_GLOBAL_ALL);
 curly->share_handle=curl_share_init();
 curl_share_setopt(curly->share_handle,CURLSHOPT_USERDATA,curly);
 curl_share_setopt(curly->share_handle,CURLSHOPT_SHARE,CURL_LOCK_DATA_CONNECT);
 curly->max_calls=aaElementCount(curly->call);
 curly->cur_calls=0;
 aaDebugf("curl=%s",curl_version());
 return RET_YES;
 }




 B curlyStop                           (_curly*curly)
 {
 N ci;
 _curlycall*ccall;
 if(curly==NULL) { return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 for(ci=0;ci<curly->max_calls;ci++)
  {
  ccall=&curly->call[ci];
  if(ccall->magic!=aaHPP(curlyCallNew)) { continue; }
  ccall->el=aaMsRunning()-ccall->ms;
  if(ccall->is_cancel!=YES) { curlyCallCancel(curly,ci); }
  }
 while(1)
  {
  curlyYield(curly);
  if(curly->cur_calls==0&&curly->fin_calls==0) { break; }
  for(ci=0;ci<curly->max_calls;ci++)
   {
   ccall=&curly->call[ci];
   if(ccall->magic!=aaHPP(curlyCallNew)) { continue; }
   if(ccall->is_fin==NO)
    {
    if(ccall->is_cancel!=YES) {  curlyCallCancel(curly,ci);    }
    continue;
    }
   if(curlyCallDelete(curly,ci)!=YES) oof;
   }
  aaYield(5000);
  if(curly->cur_calls!=0) { continue; }
  break;
  }
 curl_share_cleanup(curly->share_handle);
 curl_global_cleanup();
 aaMemoryFill(curly,sizeof(_curly),0);
 return RET_YES;
 }



 B curlyYield                          (_curly*curly)
 {
 N ci;
 _curlycall*ccall;
 if(curly==NULL) { return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 for(ci=0;ci<curly->max_calls;ci++)
  {
  curly->pf_call++;
  curly->pf_call%=curly->max_calls;
  ccall=&curly->call[curly->pf_call];
  if(ccall->magic==0) { continue; }
  if(ccall->thread.handle!=0)  {   aaThreadStatus(ccall->thread.handle,&ccall->thread.status);   }
  ccall->el=aaMsRunning()-ccall->ms;
  break;
  }
 return RET_YES;
 }


/*-----------------------------------------------------------------------*/





 size_t curlyProcRead                  (VP dest,size_t size,size_t nmemb,VP userp)
 {
 B ret;
 _curlycall*ccall;
 Q cando,todo;
 ccall=(_curlycall*)userp;
 appLog(0,F32,"procread %i %i",size,nmemb);
 cando=(Q)size*(Q)nmemb;
 return 0;
 }


/*-----------------------------------------------------------------------*/


 Z curlyProcTrace                      (CURL*handle,curl_infotype type,CP data,Y size,VP ud)
 {
 H pos,off,sl,att;
 N code,ci;
 _curly*curly;
 B etc[_4K];
 B buf[_16K];
 curly=ud;
 for(ci=0;ci<curly->max_calls;ci++)
  {
  if(curly->call[ci].magic==0)            { continue; }
  if(curly->call[ci].curl_handle==handle) { break;    }
  }
 if(ci==curly->max_calls)  {  return 0;  }
 curly->call[ci].el=aaMsRunning()-curly->call[ci].ms;

 UNUSE(data);
 UNUSE(size);
 switch(type)
  {
  default:
  return 0;



  case CURLINFO_TEXT:
  case CURLINFO_SSL_DATA_OUT:
  case CURLINFO_SSL_DATA_IN:
  break;


  case CURLINFO_HEADER_IN:
  case CURLINFO_HEADER_OUT:
  aaStringNCopy(buf,data,size,YES);
  aaStringLen(buf,&sl);
  att=0;
  while(1)
   {
   att++;
   //if(att>=10000) { oof; }
   if(sl==0) { break; }
   if(aaStringFindCharList(buf,sl,&pos,"\r\n",YES,0,YES)!=YES)
    {
    if(type==CURLINFO_HEADER_OUT)    {     curly->call[ci].hdr_o_count++;     }    else
    if(type==CURLINFO_HEADER_IN)     {     curly->call[ci].hdr_i_count++;     }
    break;
    }
   if(pos==0)
    {
    aaStringDeleteChars(buf,sl,0,pos+1);
    aaStringLen(buf,&sl);
    continue;
    }
   buf[pos]=NULL_CHAR;
   if(pos==0) { aaNote(0,"line=%i",__LINE__); ; }
   if(type==CURLINFO_HEADER_OUT)
    {
    curly->call[ci].hdr_o_count++;
    }
   else
   if(type==CURLINFO_HEADER_IN)
    {
    aaStringCopy(etc,buf);
    if(aaStringNICompare(etc,"location:",F32,0)==YES)
     {
     if(aaStringFindChar(etc,0,&off,':',YES,0,YES)==YES)
      {
      aaStringDeleteChars(etc,0,0,off+1);
      aaStringRemoveSpaces(etc,0,1,1);
      aaStringCopy(curly->call[ci].location,etc);
      if(aaStringFindChar(curly->call[ci].location,0,&off,';',YES,0,YES)==YES) {   curly->call[ci].location[off]=NULL_CHAR;      }
      }
     }
    if(aaStringNICompare(etc,"content-type:",F32,0)==YES)
     {
     if(aaStringFindChar(etc,0,&off,':',YES,0,YES)==YES)
      {
      aaStringDeleteChars(etc,0,0,off+1);
      aaStringRemoveSpaces(etc,0,1,1);
      aaStringCopy(curly->call[ci].res_content_type,etc);
      if(aaStringFindChar(curly->call[ci].res_content_type,0,&off,';',YES,0,YES)==YES) {   curly->call[ci].res_content_type[off]=NULL_CHAR;      }
      }
     }
    curly->call[ci].hdr_i_count++;
    }
   aaStringDeleteChars(buf,sl,0,pos+1);
   aaStringLen(buf,&sl);
   }
  if(type==CURLINFO_HEADER_IN)
   {
   if(curly->call[ci].http_code==0)
    {
    curl_easy_getinfo(curly->call[ci].curl_handle,CURLINFO_RESPONSE_CODE,&code);
    curly->call[ci].http_code=(W)code;
    if(curly->call[ci].http_code==100)     {     }
    if(curly->call[ci].http_code!=200)     {     }
    }
   }
  break;




  case CURLINFO_DATA_OUT:
  case CURLINFO_DATA_IN:
  break;
  }
 return 0;
 }


/*-----------------------------------------------------------------------*/


 Y curlyProcWrite                      (CP contents,Y size,Y nmemb,VP ud)
 {
 B ret;
 H left,realsize,mu;
 N ci;
 _curlycall*ccall;
 _curly*curly;
 ccall=(_curlycall*)ud;
 curly=(_curly*)ccall->curly_ptr;
 for(ci=0;ci<curly->max_calls;ci++)
  {
  if(curly->call[ci].magic==0) { continue; }
  if(curly->call[ci].thread.handle==ccall->thread.handle) {  break;   }
  }
 if(ci==curly->max_calls) {  aaNote(0,"line=%i",__LINE__);  }

 curly->call[ci].el=aaMsRunning()-curly->call[ci].ms;

 if(curly->call[ci].is_cancel)
  {
  }
 realsize=0;

 if(!curly->call[ci].is_cancel)
  {
  realsize=size*nmemb;
  if(ccall->mun.bytes==0)
   {
   if((ret=aaMemoryUnitAllocate(&ccall->mun,realsize+_8K))!=YES) { oops; } /// xaa
   left=ccall->mun.bytes-ccall->mun.used;
   }
  left=ccall->mun.bytes-ccall->mun.used;
  mu=ccall->mun.used;
  if((realsize+_2K)>=left)
   {
   if((ret=aaMemoryUnitReAllocate(&ccall->mun,ccall->mun.bytes+realsize+_32K))!=YES) { oops; } /// xaa
   ccall->mun.used=mu;
   }
  if(realsize>0)
   {
   aaMemoryCopy(&ccall->mun.mem[ccall->mun.used],realsize,contents);
   ccall->mun.used+=realsize;
   }
  ccall->mun.mem[ccall->mun.used]=NULL_CHAR;
  }
 return realsize;
 }


/*-----------------------------------------------------------------------*/


 Y curlyProcProgress                   (VP p,D dltot,D dlnow,D ultot,D ulnow)
 {
 _curlycall*ccall;
 _curly*curly;
 N ci;
 UNUSE(dltot);
 UNUSE(dlnow);
 UNUSE(ulnow);
 UNUSE(ultot);
 ccall=(_curlycall*)p;
 curly=(_curly*)ccall->curly_ptr;
 for(ci=0;ci<curly->max_calls;ci++)
  {
  if(curly->call[ci].magic==0) { continue; }
  if(curly->call[ci].thread.handle==ccall->thread.handle) {  break;   }
  }
 if(ci==curly->max_calls) { aaNote(0,"line=%i",__LINE__);  }
 curly->call[ci].el=aaMsRunning()-curly->call[ci].ms;
 if(curly->call[ci].is_cancel)
  {
  return -1;
  }
 if(curly->call[ci].el>aaSecs(60))
  {
  }
 return 0;
 }


/*-----------------------------------------------------------------------*/



 B curlyCallThread                     (H handle)
 {
 B ret;
 _threadunit tu;
 _curly*curly;
 N ci;
 H li;
 B etc[_4K];
 B is_post;
 B url[_8K];
 B post_data[_8K];
 B post_len[_1K];
 B content_type[_1K];
 B refer[_8K];
 B accept[_1K];
 B key[_8K],val[_8K];
 B ua[_1K];
 H socks_port;
 ///B use_tor,use_socks,use_proxy;
 B host[129];
 B cook[_1K];
 B username[_1K];
 B password[_1K];
 B xfer[_1K];
 CURLcode cres;
 N response_code;
 H plen;

 tu.handle=handle;
 if((ret=aaThreadStatus(tu.handle,&tu.status))!=RET_YES) { oops; }
 curly=(_curly*)tu.status.data;
 for(ci=0;ci<curly->max_calls;ci++)
  {
  if(curly->call[ci].magic==0) { continue; }
  if(curly->call[ci].thread.handle==handle) {  break;   }
  }
 if(ci==curly->max_calls) { aaNote(0,"line=%i",__LINE__);  }
 is_post=NO;
 socks_port=0;
 //use_tor=0;
 //use_socks=0;
 //use_proxy=0;
 aaStringNull(refer);
 aaStringNull(accept);
 aaStringNull(url);
 aaStringNull(post_data);
 aaStringNull(post_len);
 aaStringNull(content_type);
 aaStringNull(cook);
 aaStringNull(ua);
 aaStringNull(username);
 aaStringNull(password);
 aaStringNull(xfer);
 for(li=0;li<10;li++)
  {
  if((ret=curlyCallCmdGet(curly,ci,li,key,val))!=YES) {  break;  }
  if(aaStringICompare(key,"meth",0)==YES)
   {
   if(aaStringICompare(val,"post",0)==YES) { is_post=YES; }    else
   if(aaStringICompare(val,"get",0)==YES)  { is_post=NO;  }
   continue;
   }
  //if(aaStringICompare(key,"socks5",0)==YES)   {   aaStringCopy(host,val);   use_socks=5;   continue;   }
  //if(aaStringICompare(key,"socks4",0)==YES)   {   aaStringCopy(host,val);   use_socks=4;   continue;   }
  //if(aaStringICompare(key,"proxy",0)==YES)    {   use_proxy=1;   aaStringCopy(host,val);   continue;   }
  //if(aaStringICompare(key,"proxys",0)==YES)   {   use_proxy=2;   aaStringCopy(host,val);   continue;   }
  if(aaStringICompare(key,"url",0)==YES)            {   aaStringCopy(url,val);          continue;   }
  if(aaStringICompare(key,"contenttype",0)==YES)    {   aaStringCopy(content_type,val); continue;   }
  if(aaStringICompare(key,"accept",0)==YES)         {   aaStringCopy(accept,val);       continue;   }
  if(aaStringICompare(key,"refer",0)==YES)          {   aaStringCopy(refer,val);        continue;   }
  if(aaStringICompare(key,"postdata",0)==YES)       {   aaStringCopy(post_data,val);    continue;   }
  if(aaStringICompare(key,"postlen",0)==YES)        {   aaStringCopy(post_len,val);    continue;   }
  if(aaStringICompare(key,"ua",0)==YES)             {   aaStringCopy(ua,val);    continue;   }
  if(aaStringICompare(key,"cookie",0)==YES)         {   aaStringCopy(cook,val);    continue;   }
  if(aaStringICompare(key,"username",0)==YES)       {   aaStringCopy(username,val);    continue;   }
  if(aaStringICompare(key,"password",0)==YES)       {   aaStringCopy(password,val);    continue;   }
  if(aaStringICompare(key,"xfer",0)==YES)           {   aaStringCopy(xfer,"chunked");   continue;   }
  ///if(key[0]!=0||val[0]!=0) aaEzyLog(&ezy,2,"%i: %s=%s",li,key,val);
  }
 curly->call[ci].curl_handle=curl_easy_init();
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_URL,url);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_DNS_CACHE_TIMEOUT,300L);//360L);
 aaStringCopy(curly->call[ci].url,url);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_SSL_VERIFYPEER,0);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_SSL_VERIFYHOST,0);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_PROXY_SSL_VERIFYPEER,0);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_PROXY_SSL_VERIFYHOST,0);
 while(1)
  {
  if(!cook[0]) { break; }
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_COOKIEJAR,cook);
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_COOKIEFILE,cook);
  break;
  }
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_DEBUGFUNCTION,curlyProcTrace);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_DEBUGDATA,(VP)curly);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_VERBOSE,1);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_NOSIGNAL,1);
 if(1) curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_TIMEOUT_MS,1000*60); // 30000
 if(1) curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_CONNECTTIMEOUT_MS,1000*10);//5000
 curly->call[ci].this_ci=ci;
 if(xfer[0])
  {
  if((ret=curlyCallHeaderAppend(curly,ci,"Transfer-Encoding: chunked"))!=YES)  oops; }
  }
 /*
 if(use_tor)
  {
  aaStringCopyf(etc,"socks5://127.0.0.1:%u",socks_port);
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_PROXY,etc);
  }
 if(use_socks)
  {
  aaStringCopyf(etc,"%s://%s",aaBoolStrings(use_socks==4,"socks4","socks5"),host);
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_PROXY,etc);
  }
 if(use_proxy)
  {
  aaStringCopyf(etc,"%s://%s",aaBoolStrings(use_proxy==1,"http","https"),host);
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_PROXY,etc);
  }
 */
 if(content_type[0])  {  if((ret=curlyCallHeaderAppend(curly,ci,"Content-Type: %s",content_type))!=YES) { oops; }  }
 if(refer[0])         {  if((ret=curlyCallHeaderAppend(curly,ci,"Referer: %s",refer))!=YES)            { oops; }  }
 if(accept[0])        {  if((ret=curlyCallHeaderAppend(curly,ci,"Accept: %s",accept))!=YES)             { oops; }  }
 else                 {  if((ret=curlyCallHeaderAppend(curly,ci,"Accept:"))!=YES)                       { oops; }  }

 if(0)  {  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_ACCEPT_ENCODING,""); }
 else   {  if((ret=curlyCallHeaderAppend(curly,ci,"Accept-Encoding:"))!=YES)  { oops; } }

 if(0)  {  if((ret=curlyCallHeaderAppend(curly,ci,"Accept-Language: en-US,en;q=0.9"))!=YES) { oops; }  }
 else   {  if((ret=curlyCallHeaderAppend(curly,ci,"Accept-Language:"))!=YES)  { oops; } }

 if(is_post)
  {
  if(post_data[0]==NULL_CHAR&&post_len[0]==NULL_CHAR&&xfer[0]!=NULL_CHAR)
   {
   curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_POST, 1L);
   }
  else
   {
   if(post_data[0])
    {
    curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_POSTFIELDS,post_data);
    curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_POSTFIELDSIZE,(long)strlen((CP)post_data));
    }
   if(post_len[0])
    {
    aaStringToNumber(post_len,0,&plen,0,0,0);
    curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_POSTFIELDS,0);
    curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_POSTFIELDSIZE,(long)plen);
    }
   }
  }
 if(ua[0])
  {
  if((ret=curlyCallHeaderAppend(curly,ci,"User-Agent: %s",ua))!=YES) { oops; }
  }
 if(username[0])  {  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_USERNAME,(VP)username);  }
 if(password[0])  {  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_PASSWORD,(VP)password);  }
 if((ret=curlyCallHeaderAppend(curly,ci,"Expect: 100-continue"))!=YES)  { oops; }
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_READFUNCTION,curlyProcRead);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_WRITEFUNCTION,curlyProcWrite);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_WRITEDATA,(VP)&curly->call[ci]);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_XFERINFOFUNCTION,curlyProcProgress);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_XFERINFODATA,(VP)&curly->call[ci]);
 curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_NOPROGRESS,0L);
 if(xfer[0])
  {
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_READFUNCTION,curlyProcRead);
  curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_READDATA, (void *)&curly->call[ci]);
  }
 curly->call[ci].is_working=YES;
 cres=curl_easy_perform(curly->call[ci].curl_handle);
 if(cres!=CURLE_OK)  { curly->call[ci].is_ret=RET_FAILED; }
 else                { curly->call[ci].is_ret=RET_YES;    }
 curly->call[ci].result=cres;
 curly->call[ci].is_working=NO;
 aaStringCopy(curly->call[ci].result_str,(VP)curl_easy_strerror(cres));
 if(cres!=0)
  {
  if(cres==28)  curly->tot_timeouts++;
  else          curly->tot_fails++;
  }
 if(curly->call[ci].http_code==100)
  {
  curl_easy_getinfo(curly->call[ci].curl_handle, CURLINFO_RESPONSE_CODE, &response_code);
  curly->call[ci].http_code=(W)response_code;
  }
 aaFileSaveFromMemory("fuck.json",curly->call[ci].mun.used,curly->call[ci].mun.mem);
 if(curly->call[ci].clist)
  {
  curl_slist_free_all(curly->call[ci].clist);
  curly->call[ci].clist=NULL;
  }
 if(curly->call[ci].curl_handle)
  {
  curl_easy_cleanup(curly->call[ci].curl_handle);
  curly->call[ci].curl_handle=0;
  }
 if(curly->call[ci].result!=0)
  {
  curly->call[ci].is_error=YES;
  }
 if(curly->call[ci].is_fin==NO)
  {
  curly->call[ci].is_fin=YES;
  curly->fin_calls++;
  }
 else
  {
  oof;
  }
 return RET_YES;
 }




/*-----------------------------------------------------------------------*/


 B curlyUserAgentGet                   (H ui,VP ua)
 {
 if(ua==NULL) { return RET_MISSINGPARM; }
 aaStringNull(ua);
 while(1)
  {
  if(ui==0) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Mobile Safari/537.36"); break; }
  if(ui==1) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; Android 6.2; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/68.0.3440.106 Mobile Safari/537.36"); break; }
  if(ui==2) { aaStringCopyf(ua,"Mozilla/5.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/5.0)"); break; }
  if(ui==3) { aaStringCopyf(ua,"Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; Media Center PC)"); break; }
  if(ui==4) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; U; Android 4.0.3; ko-kr; LG-L160L Build/IML74K) AppleWebkit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30"); break; }
  if(ui==5) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; U; Android 4.0.3; de-ch; HTC Sensation Build/IML74K) AppleWebKit/534.30 (KHTML, like Gecko) Version/4.0 Mobile Safari/534.30"); break; }
  if(ui==6) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; U; Android 2.3; en-us) AppleWebKit/999+ (KHTML, like Gecko) Safari/999.9"); break; }
  if(ui==7) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; U; Android 2.3.5; zh-cn; HTC_IncredibleS_S710e Build/GRJ90) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1"); break; }
  if(ui==8) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; U; Android 2.3.5; en-us; HTC Vision Build/GRI40) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1"); break; }
  if(ui==9) { aaStringCopyf(ua,"Mozilla/5.0 (Linux; U; Android 2.3.4; fr-fr; HTC Desire Build/GRJ22) AppleWebKit/533.1 (KHTML, like Gecko) Version/4.0 Mobile Safari/533.1"); break; }
  return RET_FAILED;
  }
 return RET_YES;
 }



/*-----------------------------------------------------------------------*/




 B curlyCallNew                        (_curly*curly,HP index,_curlycall**ccall,VP fmt,...)
 {
 B ret;
 N ci;
 if(curly==NULL) { return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 if(index) { *index=0; }
 aaVargsf8K(fmt);
 if(ccall) { *ccall=NULL; }
 for(ci=0;ci<curly->max_calls;ci++)
  {
  if(curly->call[ci].magic==0)  { break; }
  }
 if(ci==curly->max_calls) { return RET_FAILED; }
 if(curly->call[ci].is_working) oof;
 if(curly->call[ci].is_fin==YES) oof;
 if(curly->call[ci].is_cancel) oof;
 aaMemoryFill(&curly->call[ci],sizeof(_curlycall),0);
 curly->call[ci].magic=aaHPP(curlyCallNew);
// curly->call[ci].stage=0;
 curly->call[ci].curly_ptr=curly;
 curly->call[ci].ms=aaMsRunning();
 curly->call[ci].http_code=0;
 aaStringNCopy(curly->call[ci].cmd,str8k.buf,str8k.len,YES);
 if((ret=aaThreadCreateRelayed(&curly->call[ci].thread.handle,curlyCallThread,(H)curly,0,NULL,YES-1))!=YES)
  {
  aaThreadDestroy(curly->call[ci].thread.handle);
  if(curlyCallDelete(curly,ci)!=YES) oof;
  return ret;
  }
 if((ret=aaThreadStatus(curly->call[ci].thread.handle,&curly->call[ci].thread.status))!=YES) { oops; }
 curly->cur_calls++;
 curly->tot_calls++;
 if(index) { *index=ci; }
 if(ccall) { *ccall=&curly->call[ci]; }
 return RET_YES;
 }



 B curlyCallDelete                     (_curly*curly,H index)
 {
 N ci;
 H go;
 if(curly==NULL)              { oof; return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 ci=(N)index;
 if(ci>=curly->max_calls)     { return RET_BADHANDLE; }
 if(curly->call[ci].magic==0) { return RET_BADHANDLE; }
 if(curly->call[ci].thread.handle!=0)
  {
  if(curly->call[ci].is_fin==NO)
   {
   aaThreadExit(curly->call[ci].thread.handle);
   }
  aaThreadDestroy(curly->call[ci].thread.handle);
  for(go=0;go<400;go++)
   {
   if(curly->call[ci].is_fin) { break; }
   aaSleep(3);
   if((go%100)==99) { }
   }
  if(go==1000) { }
  }
 if(curly->call[ci].clist)   {   curly->call[ci].clist=0;   }
 if(curly->call[ci].curl_handle!=0)   {   curl_easy_cleanup(curly->call[ci].curl_handle);   }
 if(curly->call[ci].mun.bytes)
  {
  if(aaMemoryUnitRelease(&curly->call[ci].mun)!=YES) { oof; } /// xaa
  }
 if(curly->call[ci].is_fin==YES)
  {
  curly->fin_calls--;
  if(curly->fin_calls<0)   {   curly->fin_calls=0;   }
  }
 aaMemoryFill(&curly->call[ci],sizeof(_curlycall),0);
 curly->cur_calls--;
 return RET_YES;
 }




 B curlyCallCancel                     (_curly*curly,H index)
 {
 N ci;
 _curlycall*ccall;
 if(curly==NULL) { return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 ci=(N)index;
 if(ci>=curly->max_calls) { return RET_BADHANDLE; }
 if(curly->call[ci].magic==0) { return RET_BADHANDLE; }
 ccall=&curly->call[ci];
 ccall->is_cancel=YES;
 return RET_YES;
 }



 B curlyCallCmdGet                     (_curly*curly,H index,H line,VP key,VP val)
 {
 B ret;
 H ci,sl,lines;
 B buf[_8K];
 H line_offs[1000];
 H line_lens[1000];
 if(key) { aaStringNull(key); }
 if(val) { aaStringNull(val); }
 ci=index;
 aaStringLen(curly->call[ci].cmd,&sl);
 if((ret=aaStringLineCountGetToBuffer(curly->call[ci].cmd,sl,&lines,1000,line_offs,line_lens))!=YES) { oops;  }
 if(line>lines) {  return RET_BOUNDS; }
 aaStringNCopy(buf,&curly->call[ci].cmd[line_offs[line]],line_lens[line],YES);
 if(line_lens[line]>0)
  {
  if((ret=aaStringSplitChar(buf,line_lens[line],'=',NO,YES,0,YES,key,val))!=YES)  { oops; }
  }
 return YES;
 }


/*-----------------------------------------------------------------------*/




 B curlyCallHeaderAppend               (_curly*curly,H index,VP fmt,...)
 {
 N ci;
 B etc[_1K];
 Z res;
 if(curly==NULL) { return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 aaVargsf8K(fmt);
 ci=(N)index;
 if(ci>=curly->max_calls)        { return RET_BADHANDLE; }
 if(curly->call[ci].magic==0)    { return RET_BADHANDLE; }
 if(curly->call[ci].is_working)  { return RET_INUSE;  }
 if(curly->call[ci].is_fin==YES) { return RET_ALREADYSTARTED; }
 aaStringCopyf(etc,"%s",str8k.buf);
 curly->call[ci].clist=curl_slist_append(curly->call[ci].clist,(CP)etc);
 res=curl_easy_setopt(curly->call[ci].curl_handle,CURLOPT_HTTPHEADER,curly->call[ci].clist);
 if(res!=0) { return RET_FAILED; }
 return RET_YES;
 }




 B curlyCallWait                       (_curly*curly,H index,_curlycall**curlycallptr)
 {
 H ci;
 _curlycall*ccall;
 if(curlycallptr) { *curlycallptr=NULL; }
 if(curly==NULL)              { oof; return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 ci=(N)index;
 if((N)ci>=curly->max_calls)     { return RET_BADHANDLE; }
 if(curlycallptr) { *curlycallptr=&curly->call[ci]; }
 if(curly->call[ci].magic==0) { return RET_BADHANDLE; }
 ccall=(_curlycall*)&curly->call[ci];
 if(ccall->is_fin!=YES)     { return RET_NOTREADY; }
 if(ccall->is_error)
  {
  aaCustomLog("ERR: %i %s",ccall->result,ccall->result_str);
  return RET_FAILED;
  }
 if(ccall->http_code==301||ccall->http_code==302) { return RET_OTHER; }
 if(ccall->http_code!=200&&ccall->http_code!=100)  {  return RET_FAILED;  }
 if(ccall->http_code==100)  {  ccall->http_code=0;  }
 return RET_YES;
 }





 B curlyCallRetry                      (_curly*curly,H index,HP newindex)
 {
 B ret;
 N ci;
 H new_ci,tt;//s4i;
 B usd[_1K],cmd[_8K];
 _curlycall*ccall;
 if(curly==NULL)                   { return RET_MISSINGPARM; }
 if(curly->magic!=aaHPP(curlyStart)) { return RET_NOTINITIALIZED; }
 ci=(N)index;
 if(ci>=curly->max_calls)     { return RET_BADHANDLE; }
 if(curly->call[index].magic==0) { return RET_BADHANDLE; }
 ccall=(_curlycall*)&curly->call[index];
 aaMemoryCopy(usd,_1K,ccall->user_data);
 aaMemoryCopy(cmd,_8K,ccall->cmd);
 if((ret=curlyCallDelete(curly,index))!=RET_YES)                { oops; }
 if((ret=curlyCallNew(curly,&new_ci,NULL,"%s",cmd))!=RET_YES) { oops; }
 aaMemoryCopy(curly->call[new_ci].user_data,_1K,usd);
 curly->tot_retries++;
 if(newindex) { *newindex=new_ci; }
 return RET_YES;
 }

/*-----------------------------------------------------------------------*/


 Q globalIdGenerate                    (V)
 {
 Q go,bs,id,bi;
 bs=(Q)sizeof(app.global_id_block);
 go=0;
 id=0;
 while(1)
  {
  go++;
  if(go>=(bs/2))
   {
   ///globalIdReset();
   app.global_id_counter+=bs;
   aaMemoryFill(app.global_id_block,sizeof(app.global_id_block),0);
   go=0;
   continue;
   }
  bi=aaMathRand64(0,bs);
  bi=bi%bs;
  if(app.global_id_block[bi]==1) { continue; }
  id=(app.global_id_counter*bs)+bi;
  app.global_id_block[bi]=1;
  break;
  }
 return id;
 }

/*-----------------------------------------------------------------------*/




 B serverCallRoomGather                (_theservercallgather*scgather,VP fmt,...)
 {
 H e,ec,c;
 aaVargsf256K(fmt);
 scgather->count=0;
 ec=aaElementCount(scgather->call_extra_index);
 if(ec!=SERVER_MAX_CALLS) { aaNote(0,"gather ec=%i ",ec); }
 for(e=0;e<ec;e++) { scgather->call_extra_index[e]=-1; }
 c=0;
 for(e=0;e<ec;e++)
  {
  if(app.the_server_call_extra_data[e].call_handle==0) { continue; }
  if(app.the_server_call_extra_data[e].call_index!=e)  { aaNote(0,"e=%i ci=%i",e,app.the_server_call_extra_data[e].call_index);  continue; }
  if(aaStringICompare(app.the_server_call_extra_data[e].room_name,str256k.buf,0)!=YES) { continue; }
  scgather->call_extra_index[c]=e;
  c++;
  }
 scgather->count=c;
 return RET_YES;
 }









 B serverCallToText                    (VP txt)
 {
 if(app.the_server.call.status.index>=SERVER_MAX_CALLS) { aaNote(0,"index=%i",app.the_server.call.status.index); }
 aaStringNull(txt);
 if(0) { return YES; }
 aaStringAppendf(txt,"%s ",app.the_server.scd->wock.x_forwarded_for);
 aaStringAppendf(txt,"%s ",app.the_server.scd->wock.url);
 aaStringAppendf(txt,"%u ",app.the_server.call.handle);
 aaStringAppendf(txt,"%u ",app.the_server.call.status.index);
 aaStringAppendf(txt,"%u ",app.the_server.call.status.number);
 aaStringAppendf(txt,"%x ",app.the_server.call.status.session);
 aaStringAppendf(txt,"%i ",app.the_server.scd->is_close);
 aaStringAppendf(txt,"%i ",app.the_server.scd->is_closing);
 return RET_YES;
 }






 B serverCallNext                      (V)
 {
 B ret;
 B pre[_1K];
 H ci;

 while(1)
  {
  if((ret=aaNetWebsocketServerCallNext(&app.the_server))!=YES) { break; }
  if(app.the_server.scd==NULL) { oof; }
  if(app.the_server.call.handle==0) { oof; }
  if(app.the_server.scd->is_closing)
   {
   if(app.the_server.scd->ustage>=1000) {  break;   }
   serverCallToText(pre);
   //aaDebugf("%s closea ",pre);
   //appLog(0,F32,"%s closea",pre);
   ci=app.the_server.call.status.index;
   aaMemoryFill(&app.the_server_call_extra_data[ci],sizeof(_theservercallextradata),0);
   if(aaNetWebsocketServerCallClose(&app.the_server)!=YES) { oof; }
   break;
   }

  if(app.the_server.scd->is_ready!=YES) { break; }
  if(app.the_server.scd->sys_flag==0)
   {
   aaNetWebsocketServerPktWritef(&app.the_server,WEBSOCKET_OPCODE_TEXT,YES,"{\"xfwd\":\"%s\"}",app.the_server.scd->wock.x_forwarded_for);
   app.the_server.scd->sys_flag=1;
   }
  return RET_YES;
  }
 return RET_NOTREADY;
 }





 B serverCallPktWrite                  (B oc,B ff,H bytes,VP data)
 {
 B ret;
 if((ret=aaNetWebsocketServerPktWrite(&app.the_server,oc,ff,bytes,data))!=RET_YES) { oops; }
 return RET_YES;
 }



 B serverCallPktWritef                 (B oc,B ff,VP fmt,...)
 {
 B ret;
 aaVargsf256K(fmt);
 if((ret=aaNetWebsocketServerPktWritef(&app.the_server,oc,ff,"%s",str256k.buf))!=RET_YES) { oops; }
 return RET_YES;
 }





 B serverCallPktRead                   (_websockethdr*wockhdr,VP wockdata)
 {
 B ret;
 BP bp;
 if((ret=aaNetWebsocketServerPktRead(&app.the_server,wockhdr,wockdata))!=RET_YES) { return ret; }
 bp=(BP)wockdata;
 bp[wockhdr->bytes]=NULL_CHAR;
 return RET_YES;
 }






 B serverCallPktProcess                (_websockethdr*wockhdr,VP wockdata)
 {
 B ret;
 BP wdata;
 wdata=(BP)wockdata;
 wdata[wockhdr->bytes]=NULL_CHAR;
 //appLog(0,F32,"pktprocess %s",wdata);
 if((ret=aaJsonCreate(&json_unit.handle,NO))!=YES) { oops; }
 if((ret=aaJsonDecoderBegin(json_unit.handle,wockhdr->bytes,wockdata))!=YES)
  {
  //appLog(0,F32,"serverCallPktProcess jsonbegin failed %s",arets);
  if((ret=aaJsonDestroy(json_unit.handle))!=YES) { oops; }
  return RET_FAILED;
  }
 if((ret=aaJsonDecoderYield(json_unit.handle,YES,&json_unit.status))!=RET_YES)
  {
  //appLog(0,F32,"serverCallPktProcess json failed %s",arets);
  if((ret=aaJsonDestroy(json_unit.handle))!=YES) { oops; }
  return RET_FAILED;
  }
 //appLog(0,F32,"line=%i",__LINE__);
 aaJcursorNew(&jay_cur);
 aaJcursorAttach(&jay_cur,json_unit.handle);
 if((ret=aaJcursorFlatten(&jay_cur))!=YES) { oops; }
 if(tr.magic!=0) { aaTextReaderDelete(&tr); }
 if((ret=aaTextReaderNew(&tr,0,jay_cur.flat_out))!=YES) { oops; }
 aaJcursorDelete(&jay_cur);
 if((ret=aaJsonDestroy(json_unit.handle))!=YES) { oops; }
 return RET_YES;
 }





 B serverProcessClose                  (V)
 {
 B ret;
 H ci,j;
 Q uid;
 B pre[_1K];
 B room[_1K];
 N scei;
 _theservercallgather scgath;
 B out[_32K];

 ci=app.the_server.call.status.index;
 serverCallToText(pre);
 aaStringCopyf(room,"%s",app.the_server_call_extra_data[ci].room_name);
 uid=app.the_server_call_extra_data[ci].uuid;
 aaMemoryFill(&app.the_server_call_extra_data[ci],sizeof(_theservercallextradata),0);
 if(aaNetWebsocketServerCallClose(&app.the_server)!=YES) { oof; }
 if(room[0]&&uid)
  {
  serverCallRoomGather(&scgath,"%s",room);
  for(j=0;j<scgath.count;j++)
   {
   scei=scgath.call_extra_index[j];
   if(scei==(N)ci) { continue; }
   if((ret=aaNetWebsocketServerCallSet(&app.the_server,app.the_server_call_extra_data[scei].call_handle))!=YES) { oops; continue; }
   aaStringNull(out);
   aaStringAppendf(out,"{");
   aaStringAppendf(out,"\"cmd\":\"left\",");
   aaStringAppendf(out,"\"room\":\"%s\",",room);
   aaStringAppendf(out,"\"uuid\":%I64d",uid);
   aaStringAppendf(out,"}");
   serverCallPktWritef(WEBSOCKET_OPCODE_TEXT,1,"%s",out);
   }
  }
 return RET_YES;
 }





 B serverProcessor                     (V)
 {
 B ret;
 B pre[_1K];
 H ci,j,ok,ti,test_count;
 Q uid,el,to,from;
 _theservercallgather scgath;
 _websockethdr wockhdr;
 B wockdata[_256K];
 B cha;
 _trobj trobj[32];
 N scei,w0;
 B out[_32K];

 if(serverCallNext()==YES)
  {
  if(app.the_server.scd->is_close!=0&&app.the_server.scd->is_closing==0)
   {
   serverProcessClose();
   return RET_YES;
   }

  switch(app.the_server.scd->ustage)
   {
   case 0:
   if(app.the_server.scd->sys_flag!=1) { break; }
   serverCallToText(pre);
   while(1)
    {
    ok=0;
    if(aaStringICompare(app.the_server.scd->wock.url,"/rtcsig/",0)==YES) { ok=2000; break; }
    break;
    }
   if(ok==0)
    {
    appLog(0,F32,"%s %s answered bad url",app.the_server.scd->wock.url,pre);
    if(aaNetWebsocketServerCallClose(&app.the_server)!=YES) { oof; }
    binerr_user_cntr++;
    break;
    }

   appLog(0,F32,"%s answered",pre);
   ci=app.the_server.call.status.index;
   aaMemoryFill(&app.the_server_call_extra_data[ci],sizeof(_theservercallextradata),0);
   app.the_server_call_extra_data[ci].call_handle=app.the_server.call.handle;
   app.the_server_call_extra_data[ci].call_index=ci;
   app.the_server_call_extra_data[ci].call_number=app.the_server.call.status.number;
   app.the_server_call_extra_data[ci].call_session=app.the_server.call.status.session;
   app.the_server.scd->ustage=ok;
   break;



   case 60: app.the_server.scd->ustage++; break;
   case 61: app.the_server.scd->ustage++; break;
   case 62: app.the_server.scd->ustage++; break;
   case 63: app.the_server.scd->ustage++; break;
   case 64: app.the_server.scd->ustage++; break;
   case 65: app.the_server.scd->ustage++; break;
   case 66: if(aaNetWebsocketServerCallClose(&app.the_server)!=YES) { oof; } break;

   case 70: el=aaMsRunning()-app.the_server.scd->ums;
            if(el>=3000) { app.the_server.scd->ustage=60; }
            break;



   case 2000:
   ///if(aaMsRunning()>10000) { app.the_server.scd->ustage=60; break; }
   serverCallToText(pre);
   ci=app.the_server.call.status.index;
   if(serverCallPktRead(&wockhdr,wockdata)==YES)
    {
    if(serverCallPktProcess(&wockhdr,wockdata)==YES)
     {
     ti=0;
     trObjInit(&trobj[ti],"cmd");
     trobj[ti].ret=trValGet(&tr,trobj[ti].val,&trobj[ti].line,&trobj[ti].is_qtd,"%s",trobj[ti].key);
     if(trobj[ti].ret!=RET_YES) {   appLog(0,F32,"cmd not found");      break;      }
     //appLog(0,F32,"cmd=%s",trobj[ti].val);
     aaStringIsIStringQuoted(trobj[ti].val,100,&w0,"join","say",0);

     switch(w0)
      {
      default:
      appLog(0,F32,"cmd=%s",trobj[ti].val);
      break;

      case 100: // join  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      trObjInit(&trobj[0],"cmd");
      trObjInit(&trobj[1],"room");
      trObjInit(&trobj[2],"fingerprint");
      trObjInit(&trobj[3],"testcount");
      for(ti=0;ti<4;ti++) { trobj[ti].ret=trValGet(&tr,trobj[ti].val,&trobj[ti].line,&trobj[ti].is_qtd,"%s",trobj[ti].key);   }
      aaStringToNumber(trobj[3].val,0,&test_count,0,0,0);
      if(test_count<2)  { test_count=2; }
      else
      if(test_count>32) { test_count=32; }
      serverCallRoomGather(&scgath,"%s",trobj[1].val);
//    aaDebugf("tc=%i sc=%i",test_count,scgath.count);
      if(scgath.count>=test_count)
       {
       aaStringNull(out);
       aaStringAppendf(out,"{");
       aaStringAppendf(out,"\"cmd\":\"full\",");
       aaStringAppendf(out,"\"room\":\"%s\"",trobj[1].val);
       aaStringAppendf(out,"}");
       serverCallPktWritef(WEBSOCKET_OPCODE_TEXT,1,"%s",out);
       app.the_server.scd->ums=aaMsRunning();
       app.the_server.scd->ustage=70;
       break;
       }
      uid=globalIdGenerate();
      aaStringCopy(app.the_server_call_extra_data[ci].room_name,trobj[1].val);
      app.the_server_call_extra_data[ci].uuid=uid;
      serverCallRoomGather(&scgath,"%s",trobj[1].val);
      aaStringNull(out);
      aaStringAppendf(out,"{");
      aaStringAppendf(out,"\"cmd\":\"hi\",");
      aaStringAppendf(out,"\"room\":\"%s\",",trobj[1].val);
      aaStringAppendf(out,"\"uuid\":%I64d,",uid);
      aaStringAppendf(out,"\"peerCount\":%i,",scgath.count);
      aaStringAppendf(out,"\"peerList\":[");
      for(j=0;j<scgath.count;j++)
       {
       scei=scgath.call_extra_index[j];
       aaStringAppendf(out,"%I64d,",app.the_server_call_extra_data[scei].uuid);
       }
      aaStringLastCharGet(out,0,&cha);
      aaStringLastCharDeleteIfChar(out,0,',');
      aaStringAppendf(out,"]");
      aaStringAppendf(out,"}");
      serverCallPktWritef(WEBSOCKET_OPCODE_TEXT,1,"%s",out);
      for(j=0;j<scgath.count;j++)
       {
       scei=scgath.call_extra_index[j];
       if(scei==(N)ci) { continue; }
       if((ret=aaNetWebsocketServerCallSet(&app.the_server,app.the_server_call_extra_data[scei].call_handle))!=YES) { oops; continue; }
       aaStringNull(out);
       aaStringAppendf(out,"{");
       aaStringAppendf(out,"\"cmd\":\"joined\",");
       aaStringAppendf(out,"\"room\":\"%s\",",trobj[1].val);
       aaStringAppendf(out,"\"uuid\":%I64d",uid);
       aaStringAppendf(out,"}");
       serverCallPktWritef(WEBSOCKET_OPCODE_TEXT,1,"%s",out);
       }
      break;




      case 101: // say  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
      trObjInit(&trobj[0],"cmd");
      trObjInit(&trobj[1],"room");
      trObjInit(&trobj[2],"to");
      trObjInit(&trobj[3],"msg.func");
      trObjInit(&trobj[4],"msg.data");
      for(ti=0;ti<5;ti++) { trobj[ti].ret=trValGet(&tr,trobj[ti].val,&trobj[ti].line,&trobj[ti].is_qtd,"%s",trobj[ti].key);   }
      serverCallRoomGather(&scgath,"%s",trobj[1].val);
      aaStringToNumber(trobj[2].val,0,0,0,0,&to);
      ///appLog(0,F32,"to=%I64d",to);
      from=app.the_server_call_extra_data[ci].uuid;
      if(to==0) // to all
       {
       for(j=0;j<scgath.count;j++)
        {
        scei=scgath.call_extra_index[j];
        //if(scei==ci) { continue; }
        if((ret=aaNetWebsocketServerCallSet(&app.the_server,app.the_server_call_extra_data[scei].call_handle))!=YES) { oops; continue; }
        aaStringNull(out);
        aaStringAppendf(out,"{");
        aaStringAppendf(out,"\"cmd\":\"said\",");
        aaStringAppendf(out,"\"room\":\"%s\",",trobj[1].val);
        aaStringAppendf(out,"\"uuid\":%I64d,",from); // from
        aaStringAppendf(out,"\"to\":%I64d,",to);
        aaStringAppendf(out,"\"target\":%I64d,",app.the_server_call_extra_data[scei].uuid);
        aaStringAppendf(out,"\"msg_func\":\"%s\",",trobj[3].val);
        aaStringAppendf(out,"\"msg_data\":\"%s\"",trobj[4].val);
        aaStringAppendf(out,"}");
        serverCallPktWritef(WEBSOCKET_OPCODE_TEXT,1,"%s",out);
        }
       }
      else
      if(to==1) // to server
       {
       //aaDebugf("from=%I64d",from);
       //aaDebugf("%s) %I64d, %s: %s",trobj[1].val,from,trobj[3].val,trobj[4].val);
       }
      else
       {
       for(j=0;j<scgath.count;j++)
        {
        scei=scgath.call_extra_index[j];
        //if(scei==ci) { continue; }
        if(app.the_server_call_extra_data[scei].uuid!=to) { continue; }
        if((ret=aaNetWebsocketServerCallSet(&app.the_server,app.the_server_call_extra_data[scei].call_handle))!=YES) { oops; continue; }
        aaStringNull(out);
        aaStringAppendf(out,"{");
        aaStringAppendf(out,"\"cmd\":\"said\",");
        aaStringAppendf(out,"\"room\":\"%s\",",trobj[1].val);
        aaStringAppendf(out,"\"uuid\":%I64d,",from); // from
        aaStringAppendf(out,"\"to\":%I64d,",to);
        aaStringAppendf(out,"\"target\":%I64d,",app.the_server_call_extra_data[scei].uuid);
        aaStringAppendf(out,"\"msg_func\":\"%s\",",trobj[3].val);
        aaStringAppendf(out,"\"msg_data\":\"%s\"",trobj[4].val);
        aaStringAppendf(out,"}");
        serverCallPktWritef(WEBSOCKET_OPCODE_TEXT,1,"%s",out);
        break;
        }
       }
      break;
      }
     }
    }
   break;
   }
  }
 return RET_YES;
 }






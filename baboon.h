/*-----------------------------------------------------------------------*/
 #pragma once
 #ifndef INC_BABOON_H
 #define INC_BABOON_H
 #define PUB                           extern
 #ifdef __cplusplus
 PUB "C" {
 #endif
/*-----------------------------------------------------------------------*/
 #include "aa.h"
 #include <string.h>
 #include <ctype.h>
 #include <stdbool.h>
 #include "curl.h"
/*-----------------------------------------------------------------------*/
 #define DEV_VERSION                   "1.23"
/*-----------------------------------------------------------------------*/
 #define CURLY_MAX_CALLS               64
/*-----------------------------------------------------------------------*/
 #define SERVER_MAX_CALLS              64
/*-----------------------------------------------------------------------*/

 #define ULAW_MUCLIP                   32635
 #define ULAW_BIAS                     0x84
 #define ULAW_MUZERO                   0x02
 #define ULAW_ZEROTRAP

 #define ALAW_QUANT_MASK               (0xf)
 #define ALAW_NSEGS                    (8)
 #define ALAW_SEG_SHIFT                (4)

 V UlawEncode                          (IP pcm16,BP uptr,Z pcminc,Z uinc,H len);
 V UlawDecode                          (BP uptr,IP pcm16,Z uinc,Z pcminc,H len);
 V AlawEncode                          (IP pcm16,BP alawp,Z pcminc,Z ainc,H len);
 V AlawDecode                          (BP alawp,IP pcm16,Z ainc,Z pcminc,H len);

/*-----------------------------------------------------------------------*/


 structure
 {
 H magic;
 B ret;
 B key[_4K];
 H line;
 B is_qtd;
 B val[_4K];
 }
 _trobj;


 B trObjInit                           (_trobj*trobj,VP fmt,...);
 B trValGet                            (_textreader*textreader,VP val,HP li,BP isqtd,VP fmt,...);
 B trKeyValGet                         (_textreader*textreader,H li,BP isqtd,VP key,VP val);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 H stage;
 B is_finished;
 B is_success;
 B is_failure;
 _udpunit udp[1];
 _dnsunit dns;
 H dns_index;
 _stununit stun;
 B dot[129];
 }
 _stunner;



 B stunnerNew                          (_stunner*stunner);
 B stunnerDelete                       (_stunner*stunner);
 B stunnerYield                        (_stunner*stunner,H ita);



/*-----------------------------------------------------------------------*/

 structure
 {
 Y cc:4;              // CSRC count
 Y x:1;               // header extension flag
 Y p:1;               // padding flag
 Y version:2;         // protocol version
 Y pt:7;              // payload type
 Y m:1;               // marker bit
 Y seq:16;            // sequence number
 Y ts;
 Y ssrc;
 }
 _rtpheader;

/*-----------------------------------------------------------------------*/

 structure
 {
 B type[17];
 B value[257];
 H token_count;
 _offlen token_offlen[32];
 B token[32][129];
 }
 _sdp;


 B aaSdpParse                          (_sdp*sdp,H bytes,VP data);

/*-----------------------------------------------------------------------*/



 structure
 {
 B is_failed;
 B is_success;
 H code;
 H version[2];
 }
 _sipresult;



 structure
 {
 B is_failed;
 B is_success;
 B field[129];
 H data_bytes;
 B data[_2K];
 }
 _sipheader;



 B aaNetSipResultReadFromString        (_sipresult*sipresult,H bytes,VP str);
 B aaNetSipHeaderReadFromString        (_sipheader*sipheader,H bytes,VP str);


/*-----------------------------------------------------------------------*/

 Q globalIdGenerate                    (V);

/*-----------------------------------------------------------------------*/

 structure
 {
 H call_handle;
 H call_index;
 H call_number;
 H call_session;
 B room_name[65];
 Q uuid;
 //N bashy_index;
 }
 _theservercallextradata;


 structure
 {
 H count;
 N call_extra_index[SERVER_MAX_CALLS];
 }
 _theservercallgather;

/*-----------------------------------------------------------------------*/



 structure
 {
 H magic;
 B is_ready;
 B is_paused;
 B do_quit;
 _info info;
 _sysinfo si;
 _displayinfo di;
 _surfaceunit surf;
 H tray_icon_index;
 Q tray_icon_ms;
 _surfaceunit canvas;
 Q canvas_update_ms;
 _fontunit font[1];
 B bilboard[15][257];
 _netstatus ns;
 Q global_id_counter;
 B global_id_block[SERVER_MAX_CALLS];
 _websocketserver the_server;
 _theservercallextradata the_server_call_extra_data[SERVER_MAX_CALLS];
 }
 _app;


 B appStart                            (V);
 B appStop                             (V);
 B appYield                            (V);
 B appLog                              (H index,H lines,VP fmt,...);
 B appStats                            (V);
 V appEngine                           (V);

/*-----------------------------------------------------------------------*/

 structure
 {
 H magic;
 B is_fin;
 B is_ret;
 B is_working;
 B is_cancel;
 B is_error;
 H this_ci;
 _threadunit thread;
 CURL*curl_handle;
 Z result;
 C result_str[_1K];
 VP curly_ptr;
 struct curl_slist*clist;
 _memoryunit mun;
 B cmd[_8K];
 B cookie[129];
 Q ms,el;
 W http_code;
 B location[_1K];
 H hdr_i_count;
 H hdr_o_count;
 B res_content_type[129];
/// H task_type;
/// _list task_list;
/// B list_line_buf[_8K];
 B url[_8K];
 B data[_8K];
 B user_data[_1K];
 ////H s4i;
/// _filestreamunit fsu;
 }
 _curlycall;


 structure
 {
 H magic;
 CURLSH*share_handle;
 N max_calls;
 N cur_calls;
 N fin_calls;
 Q tot_calls;
 Q tot_fails;
 Q tot_timeouts;
 Q tot_retries;
 _curlycall call[CURLY_MAX_CALLS];
 H pf_call;
 }
 _curly;

 Z curlyProcTrace                      (CURL*handle,curl_infotype type,CP data,Y size,VP ud);
 Y curlyProcWrite                      (CP contents,Y size,Y nmemb,VP ud);
 Y curlyProcProgress                   (VP p,D dltot,D dlnow,D ultot,D ulnow);
 B curlyCallThread                     (H handle);
 B curlyUserAgentGet                   (H ui,VP ua);

 B curlyStart                          (_curly*curly);
 B curlyStop                           (_curly*curly);
 B curlyYield                          (_curly*curly);

 B curlyCallNew                        (_curly*curly,HP index,_curlycall**ccall,VP fmt,...);
 B curlyCallDelete                     (_curly*curly,H index);
 B curlyCallCancel                     (_curly*curly,H index);
 B curlyCallCmdGet                     (_curly*curly,H index,H line,VP key,VP val);
 B curlyCallHeaderAppend               (_curly*curly,H index,VP fmt,...);
 B curlyCallWait                       (_curly*curly,H index,_curlycall**curlycallptr);
 B curlyCallRetry                      (_curly*curly,H index,HP newindex);


/*-----------------------------------------------------------------------*/

 B serverCallRoomGather                (_theservercallgather*scgather,VP fmt,...);
 B serverCallToText                    (VP txt);
 B serverCallNext                      (V);
 B serverCallPktWrite                  (B oc,B ff,H bytes,VP data);
 B serverCallPktWritef                 (B oc,B ff,VP fmt,...);
 B serverCallPktRead                   (_websockethdr*wockhdr,VP wockdata);
 B serverCallPktProcess                (_websockethdr*wockhdr,VP wockdata);
 B serverProcessClose                  (V);
 B serverProcessor                     (V);







/*-----------------------------------------------------------------------*/
 PUB _app                              app;
/*-----------------------------------------------------------------------*/
 #endif
/*-----------------------------------------------------------------------*/
 #ifdef __cplusplus
 }
 #endif




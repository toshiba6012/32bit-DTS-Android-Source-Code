 /*
  *   This library is free software; you can redistribute it and/or modify
  *   it under the terms of the GNU Lesser General Public License as
  *   published by the Free Software Foundation; either version 2.1 of
  *   the License, or (at your option) any later version.
  *
  *   This program is distributed in the hope that it will be useful,
  *   but WITHOUT ANY WARRANTY; without even the implied warranty of
  *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *   GNU Lesser General Public License for more details.
  *
  *   You should have received a copy of the GNU Lesser General Public
  *   License along with this library; if not, write to the Free Software
  *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
  *
  */
 
 #ifndef __ALSA_PCM_H
 #define __ALSA_PCM_H
 
 #ifdef __cplusplus
 extern "C" {
 #endif
 
 #include <stdint.h>
 
 #define SND_PCM_DLSYM_VERSION       _dlsym_pcm_001
 
 typedef struct _snd_pcm_info snd_pcm_info_t;
 
 typedef struct _snd_pcm_hw_params snd_pcm_hw_params_t;
 
 typedef struct _snd_pcm_sw_params snd_pcm_sw_params_t;
  typedef struct _snd_pcm_status snd_pcm_status_t;
 typedef struct _snd_pcm_access_mask snd_pcm_access_mask_t;
 typedef struct _snd_pcm_format_mask snd_pcm_format_mask_t;
 typedef struct _snd_pcm_subformat_mask snd_pcm_subformat_mask_t;
 
 typedef enum _snd_pcm_class {
     SND_PCM_CLASS_GENERIC = 0,
     SND_PCM_CLASS_MULTI,
     SND_PCM_CLASS_MODEM,
     SND_PCM_CLASS_DIGITIZER,
     SND_PCM_CLASS_LAST = SND_PCM_CLASS_DIGITIZER
 } snd_pcm_class_t;
 
 typedef enum _snd_pcm_subclass {
     SND_PCM_SUBCLASS_GENERIC_MIX = 0,
     SND_PCM_SUBCLASS_MULTI_MIX,
     SND_PCM_SUBCLASS_LAST = SND_PCM_SUBCLASS_MULTI_MIX
 } snd_pcm_subclass_t;
 
 typedef enum _snd_pcm_stream {
     SND_PCM_STREAM_PLAYBACK = 0,
     SND_PCM_STREAM_CAPTURE,
     SND_PCM_STREAM_LAST = SND_PCM_STREAM_CAPTURE
 } snd_pcm_stream_t;
 
 typedef enum _snd_pcm_access {
     SND_PCM_ACCESS_MMAP_INTERLEAVED = 0,
     SND_PCM_ACCESS_MMAP_NONINTERLEAVED,
     SND_PCM_ACCESS_MMAP_COMPLEX,
     SND_PCM_ACCESS_RW_INTERLEAVED,
     SND_PCM_ACCESS_RW_NONINTERLEAVED,
     SND_PCM_ACCESS_LAST = SND_PCM_ACCESS_RW_NONINTERLEAVED
 } snd_pcm_access_t;
 
 typedef enum _snd_pcm_format {
     SND_PCM_FORMAT_UNKNOWN = -1,
     SND_PCM_FORMAT_S8 = 0,
     SND_PCM_FORMAT_U8,
     SND_PCM_FORMAT_S16_LE,
     SND_PCM_FORMAT_S16_BE,
     SND_PCM_FORMAT_U16_LE,
     SND_PCM_FORMAT_U16_BE,
     SND_PCM_FORMAT_S24_LE,
     SND_PCM_FORMAT_S24_BE,
     SND_PCM_FORMAT_U24_LE,
     SND_PCM_FORMAT_U24_BE,
     SND_PCM_FORMAT_S32_LE,
     SND_PCM_FORMAT_S32_BE,
     SND_PCM_FORMAT_U32_LE,
     SND_PCM_FORMAT_U32_BE,
     SND_PCM_FORMAT_FLOAT_LE,
     SND_PCM_FORMAT_FLOAT_BE,
     SND_PCM_FORMAT_FLOAT64_LE,
     SND_PCM_FORMAT_FLOAT64_BE,
     SND_PCM_FORMAT_IEC958_SUBFRAME_LE,
     SND_PCM_FORMAT_IEC958_SUBFRAME_BE,
     SND_PCM_FORMAT_MU_LAW,
     SND_PCM_FORMAT_A_LAW,
     SND_PCM_FORMAT_IMA_ADPCM,
     SND_PCM_FORMAT_MPEG,
     SND_PCM_FORMAT_GSM,
     SND_PCM_FORMAT_S20_LE,
     SND_PCM_FORMAT_S20_BE,
     SND_PCM_FORMAT_U20_LE,
     SND_PCM_FORMAT_U20_BE,
     SND_PCM_FORMAT_SPECIAL = 31,
     SND_PCM_FORMAT_S24_3LE = 32,
     SND_PCM_FORMAT_S24_3BE,
     SND_PCM_FORMAT_U24_3LE,
     SND_PCM_FORMAT_U24_3BE,
     SND_PCM_FORMAT_S20_3LE,
     SND_PCM_FORMAT_S20_3BE,
     SND_PCM_FORMAT_U20_3LE,
     SND_PCM_FORMAT_U20_3BE,
     SND_PCM_FORMAT_S18_3LE,
     SND_PCM_FORMAT_S18_3BE,
     SND_PCM_FORMAT_U18_3LE,
     SND_PCM_FORMAT_U18_3BE,
     /* G.723 (ADPCM) 24 kbit/s, 8 samples in 3 bytes */
     SND_PCM_FORMAT_G723_24,
     /* G.723 (ADPCM) 24 kbit/s, 1 sample in 1 byte */
     SND_PCM_FORMAT_G723_24_1B,
     /* G.723 (ADPCM) 40 kbit/s, 8 samples in 3 bytes */
     SND_PCM_FORMAT_G723_40,
     /* G.723 (ADPCM) 40 kbit/s, 1 sample in 1 byte */
     SND_PCM_FORMAT_G723_40_1B,
     /* Direct Stream Digital (DSD) in 1-byte samples (x8) */
     SND_PCM_FORMAT_DSD_U8,
     /* Direct Stream Digital (DSD) in 2-byte samples (x16) */
     SND_PCM_FORMAT_DSD_U16_LE,
     /* Direct Stream Digital (DSD) in 4-byte samples (x32) */
     SND_PCM_FORMAT_DSD_U32_LE,
     /* Direct Stream Digital (DSD) in 2-byte samples (x16) */
     SND_PCM_FORMAT_DSD_U16_BE,
     /* Direct Stream Digital (DSD) in 4-byte samples (x32) */
     SND_PCM_FORMAT_DSD_U32_BE,
     SND_PCM_FORMAT_LAST = SND_PCM_FORMAT_DSD_U32_BE,
 
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 
     SND_PCM_FORMAT_S16 = SND_PCM_FORMAT_S16_LE,
     SND_PCM_FORMAT_U16 = SND_PCM_FORMAT_U16_LE,
     SND_PCM_FORMAT_S24 = SND_PCM_FORMAT_S24_LE,
     SND_PCM_FORMAT_U24 = SND_PCM_FORMAT_U24_LE,
     SND_PCM_FORMAT_S32 = SND_PCM_FORMAT_S32_LE,
     SND_PCM_FORMAT_U32 = SND_PCM_FORMAT_U32_LE,
     SND_PCM_FORMAT_FLOAT = SND_PCM_FORMAT_FLOAT_LE,
     SND_PCM_FORMAT_FLOAT64 = SND_PCM_FORMAT_FLOAT64_LE,
     SND_PCM_FORMAT_IEC958_SUBFRAME = SND_PCM_FORMAT_IEC958_SUBFRAME_LE,
     SND_PCM_FORMAT_S20 = SND_PCM_FORMAT_S20_LE,
     SND_PCM_FORMAT_U20 = SND_PCM_FORMAT_U20_LE,
 #elif __BYTE_ORDER == __BIG_ENDIAN
 
     SND_PCM_FORMAT_S16 = SND_PCM_FORMAT_S16_BE,
     SND_PCM_FORMAT_U16 = SND_PCM_FORMAT_U16_BE,
     SND_PCM_FORMAT_S24 = SND_PCM_FORMAT_S24_BE,
     SND_PCM_FORMAT_U24 = SND_PCM_FORMAT_U24_BE,
     SND_PCM_FORMAT_S32 = SND_PCM_FORMAT_S32_BE,
     SND_PCM_FORMAT_U32 = SND_PCM_FORMAT_U32_BE,
     SND_PCM_FORMAT_FLOAT = SND_PCM_FORMAT_FLOAT_BE,
     SND_PCM_FORMAT_FLOAT64 = SND_PCM_FORMAT_FLOAT64_BE,
     SND_PCM_FORMAT_IEC958_SUBFRAME = SND_PCM_FORMAT_IEC958_SUBFRAME_BE,
     SND_PCM_FORMAT_S20 = SND_PCM_FORMAT_S20_BE,
     SND_PCM_FORMAT_U20 = SND_PCM_FORMAT_U20_BE,
 #else
 #error "Unknown endian"
 #endif
 } snd_pcm_format_t;
 
 typedef enum _snd_pcm_subformat {
     SND_PCM_SUBFORMAT_STD = 0,
     SND_PCM_SUBFORMAT_LAST = SND_PCM_SUBFORMAT_STD
 } snd_pcm_subformat_t;
 
 typedef enum _snd_pcm_state {
     SND_PCM_STATE_OPEN = 0,
     SND_PCM_STATE_SETUP,
     SND_PCM_STATE_PREPARED,
     SND_PCM_STATE_RUNNING,
     SND_PCM_STATE_XRUN,
     SND_PCM_STATE_DRAINING,
     SND_PCM_STATE_PAUSED,
     SND_PCM_STATE_SUSPENDED,
     SND_PCM_STATE_DISCONNECTED,
     SND_PCM_STATE_LAST = SND_PCM_STATE_DISCONNECTED,
     SND_PCM_STATE_PRIVATE1 = 1024
 } snd_pcm_state_t;
 
 typedef enum _snd_pcm_start {
     SND_PCM_START_DATA = 0,
     SND_PCM_START_EXPLICIT,
     SND_PCM_START_LAST = SND_PCM_START_EXPLICIT
 } snd_pcm_start_t;
 
 typedef enum _snd_pcm_xrun {
     SND_PCM_XRUN_NONE = 0,
     SND_PCM_XRUN_STOP,
     SND_PCM_XRUN_LAST = SND_PCM_XRUN_STOP
 } snd_pcm_xrun_t;
 
 typedef enum _snd_pcm_tstamp {
     SND_PCM_TSTAMP_NONE = 0,
     SND_PCM_TSTAMP_ENABLE,
     SND_PCM_TSTAMP_MMAP = SND_PCM_TSTAMP_ENABLE,
     SND_PCM_TSTAMP_LAST = SND_PCM_TSTAMP_ENABLE
 } snd_pcm_tstamp_t;
 
 typedef enum _snd_pcm_tstamp_type {
     SND_PCM_TSTAMP_TYPE_GETTIMEOFDAY = 0,   
     SND_PCM_TSTAMP_TYPE_MONOTONIC,  
     SND_PCM_TSTAMP_TYPE_MONOTONIC_RAW,  
     SND_PCM_TSTAMP_TYPE_LAST = SND_PCM_TSTAMP_TYPE_MONOTONIC_RAW,
 } snd_pcm_tstamp_type_t;
 
 typedef struct _snd_pcm_audio_tstamp_config {
     /* 5 of max 16 bits used */
     unsigned int type_requested:4;
     unsigned int report_delay:1; /* add total delay to A/D or D/A */
 } snd_pcm_audio_tstamp_config_t;
 
 typedef struct _snd_pcm_audio_tstamp_report {
     /* 6 of max 16 bits used for bit-fields */
 
     /* for backwards compatibility */
     unsigned int valid:1;
 
     /* actual type if hardware could not support requested timestamp */
     unsigned int actual_type:4;
 
     /* accuracy represented in ns units */
     unsigned int accuracy_report:1; /* 0 if accuracy unknown, 1 if accuracy field is valid */
     unsigned int accuracy; /* up to 4.29s, will be packed in separate field  */
 } snd_pcm_audio_tstamp_report_t;
 
 typedef unsigned long snd_pcm_uframes_t;
 typedef long snd_pcm_sframes_t;
 
 #define SND_PCM_NONBLOCK        0x00000001
 
 #define SND_PCM_ASYNC           0x00000002
 
 #define SND_PCM_ABORT           0x00008000
 
 #define SND_PCM_NO_AUTO_RESAMPLE    0x00010000
 
 #define SND_PCM_NO_AUTO_CHANNELS    0x00020000
 
 #define SND_PCM_NO_AUTO_FORMAT      0x00040000
 
 #define SND_PCM_NO_SOFTVOL      0x00080000
 
 typedef struct _snd_pcm snd_pcm_t;
 
 enum _snd_pcm_type {
     SND_PCM_TYPE_HW = 0,
     SND_PCM_TYPE_HOOKS,
     SND_PCM_TYPE_MULTI,
     SND_PCM_TYPE_FILE,
     SND_PCM_TYPE_NULL,
     SND_PCM_TYPE_SHM,
     SND_PCM_TYPE_INET,
     SND_PCM_TYPE_COPY,
     SND_PCM_TYPE_LINEAR,
     SND_PCM_TYPE_ALAW,
     SND_PCM_TYPE_MULAW,
     SND_PCM_TYPE_ADPCM,
     SND_PCM_TYPE_RATE,
     SND_PCM_TYPE_ROUTE,
     SND_PCM_TYPE_PLUG,
     SND_PCM_TYPE_SHARE,
     SND_PCM_TYPE_METER,
     SND_PCM_TYPE_MIX,
     SND_PCM_TYPE_DROUTE,
     SND_PCM_TYPE_LBSERVER,
     SND_PCM_TYPE_LINEAR_FLOAT,
     SND_PCM_TYPE_LADSPA,
     SND_PCM_TYPE_DMIX,
     SND_PCM_TYPE_JACK,
     SND_PCM_TYPE_DSNOOP,
     SND_PCM_TYPE_DSHARE,
     SND_PCM_TYPE_IEC958,
     SND_PCM_TYPE_SOFTVOL,
     SND_PCM_TYPE_IOPLUG,
     SND_PCM_TYPE_EXTPLUG,
     SND_PCM_TYPE_MMAP_EMUL,
     SND_PCM_TYPE_LAST = SND_PCM_TYPE_MMAP_EMUL
 };
 
 typedef enum _snd_pcm_type snd_pcm_type_t;
 
 typedef struct _snd_pcm_channel_area {
     void *addr;
     unsigned int first;
     unsigned int step;
 } snd_pcm_channel_area_t;
 
 typedef union _snd_pcm_sync_id {
     unsigned char id[16];
     unsigned short id16[8];
     unsigned int id32[4];
 } snd_pcm_sync_id_t;
 
 typedef struct _snd_pcm_scope snd_pcm_scope_t;
 
 int snd_pcm_open(snd_pcm_t **pcm, const char *name, 
          snd_pcm_stream_t stream, int mode);
 int snd_pcm_open_lconf(snd_pcm_t **pcm, const char *name, 
                snd_pcm_stream_t stream, int mode,
                snd_config_t *lconf);
 int snd_pcm_open_fallback(snd_pcm_t **pcm, snd_config_t *root,
               const char *name, const char *orig_name,
               snd_pcm_stream_t stream, int mode);
 
 int snd_pcm_close(snd_pcm_t *pcm);
 const char *snd_pcm_name(snd_pcm_t *pcm);
 snd_pcm_type_t snd_pcm_type(snd_pcm_t *pcm);
 snd_pcm_stream_t snd_pcm_stream(snd_pcm_t *pcm);
 int snd_pcm_poll_descriptors_count(snd_pcm_t *pcm);
 int snd_pcm_poll_descriptors(snd_pcm_t *pcm, struct pollfd *pfds, unsigned int space);
 int snd_pcm_poll_descriptors_revents(snd_pcm_t *pcm, struct pollfd *pfds, unsigned int nfds, unsigned short *revents);
 int snd_pcm_nonblock(snd_pcm_t *pcm, int nonblock);
 static __inline__ int snd_pcm_abort(snd_pcm_t *pcm) { return snd_pcm_nonblock(pcm, 2); }
 int snd_async_add_pcm_handler(snd_async_handler_t **handler, snd_pcm_t *pcm, 
                   snd_async_callback_t callback, void *private_data);
 snd_pcm_t *snd_async_handler_get_pcm(snd_async_handler_t *handler);
 int snd_pcm_info(snd_pcm_t *pcm, snd_pcm_info_t *info);
 int snd_pcm_hw_params_current(snd_pcm_t *pcm, snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params(snd_pcm_t *pcm, snd_pcm_hw_params_t *params);
 int snd_pcm_hw_free(snd_pcm_t *pcm);
 int snd_pcm_sw_params_current(snd_pcm_t *pcm, snd_pcm_sw_params_t *params);
 int snd_pcm_sw_params(snd_pcm_t *pcm, snd_pcm_sw_params_t *params);
 int snd_pcm_prepare(snd_pcm_t *pcm);
 int snd_pcm_reset(snd_pcm_t *pcm);
 int snd_pcm_status(snd_pcm_t *pcm, snd_pcm_status_t *status);
 int snd_pcm_start(snd_pcm_t *pcm);
 int snd_pcm_drop(snd_pcm_t *pcm);
 int snd_pcm_drain(snd_pcm_t *pcm);
 int snd_pcm_pause(snd_pcm_t *pcm, int enable);
 snd_pcm_state_t snd_pcm_state(snd_pcm_t *pcm);
 int snd_pcm_hwsync(snd_pcm_t *pcm);
 int snd_pcm_delay(snd_pcm_t *pcm, snd_pcm_sframes_t *delayp);
 int snd_pcm_resume(snd_pcm_t *pcm);
 int snd_pcm_htimestamp(snd_pcm_t *pcm, snd_pcm_uframes_t *avail, snd_htimestamp_t *tstamp);
 snd_pcm_sframes_t snd_pcm_avail(snd_pcm_t *pcm);
 snd_pcm_sframes_t snd_pcm_avail_update(snd_pcm_t *pcm);
 int snd_pcm_avail_delay(snd_pcm_t *pcm, snd_pcm_sframes_t *availp, snd_pcm_sframes_t *delayp);
 snd_pcm_sframes_t snd_pcm_rewindable(snd_pcm_t *pcm);
 snd_pcm_sframes_t snd_pcm_rewind(snd_pcm_t *pcm, snd_pcm_uframes_t frames);
 snd_pcm_sframes_t snd_pcm_forwardable(snd_pcm_t *pcm);
 snd_pcm_sframes_t snd_pcm_forward(snd_pcm_t *pcm, snd_pcm_uframes_t frames);
 snd_pcm_sframes_t snd_pcm_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size);
 snd_pcm_sframes_t snd_pcm_readi(snd_pcm_t *pcm, void *buffer, snd_pcm_uframes_t size);
 snd_pcm_sframes_t snd_pcm_writen(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size);
 snd_pcm_sframes_t snd_pcm_readn(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size);
 int snd_pcm_wait(snd_pcm_t *pcm, int timeout);
 
 int snd_pcm_link(snd_pcm_t *pcm1, snd_pcm_t *pcm2);
 int snd_pcm_unlink(snd_pcm_t *pcm);
 
 #define SND_CHMAP_API_VERSION   ((1 << 16) | (0 << 8) | 1)
 
 enum snd_pcm_chmap_type {
     SND_CHMAP_TYPE_NONE = 0,
     SND_CHMAP_TYPE_FIXED,   
     SND_CHMAP_TYPE_VAR, 
     SND_CHMAP_TYPE_PAIRED,  
     SND_CHMAP_TYPE_LAST = SND_CHMAP_TYPE_PAIRED, 
 };
 
 enum snd_pcm_chmap_position {
     SND_CHMAP_UNKNOWN = 0,  
     SND_CHMAP_NA,       
     SND_CHMAP_MONO,     
     SND_CHMAP_FL,       
     SND_CHMAP_FR,       
     SND_CHMAP_RL,       
     SND_CHMAP_RR,       
     SND_CHMAP_FC,       
     SND_CHMAP_LFE,      
     SND_CHMAP_SL,       
     SND_CHMAP_SR,       
     SND_CHMAP_RC,       
     SND_CHMAP_FLC,      
     SND_CHMAP_FRC,      
     SND_CHMAP_RLC,      
     SND_CHMAP_RRC,      
     SND_CHMAP_FLW,      
     SND_CHMAP_FRW,      
     SND_CHMAP_FLH,      
     SND_CHMAP_FCH,      
     SND_CHMAP_FRH,      
     SND_CHMAP_TC,       
     SND_CHMAP_TFL,      
     SND_CHMAP_TFR,      
     SND_CHMAP_TFC,      
     SND_CHMAP_TRL,      
     SND_CHMAP_TRR,      
     SND_CHMAP_TRC,      
     SND_CHMAP_TFLC,     
     SND_CHMAP_TFRC,     
     SND_CHMAP_TSL,      
     SND_CHMAP_TSR,      
     SND_CHMAP_LLFE,     
     SND_CHMAP_RLFE,     
     SND_CHMAP_BC,       
     SND_CHMAP_BLC,      
     SND_CHMAP_BRC,      
     SND_CHMAP_LAST = SND_CHMAP_BRC,
 };
 
 #define SND_CHMAP_POSITION_MASK     0xffff
 
 #define SND_CHMAP_PHASE_INVERSE     (0x01 << 16)
 
 #define SND_CHMAP_DRIVER_SPEC       (0x02 << 16)
 
 typedef struct snd_pcm_chmap {
     unsigned int channels;  
     unsigned int pos[0];    
 } snd_pcm_chmap_t;
 
 typedef struct snd_pcm_chmap_query {
     enum snd_pcm_chmap_type type;   
     snd_pcm_chmap_t map;        
 } snd_pcm_chmap_query_t;
 
 
 snd_pcm_chmap_query_t **snd_pcm_query_chmaps(snd_pcm_t *pcm);
 snd_pcm_chmap_query_t **snd_pcm_query_chmaps_from_hw(int card, int dev,
                              int subdev,
                              snd_pcm_stream_t stream);
 void snd_pcm_free_chmaps(snd_pcm_chmap_query_t **maps);
 snd_pcm_chmap_t *snd_pcm_get_chmap(snd_pcm_t *pcm);
 int snd_pcm_set_chmap(snd_pcm_t *pcm, const snd_pcm_chmap_t *map);
 
 const char *snd_pcm_chmap_type_name(enum snd_pcm_chmap_type val);
 const char *snd_pcm_chmap_name(enum snd_pcm_chmap_position val);
 const char *snd_pcm_chmap_long_name(enum snd_pcm_chmap_position val);
 int snd_pcm_chmap_print(const snd_pcm_chmap_t *map, size_t maxlen, char *buf);
 unsigned int snd_pcm_chmap_from_string(const char *str);
 snd_pcm_chmap_t *snd_pcm_chmap_parse_string(const char *str);
 
 //int snd_pcm_mixer_element(snd_pcm_t *pcm, snd_mixer_t *mixer, snd_mixer_elem_t **elem);
 
 /*
  * application helpers - these functions are implemented on top
  * of the basic API
  */
 
 int snd_pcm_recover(snd_pcm_t *pcm, int err, int silent);
 int snd_pcm_set_params(snd_pcm_t *pcm,
                        snd_pcm_format_t format,
                        snd_pcm_access_t access,
                        unsigned int channels,
                        unsigned int rate,
                        int soft_resample,
                        unsigned int latency);
 int snd_pcm_get_params(snd_pcm_t *pcm,
                        snd_pcm_uframes_t *buffer_size,
                        snd_pcm_uframes_t *period_size);
 
 size_t snd_pcm_info_sizeof(void);
 #define snd_pcm_info_alloca(ptr) __snd_alloca(ptr, snd_pcm_info)
 int snd_pcm_info_malloc(snd_pcm_info_t **ptr);
 void snd_pcm_info_free(snd_pcm_info_t *obj);
 void snd_pcm_info_copy(snd_pcm_info_t *dst, const snd_pcm_info_t *src);
 unsigned int snd_pcm_info_get_device(const snd_pcm_info_t *obj);
 unsigned int snd_pcm_info_get_subdevice(const snd_pcm_info_t *obj);
 snd_pcm_stream_t snd_pcm_info_get_stream(const snd_pcm_info_t *obj);
 int snd_pcm_info_get_card(const snd_pcm_info_t *obj);
 const char *snd_pcm_info_get_id(const snd_pcm_info_t *obj);
 const char *snd_pcm_info_get_name(const snd_pcm_info_t *obj);
 const char *snd_pcm_info_get_subdevice_name(const snd_pcm_info_t *obj);
 snd_pcm_class_t snd_pcm_info_get_class(const snd_pcm_info_t *obj);
 snd_pcm_subclass_t snd_pcm_info_get_subclass(const snd_pcm_info_t *obj);
 unsigned int snd_pcm_info_get_subdevices_count(const snd_pcm_info_t *obj);
 unsigned int snd_pcm_info_get_subdevices_avail(const snd_pcm_info_t *obj);
 snd_pcm_sync_id_t snd_pcm_info_get_sync(const snd_pcm_info_t *obj);
 void snd_pcm_info_set_device(snd_pcm_info_t *obj, unsigned int val);
 void snd_pcm_info_set_subdevice(snd_pcm_info_t *obj, unsigned int val);
 void snd_pcm_info_set_stream(snd_pcm_info_t *obj, snd_pcm_stream_t val);
 
 int snd_pcm_hw_params_any(snd_pcm_t *pcm, snd_pcm_hw_params_t *params);
 
 int snd_pcm_hw_params_can_mmap_sample_resolution(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_is_double(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_is_batch(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_is_block_transfer(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_is_monotonic(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_can_overrange(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_can_pause(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_can_resume(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_is_half_duplex(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_is_joint_duplex(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_can_sync_start(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_can_disable_period_wakeup(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_supports_audio_wallclock_ts(const snd_pcm_hw_params_t *params); /* deprecated, use audio_ts_type */
 int snd_pcm_hw_params_supports_audio_ts_type(const snd_pcm_hw_params_t *params, int type);
 int snd_pcm_hw_params_get_rate_numden(const snd_pcm_hw_params_t *params,
                       unsigned int *rate_num,
                       unsigned int *rate_den);
 int snd_pcm_hw_params_get_sbits(const snd_pcm_hw_params_t *params);
 int snd_pcm_hw_params_get_fifo_size(const snd_pcm_hw_params_t *params);
 
 #if 0
 typedef struct _snd_pcm_hw_strategy snd_pcm_hw_strategy_t;
 
 /* choices need to be sorted on ascending badness */
 typedef struct _snd_pcm_hw_strategy_simple_choices_list {
     unsigned int value;
     unsigned int badness;
 } snd_pcm_hw_strategy_simple_choices_list_t;
 
 int snd_pcm_hw_params_strategy(snd_pcm_t *pcm, snd_pcm_hw_params_t *params,
                    const snd_pcm_hw_strategy_t *strategy,
                    unsigned int badness_min,
                    unsigned int badness_max);
 
 void snd_pcm_hw_strategy_free(snd_pcm_hw_strategy_t *strategy);
 int snd_pcm_hw_strategy_simple(snd_pcm_hw_strategy_t **strategyp,
                    unsigned int badness_min,
                    unsigned int badness_max);
 int snd_pcm_hw_params_try_explain_failure(snd_pcm_t *pcm,
                       snd_pcm_hw_params_t *fail,
                       snd_pcm_hw_params_t *success,
                       unsigned int depth,
                       snd_output_t *out);
 
 #endif
 
 size_t snd_pcm_hw_params_sizeof(void);
 #define snd_pcm_hw_params_alloca(ptr) __snd_alloca(ptr, snd_pcm_hw_params)
 int snd_pcm_hw_params_malloc(snd_pcm_hw_params_t **ptr);
 void snd_pcm_hw_params_free(snd_pcm_hw_params_t *obj);
 void snd_pcm_hw_params_copy(snd_pcm_hw_params_t *dst, const snd_pcm_hw_params_t *src);
 
 #if !defined(ALSA_LIBRARY_BUILD) && !defined(ALSA_PCM_OLD_HW_PARAMS_API)
 
 int snd_pcm_hw_params_get_access(const snd_pcm_hw_params_t *params, snd_pcm_access_t *_access);
 int snd_pcm_hw_params_test_access(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t _access);
 int snd_pcm_hw_params_set_access(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t _access);
 int snd_pcm_hw_params_set_access_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t *_access);
 int snd_pcm_hw_params_set_access_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_t *_access);
 int snd_pcm_hw_params_set_access_mask(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_access_mask_t *mask);
 int snd_pcm_hw_params_get_access_mask(snd_pcm_hw_params_t *params, snd_pcm_access_mask_t *mask);
 
 int snd_pcm_hw_params_get_format(const snd_pcm_hw_params_t *params, snd_pcm_format_t *val);
 int snd_pcm_hw_params_test_format(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t val);
 int snd_pcm_hw_params_set_format(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t val);
 int snd_pcm_hw_params_set_format_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t *format);
 int snd_pcm_hw_params_set_format_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_t *format);
 int snd_pcm_hw_params_set_format_mask(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_format_mask_t *mask);
 void snd_pcm_hw_params_get_format_mask(snd_pcm_hw_params_t *params, snd_pcm_format_mask_t *mask);
 
 int snd_pcm_hw_params_get_subformat(const snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat);
 int snd_pcm_hw_params_test_subformat(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t subformat);
 int snd_pcm_hw_params_set_subformat(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t subformat);
 int snd_pcm_hw_params_set_subformat_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat);
 int snd_pcm_hw_params_set_subformat_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_t *subformat);
 int snd_pcm_hw_params_set_subformat_mask(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_subformat_mask_t *mask);
 void snd_pcm_hw_params_get_subformat_mask(snd_pcm_hw_params_t *params, snd_pcm_subformat_mask_t *mask);
 
 int snd_pcm_hw_params_get_channels(const snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_get_channels_min(const snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_get_channels_max(const snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_test_channels(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val);
 int snd_pcm_hw_params_set_channels(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val);
 int snd_pcm_hw_params_set_channels_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_set_channels_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_set_channels_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, unsigned int *max);
 int snd_pcm_hw_params_set_channels_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_set_channels_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_set_channels_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 
 int snd_pcm_hw_params_get_rate(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_rate_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_rate_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_test_rate(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_rate(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_rate_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_rate_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_rate_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir);
 int snd_pcm_hw_params_set_rate_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_rate_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_rate_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_rate_resample(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val);
 int snd_pcm_hw_params_get_rate_resample(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_set_export_buffer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val);
 int snd_pcm_hw_params_get_export_buffer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 int snd_pcm_hw_params_set_period_wakeup(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val);
 int snd_pcm_hw_params_get_period_wakeup(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val);
 
 int snd_pcm_hw_params_get_period_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_period_time_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_period_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_test_period_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_period_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_period_time_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_period_time_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_period_time_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir);
 int snd_pcm_hw_params_set_period_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_period_time_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_period_time_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 
 int snd_pcm_hw_params_get_period_size(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *frames, int *dir);
 int snd_pcm_hw_params_get_period_size_min(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *frames, int *dir);
 int snd_pcm_hw_params_get_period_size_max(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *frames, int *dir);
 int snd_pcm_hw_params_test_period_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val, int dir);
 int snd_pcm_hw_params_set_period_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val, int dir);
 int snd_pcm_hw_params_set_period_size_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir);
 int snd_pcm_hw_params_set_period_size_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir);
 int snd_pcm_hw_params_set_period_size_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *min, int *mindir, snd_pcm_uframes_t *max, int *maxdir);
 int snd_pcm_hw_params_set_period_size_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir);
 int snd_pcm_hw_params_set_period_size_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir);
 int snd_pcm_hw_params_set_period_size_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val, int *dir);
 int snd_pcm_hw_params_set_period_size_integer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params);
 
 int snd_pcm_hw_params_get_periods(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_periods_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_periods_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_test_periods(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_periods(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_periods_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_periods_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_periods_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir);
 int snd_pcm_hw_params_set_periods_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_periods_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_periods_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_periods_integer(snd_pcm_t *pcm, snd_pcm_hw_params_t *params);
 
 int snd_pcm_hw_params_get_buffer_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_buffer_time_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_get_buffer_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_test_buffer_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_buffer_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir);
 int snd_pcm_hw_params_set_buffer_time_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_buffer_time_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_buffer_time_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir);
 int snd_pcm_hw_params_set_buffer_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_buffer_time_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 int snd_pcm_hw_params_set_buffer_time_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir);
 
 int snd_pcm_hw_params_get_buffer_size(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_get_buffer_size_min(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_get_buffer_size_max(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_test_buffer_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_hw_params_set_buffer_size(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_hw_params_set_buffer_size_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_set_buffer_size_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_set_buffer_size_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *min, snd_pcm_uframes_t *max);
 int snd_pcm_hw_params_set_buffer_size_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_set_buffer_size_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_hw_params_set_buffer_size_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 
 #endif /* !ALSA_LIBRARY_BUILD && !ALSA_PCM_OLD_HW_PARAMS_API */
 
 int snd_pcm_hw_params_get_min_align(const snd_pcm_hw_params_t *params, snd_pcm_uframes_t *val);
 
 size_t snd_pcm_sw_params_sizeof(void);
 #define snd_pcm_sw_params_alloca(ptr) __snd_alloca(ptr, snd_pcm_sw_params)
 int snd_pcm_sw_params_malloc(snd_pcm_sw_params_t **ptr);
 void snd_pcm_sw_params_free(snd_pcm_sw_params_t *obj);
 void snd_pcm_sw_params_copy(snd_pcm_sw_params_t *dst, const snd_pcm_sw_params_t *src);
 int snd_pcm_sw_params_get_boundary(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val);
 
 #if !defined(ALSA_LIBRARY_BUILD) && !defined(ALSA_PCM_OLD_SW_PARAMS_API)
 
 int snd_pcm_sw_params_set_tstamp_mode(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_tstamp_t val);
 int snd_pcm_sw_params_get_tstamp_mode(const snd_pcm_sw_params_t *params, snd_pcm_tstamp_t *val);
 int snd_pcm_sw_params_set_tstamp_type(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_tstamp_type_t val);
 int snd_pcm_sw_params_get_tstamp_type(const snd_pcm_sw_params_t *params, snd_pcm_tstamp_type_t *val);
 int snd_pcm_sw_params_set_avail_min(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_sw_params_get_avail_min(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_sw_params_set_period_event(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, int val);
 int snd_pcm_sw_params_get_period_event(const snd_pcm_sw_params_t *params, int *val);
 int snd_pcm_sw_params_set_start_threshold(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_sw_params_get_start_threshold(const snd_pcm_sw_params_t *paramsm, snd_pcm_uframes_t *val);
 int snd_pcm_sw_params_set_stop_threshold(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_sw_params_get_stop_threshold(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_sw_params_set_silence_threshold(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_sw_params_get_silence_threshold(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val);
 int snd_pcm_sw_params_set_silence_size(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val);
 int snd_pcm_sw_params_get_silence_size(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val);
 
 #endif /* !ALSA_LIBRARY_BUILD && !ALSA_PCM_OLD_SW_PARAMS_API */
 
 /* include old API */
 #ifndef ALSA_LIBRARY_BUILD
 #if defined(ALSA_PCM_OLD_HW_PARAMS_API) || defined(ALSA_PCM_OLD_SW_PARAMS_API)
 #include "pcm_old.h"
 #endif
 #endif
 
 size_t snd_pcm_access_mask_sizeof(void);
 #define snd_pcm_access_mask_alloca(ptr) __snd_alloca(ptr, snd_pcm_access_mask)
 int snd_pcm_access_mask_malloc(snd_pcm_access_mask_t **ptr);
 void snd_pcm_access_mask_free(snd_pcm_access_mask_t *obj);
 void snd_pcm_access_mask_copy(snd_pcm_access_mask_t *dst, const snd_pcm_access_mask_t *src);
 void snd_pcm_access_mask_none(snd_pcm_access_mask_t *mask);
 void snd_pcm_access_mask_any(snd_pcm_access_mask_t *mask);
 int snd_pcm_access_mask_test(const snd_pcm_access_mask_t *mask, snd_pcm_access_t val);
 int snd_pcm_access_mask_empty(const snd_pcm_access_mask_t *mask);
 void snd_pcm_access_mask_set(snd_pcm_access_mask_t *mask, snd_pcm_access_t val);
 void snd_pcm_access_mask_reset(snd_pcm_access_mask_t *mask, snd_pcm_access_t val);
 
 size_t snd_pcm_format_mask_sizeof(void);
 #define snd_pcm_format_mask_alloca(ptr) __snd_alloca(ptr, snd_pcm_format_mask)
 int snd_pcm_format_mask_malloc(snd_pcm_format_mask_t **ptr);
 void snd_pcm_format_mask_free(snd_pcm_format_mask_t *obj);
 void snd_pcm_format_mask_copy(snd_pcm_format_mask_t *dst, const snd_pcm_format_mask_t *src);
 void snd_pcm_format_mask_none(snd_pcm_format_mask_t *mask);
 void snd_pcm_format_mask_any(snd_pcm_format_mask_t *mask);
 int snd_pcm_format_mask_test(const snd_pcm_format_mask_t *mask, snd_pcm_format_t val);
 int snd_pcm_format_mask_empty(const snd_pcm_format_mask_t *mask);
 void snd_pcm_format_mask_set(snd_pcm_format_mask_t *mask, snd_pcm_format_t val);
 void snd_pcm_format_mask_reset(snd_pcm_format_mask_t *mask, snd_pcm_format_t val);
 
 size_t snd_pcm_subformat_mask_sizeof(void);
 #define snd_pcm_subformat_mask_alloca(ptr) __snd_alloca(ptr, snd_pcm_subformat_mask)
 int snd_pcm_subformat_mask_malloc(snd_pcm_subformat_mask_t **ptr);
 void snd_pcm_subformat_mask_free(snd_pcm_subformat_mask_t *obj);
 void snd_pcm_subformat_mask_copy(snd_pcm_subformat_mask_t *dst, const snd_pcm_subformat_mask_t *src);
 void snd_pcm_subformat_mask_none(snd_pcm_subformat_mask_t *mask);
 void snd_pcm_subformat_mask_any(snd_pcm_subformat_mask_t *mask);
 int snd_pcm_subformat_mask_test(const snd_pcm_subformat_mask_t *mask, snd_pcm_subformat_t val);
 int snd_pcm_subformat_mask_empty(const snd_pcm_subformat_mask_t *mask);
 void snd_pcm_subformat_mask_set(snd_pcm_subformat_mask_t *mask, snd_pcm_subformat_t val);
 void snd_pcm_subformat_mask_reset(snd_pcm_subformat_mask_t *mask, snd_pcm_subformat_t val);
 
 size_t snd_pcm_status_sizeof(void);
 #define snd_pcm_status_alloca(ptr) __snd_alloca(ptr, snd_pcm_status)
 int snd_pcm_status_malloc(snd_pcm_status_t **ptr);
 void snd_pcm_status_free(snd_pcm_status_t *obj);
 void snd_pcm_status_copy(snd_pcm_status_t *dst, const snd_pcm_status_t *src);
 snd_pcm_state_t snd_pcm_status_get_state(const snd_pcm_status_t *obj);
 void snd_pcm_status_get_trigger_tstamp(const snd_pcm_status_t *obj, snd_timestamp_t *ptr);
 void snd_pcm_status_get_trigger_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr);
 void snd_pcm_status_get_tstamp(const snd_pcm_status_t *obj, snd_timestamp_t *ptr);
 void snd_pcm_status_get_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr);
 void snd_pcm_status_get_audio_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr);
 void snd_pcm_status_get_driver_htstamp(const snd_pcm_status_t *obj, snd_htimestamp_t *ptr);
 void snd_pcm_status_get_audio_htstamp_report(const snd_pcm_status_t *obj,
                          snd_pcm_audio_tstamp_report_t *audio_tstamp_report);
 void snd_pcm_status_set_audio_htstamp_config(snd_pcm_status_t *obj,
                          snd_pcm_audio_tstamp_config_t *audio_tstamp_config);
 
 static inline void snd_pcm_pack_audio_tstamp_config(unsigned int *data,
                         snd_pcm_audio_tstamp_config_t *config)
 {
     *data = config->report_delay;
     *data <<= 4;
     *data |= config->type_requested;
 }
 
 static inline void snd_pcm_unpack_audio_tstamp_report(unsigned int data, unsigned int accuracy,
                         snd_pcm_audio_tstamp_report_t *report)
 {
     data >>= 16;
     report->valid = data & 1;
     report->actual_type = (data >> 1) & 0xF;
     report->accuracy_report = (data >> 5) & 1;
     report->accuracy = accuracy;
 }
 
 snd_pcm_sframes_t snd_pcm_status_get_delay(const snd_pcm_status_t *obj);
 snd_pcm_uframes_t snd_pcm_status_get_avail(const snd_pcm_status_t *obj);
 snd_pcm_uframes_t snd_pcm_status_get_avail_max(const snd_pcm_status_t *obj);
 snd_pcm_uframes_t snd_pcm_status_get_overrange(const snd_pcm_status_t *obj);
 
 const char *snd_pcm_type_name(snd_pcm_type_t type);
 const char *snd_pcm_stream_name(const snd_pcm_stream_t stream);
 const char *snd_pcm_access_name(const snd_pcm_access_t _access);
 const char *snd_pcm_format_name(const snd_pcm_format_t format);
 const char *snd_pcm_format_description(const snd_pcm_format_t format);
 const char *snd_pcm_subformat_name(const snd_pcm_subformat_t subformat);
 const char *snd_pcm_subformat_description(const snd_pcm_subformat_t subformat);
 snd_pcm_format_t snd_pcm_format_value(const char* name);
 const char *snd_pcm_tstamp_mode_name(const snd_pcm_tstamp_t mode);
 const char *snd_pcm_state_name(const snd_pcm_state_t state);
 
 int snd_pcm_dump(snd_pcm_t *pcm, snd_output_t *out);
 int snd_pcm_dump_hw_setup(snd_pcm_t *pcm, snd_output_t *out);
 int snd_pcm_dump_sw_setup(snd_pcm_t *pcm, snd_output_t *out);
 int snd_pcm_dump_setup(snd_pcm_t *pcm, snd_output_t *out);
 int snd_pcm_hw_params_dump(snd_pcm_hw_params_t *params, snd_output_t *out);
 int snd_pcm_sw_params_dump(snd_pcm_sw_params_t *params, snd_output_t *out);
 int snd_pcm_status_dump(snd_pcm_status_t *status, snd_output_t *out);
 
 int snd_pcm_mmap_begin(snd_pcm_t *pcm,
                const snd_pcm_channel_area_t **areas,
                snd_pcm_uframes_t *offset,
                snd_pcm_uframes_t *frames);
 snd_pcm_sframes_t snd_pcm_mmap_commit(snd_pcm_t *pcm,
                       snd_pcm_uframes_t offset,
                       snd_pcm_uframes_t frames);
 snd_pcm_sframes_t snd_pcm_mmap_writei(snd_pcm_t *pcm, const void *buffer, snd_pcm_uframes_t size);
 snd_pcm_sframes_t snd_pcm_mmap_readi(snd_pcm_t *pcm, void *buffer, snd_pcm_uframes_t size);
 snd_pcm_sframes_t snd_pcm_mmap_writen(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size);
 snd_pcm_sframes_t snd_pcm_mmap_readn(snd_pcm_t *pcm, void **bufs, snd_pcm_uframes_t size);                                                                
 
 int snd_pcm_format_signed(snd_pcm_format_t format);
 int snd_pcm_format_unsigned(snd_pcm_format_t format);
 int snd_pcm_format_linear(snd_pcm_format_t format);
 int snd_pcm_format_float(snd_pcm_format_t format);
 int snd_pcm_format_little_endian(snd_pcm_format_t format);
 int snd_pcm_format_big_endian(snd_pcm_format_t format);
 int snd_pcm_format_cpu_endian(snd_pcm_format_t format);
 int snd_pcm_format_width(snd_pcm_format_t format);          /* in bits */
 int snd_pcm_format_physical_width(snd_pcm_format_t format);     /* in bits */
 snd_pcm_format_t snd_pcm_build_linear_format(int width, int pwidth, int unsignd, int big_endian);
 ssize_t snd_pcm_format_size(snd_pcm_format_t format, size_t samples);
 uint8_t snd_pcm_format_silence(snd_pcm_format_t format);
 uint16_t snd_pcm_format_silence_16(snd_pcm_format_t format);
 uint32_t snd_pcm_format_silence_32(snd_pcm_format_t format);
 uint64_t snd_pcm_format_silence_64(snd_pcm_format_t format);
 int snd_pcm_format_set_silence(snd_pcm_format_t format, void *buf, unsigned int samples);
 
 snd_pcm_sframes_t snd_pcm_bytes_to_frames(snd_pcm_t *pcm, ssize_t bytes);
 ssize_t snd_pcm_frames_to_bytes(snd_pcm_t *pcm, snd_pcm_sframes_t frames);
 long snd_pcm_bytes_to_samples(snd_pcm_t *pcm, ssize_t bytes);
 ssize_t snd_pcm_samples_to_bytes(snd_pcm_t *pcm, long samples);
 
 int snd_pcm_area_silence(const snd_pcm_channel_area_t *dst_channel, snd_pcm_uframes_t dst_offset,
              unsigned int samples, snd_pcm_format_t format);
 int snd_pcm_areas_silence(const snd_pcm_channel_area_t *dst_channels, snd_pcm_uframes_t dst_offset,
               unsigned int channels, snd_pcm_uframes_t frames, snd_pcm_format_t format);
 int snd_pcm_area_copy(const snd_pcm_channel_area_t *dst_channel, snd_pcm_uframes_t dst_offset,
               const snd_pcm_channel_area_t *src_channel, snd_pcm_uframes_t src_offset,
               unsigned int samples, snd_pcm_format_t format);
 int snd_pcm_areas_copy(const snd_pcm_channel_area_t *dst_channels, snd_pcm_uframes_t dst_offset,
                const snd_pcm_channel_area_t *src_channels, snd_pcm_uframes_t src_offset,
                unsigned int channels, snd_pcm_uframes_t frames, snd_pcm_format_t format);
 int snd_pcm_areas_copy_wrap(const snd_pcm_channel_area_t *dst_channels,
                 snd_pcm_uframes_t dst_offset,
                 const snd_pcm_uframes_t dst_size,
                 const snd_pcm_channel_area_t *src_channels,
                 snd_pcm_uframes_t src_offset,
                 const snd_pcm_uframes_t src_size,
                 const unsigned int channels,
                 snd_pcm_uframes_t frames,
                 const snd_pcm_format_t format);
 
 typedef enum _snd_pcm_hook_type {
     SND_PCM_HOOK_TYPE_HW_PARAMS = 0,
     SND_PCM_HOOK_TYPE_HW_FREE,
     SND_PCM_HOOK_TYPE_CLOSE,
     SND_PCM_HOOK_TYPE_LAST = SND_PCM_HOOK_TYPE_CLOSE
 } snd_pcm_hook_type_t;
 
 typedef struct _snd_pcm_hook snd_pcm_hook_t;
 typedef int (*snd_pcm_hook_func_t)(snd_pcm_hook_t *hook);
 snd_pcm_t *snd_pcm_hook_get_pcm(snd_pcm_hook_t *hook);
 void *snd_pcm_hook_get_private(snd_pcm_hook_t *hook);
 void snd_pcm_hook_set_private(snd_pcm_hook_t *hook, void *private_data);
 int snd_pcm_hook_add(snd_pcm_hook_t **hookp, snd_pcm_t *pcm,
              snd_pcm_hook_type_t type,
              snd_pcm_hook_func_t func, void *private_data);
 int snd_pcm_hook_remove(snd_pcm_hook_t *hook);
 
 typedef struct _snd_pcm_scope_ops {
     int (*enable)(snd_pcm_scope_t *scope);
     void (*disable)(snd_pcm_scope_t *scope);
     void (*start)(snd_pcm_scope_t *scope);
     void (*stop)(snd_pcm_scope_t *scope);
     void (*update)(snd_pcm_scope_t *scope);
     void (*reset)(snd_pcm_scope_t *scope);
     void (*close)(snd_pcm_scope_t *scope);
 } snd_pcm_scope_ops_t;
 
 snd_pcm_uframes_t snd_pcm_meter_get_bufsize(snd_pcm_t *pcm);
 unsigned int snd_pcm_meter_get_channels(snd_pcm_t *pcm);
 unsigned int snd_pcm_meter_get_rate(snd_pcm_t *pcm);
 snd_pcm_uframes_t snd_pcm_meter_get_now(snd_pcm_t *pcm);
 snd_pcm_uframes_t snd_pcm_meter_get_boundary(snd_pcm_t *pcm);
 int snd_pcm_meter_add_scope(snd_pcm_t *pcm, snd_pcm_scope_t *scope);
 snd_pcm_scope_t *snd_pcm_meter_search_scope(snd_pcm_t *pcm, const char *name);
 int snd_pcm_scope_malloc(snd_pcm_scope_t **ptr);
 void snd_pcm_scope_set_ops(snd_pcm_scope_t *scope,
                const snd_pcm_scope_ops_t *val);
 void snd_pcm_scope_set_name(snd_pcm_scope_t *scope, const char *val);
 const char *snd_pcm_scope_get_name(snd_pcm_scope_t *scope);
 void *snd_pcm_scope_get_callback_private(snd_pcm_scope_t *scope);
 void snd_pcm_scope_set_callback_private(snd_pcm_scope_t *scope, void *val);
 int snd_pcm_scope_s16_open(snd_pcm_t *pcm, const char *name,
                snd_pcm_scope_t **scopep);
 int16_t *snd_pcm_scope_s16_get_channel_buffer(snd_pcm_scope_t *scope,
                           unsigned int channel);
 
 typedef enum _snd_spcm_latency {
     SND_SPCM_LATENCY_STANDARD = 0,
     SND_SPCM_LATENCY_MEDIUM,
     SND_SPCM_LATENCY_REALTIME
 } snd_spcm_latency_t;
 
 typedef enum _snd_spcm_xrun_type {
     SND_SPCM_XRUN_IGNORE = 0,
     SND_SPCM_XRUN_STOP
 } snd_spcm_xrun_type_t;
 
 typedef enum _snd_spcm_duplex_type {
     SND_SPCM_DUPLEX_LIBERAL = 0,
     SND_SPCM_DUPLEX_PEDANTIC
 } snd_spcm_duplex_type_t;
 
 int snd_spcm_init(snd_pcm_t *pcm,
           unsigned int rate,
           unsigned int channels,
           snd_pcm_format_t format,
           snd_pcm_subformat_t subformat,
           snd_spcm_latency_t latency,
           snd_pcm_access_t _access,
           snd_spcm_xrun_type_t xrun_type);
 
 int snd_spcm_init_duplex(snd_pcm_t *playback_pcm,
              snd_pcm_t *capture_pcm,
              unsigned int rate,
              unsigned int channels,
              snd_pcm_format_t format,
              snd_pcm_subformat_t subformat,
              snd_spcm_latency_t latency,
              snd_pcm_access_t _access,
              snd_spcm_xrun_type_t xrun_type,
              snd_spcm_duplex_type_t duplex_type);
 
 int snd_spcm_init_get_params(snd_pcm_t *pcm,
                  unsigned int *rate,
                  snd_pcm_uframes_t *buffer_size,
                  snd_pcm_uframes_t *period_size);
 
 /* Deprecated functions, for compatibility */
 const char *snd_pcm_start_mode_name(snd_pcm_start_t mode) __attribute__((deprecated));
 const char *snd_pcm_xrun_mode_name(snd_pcm_xrun_t mode) __attribute__((deprecated));
 int snd_pcm_sw_params_set_start_mode(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_start_t val) __attribute__((deprecated));
 snd_pcm_start_t snd_pcm_sw_params_get_start_mode(const snd_pcm_sw_params_t *params) __attribute__((deprecated));
 int snd_pcm_sw_params_set_xrun_mode(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_xrun_t val) __attribute__((deprecated));
 snd_pcm_xrun_t snd_pcm_sw_params_get_xrun_mode(const snd_pcm_sw_params_t *params) __attribute__((deprecated));
 #if !defined(ALSA_LIBRARY_BUILD) && !defined(ALSA_PCM_OLD_SW_PARAMS_API)
 int snd_pcm_sw_params_set_xfer_align(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, snd_pcm_uframes_t val) __attribute__((deprecated));
 int snd_pcm_sw_params_get_xfer_align(const snd_pcm_sw_params_t *params, snd_pcm_uframes_t *val) __attribute__((deprecated));
 int snd_pcm_sw_params_set_sleep_min(snd_pcm_t *pcm, snd_pcm_sw_params_t *params, unsigned int val) __attribute__((deprecated));
 int snd_pcm_sw_params_get_sleep_min(const snd_pcm_sw_params_t *params, unsigned int *val) __attribute__((deprecated));
 #endif /* !ALSA_LIBRARY_BUILD && !ALSA_PCM_OLD_SW_PARAMS_API */
 #if !defined(ALSA_LIBRARY_BUILD) && !defined(ALSA_PCM_OLD_HW_PARAMS_API)
 int snd_pcm_hw_params_get_tick_time(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_get_tick_time_min(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_get_tick_time_max(const snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_test_tick_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int val, int dir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time_min(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time_max(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time_minmax(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *min, int *mindir, unsigned int *max, int *maxdir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time_near(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time_first(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 int snd_pcm_hw_params_set_tick_time_last(snd_pcm_t *pcm, snd_pcm_hw_params_t *params, unsigned int *val, int *dir) __attribute__((deprecated));
 #endif /* !ALSA_LIBRARY_BUILD && !ALSA_PCM_OLD_HW_PARAMS_API */
 
 #ifdef __cplusplus
 }
 #endif
 
 #endif /* __ALSA_PCM_H */

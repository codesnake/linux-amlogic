/*
 * Video Enhancement
 *
 * Author: Lin Xu <lin.xu@amlogic.com>
 *         Bobby Yang <bo.yang@amlogic.com>
 *
 * Copyright (C) 2010 Amlogic Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __AM_VE_H
#define __AM_VE_H

#include <linux/amlogic/amports/vframe.h>
#include "linux/amlogic/amvecm/ve.h"

/* #if (MESON_CPU_TYPE >= MESON_CPU_TYPE_MESON8) */
/* #define WRITE_VPP_REG(x,val) */
/* WRITE_VCBUS_REG(x,val) */
/* #define WRITE_VPP_REG_BITS(x,val,start,length) */
/* WRITE_VCBUS_REG_BITS(x,val,start,length) */
/* #define READ_VPP_REG(x) */
/* READ_VCBUS_REG(x) */
/* #define READ_VPP_REG_BITS(x,start,length) */
/* READ_VCBUS_REG_BITS(x,start,length) */
/* #else */
/* #define WRITE_VPP_REG(x,val) */
/* WRITE_CBUS_REG(x,val) */
/* #define WRITE_VPP_REG_BITS(x,val,start,length) */
/* WRITE_CBUS_REG_BITS(x,val,start,length) */
/* #define READ_VPP_REG(x) */
/* READ_CBUS_REG(x) */
/* #define READ_VPP_REG_BITS(x,start,length) */
/* READ_CBUS_REG_BITS(x,start,length) */
/* #endif */


struct ve_regs_s {
	unsigned int val:32;
	unsigned int reg:14;
	unsigned int port:2;
			/* 0    NA  NA direct access */
			/* 1    VPP_CHROMA_ADDR_PORT */
			/* VPP_CHROMA_DATA_PORT CM port registers */
			/* 2    NA NA reserved */
			/* 3    NA NA reserved */
	unsigned int bit:5;
	unsigned int wid:5;
	unsigned int mode:1;
	unsigned int rsv:5;
};

extern struct ve_hist_s video_ve_hist;
extern unsigned int ve_size;
extern struct ve_dnlp_s am_ve_dnlp;
extern struct ve_dnlp_table_s am_ve_new_dnlp;
extern struct tcon_gamma_table_s video_gamma_table_r;
extern struct tcon_gamma_table_s video_gamma_table_g;
extern struct tcon_gamma_table_s video_gamma_table_b;
extern struct tcon_gamma_table_s video_gamma_table_r_adj;
extern struct tcon_gamma_table_s video_gamma_table_g_adj;
extern struct tcon_gamma_table_s video_gamma_table_b_adj;
extern struct tcon_rgb_ogo_s     video_rgb_ogo;

void ve_on_vs(struct vframe_s *vf);

void ve_set_bext(struct ve_bext_s *p);
void ve_set_dnlp(struct ve_dnlp_s *p);
void ve_set_new_dnlp(struct ve_dnlp_table_s *p);
void ve_set_dnlp_2(void);
void ve_set_hsvs(struct ve_hsvs_s *p);
void ve_set_ccor(struct ve_ccor_s *p);
void ve_set_benh(struct ve_benh_s *p);
void ve_set_demo(struct ve_demo_s *p);
void ve_set_regs(struct ve_regs_s *p);
void ve_set_regmap(struct ve_regmap_s *p);

extern void ve_enable_dnlp(void);
extern void ve_disable_dnlp(void);

extern void vpp_enable_lcd_gamma_table(void);
extern void vpp_disable_lcd_gamma_table(void);
extern void vpp_set_lcd_gamma_table(u16 *data, u32 rgb_mask);
extern void vpp_set_rgb_ogo(struct tcon_rgb_ogo_s *p);
extern void vpp_phase_lock_on_vs(unsigned int cycle,
				 unsigned int stamp,
				 bool         lock50,
				 unsigned int range_fast,
				 unsigned int range_slow);
/* #if (MESON_CPU_TYPE>=MESON_CPU_TYPE_MESON6TVD) */
extern void ve_frame_size_patch(unsigned int width, unsigned int height);
/* #endif */
extern void ve_dnlp_latch_process(void);
extern void ve_lcd_gamma_process(void);
extern void lvds_freq_process(void);
extern void ve_dnlp_param_update(void);
extern void ve_new_dnlp_param_update(void);
extern void ve_ogo_param_update(void);
extern void am_set_regmap(struct am_regs_s *p);
extern void sharpness_process(struct vframe_s *vf);
extern void amvecm_bricon_process(unsigned int bri_val,
				unsigned int cont_val, struct vframe_s *vf);
extern void amvecm_3d_black_process(void);
extern void amvecm_3d_sync_process(void);
extern void amve_vlock_process(struct vframe_s *vf);

int amvecm_hiu_reg_read(unsigned int reg, unsigned int *val);
int amvecm_hiu_reg_write(unsigned int reg, unsigned int val);
extern unsigned int vecm_latch_flag;
extern unsigned int cm_size;
extern unsigned int sync_3d_h_start;
extern unsigned int sync_3d_h_end;
extern unsigned int sync_3d_v_start;
extern unsigned int sync_3d_v_end;
extern unsigned int sync_3d_polarity;
extern unsigned int sync_3d_out_inv;

extern void __iomem *amvecm_hiu_reg_base;

#ifdef CONFIG_VSYNC_RDMA
extern int VSYNC_WR_MPEG_REG(u32 adr, u32 val);
extern u32 VSYNC_RD_MPEG_REG(u32 adr);
#endif

/* #if defined(CONFIG_ARCH_MESON2) */
/* unsigned long long ve_get_vs_cnt(void); */
/* #endif */

#endif


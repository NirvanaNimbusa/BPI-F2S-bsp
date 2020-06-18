#include "pinctrl_sunplus_sp7021.h"

static const unsigned pins_spif1[] = {
	D(10,3), D(10,4), D(10,6), D(10,7)
};
static const unsigned pins_spif2[] = {
	D(9,4), D(9,6), D(9,7), D(10,1)
};
static const sp7021grp_t sp7021grps_spif[] = {
	EGRP("SPI_FLASH1", 1, pins_spif1),
	EGRP("SPI_FLASH2", 2, pins_spif2)
};

static const unsigned pins_spi41[] = { D(10,2), D(10,5) };
static const unsigned pins_spi42[] = { D(9,5), D(9,8) };
static const sp7021grp_t sp7021grps_spi4[] = {
	EGRP("SPI_FLASH_4BIT1", 1, pins_spi41),
	EGRP("SPI_FLASH_4BIT2", 2, pins_spi42)
};

static const unsigned pins_snan[] = {
	D(9,4), D(9,5), D(9,6), D(9,7), D(10,0), D(10,1)
};
static const sp7021grp_t sp7021grps_snan[] = {
	EGRP("SPI_NAND", 1, pins_snan)
};

static const unsigned pins_emmc[] = {
	D(9,0), D(9,1), D(9,2), D(9,3), D(9,4), D(9,5),
	D(9,6), D(9,7), D(10,0), D(10,1)
};
static const sp7021grp_t sp7021grps_emmc[] = {
	EGRP("CARD0_EMMC", 1, pins_emmc)
};

static const unsigned pins_sdsd[] = {
	D(8,1), D(8,2), D(8,3), D(8,4), D(8,5), D(8,6)
};
static const sp7021grp_t sp7021grps_sdsd[] = {
	EGRP("SD_CARD", 1, pins_sdsd)
};

static const unsigned pins_uar0[] = { D(11,0), D(11,1) };
static const sp7021grp_t sp7021grps_uar0[] = {
	EGRP("UA0", 1, pins_uar0)
};

static const unsigned pins_adbg1[] = { D(10,2), D(10,3) };
static const unsigned pins_adbg2[] = { D(7,1), D(7,2) };
static const sp7021grp_t sp7021grps_adbg[] = {
	EGRP("ACHIP_DEBUG1", 1, pins_adbg1),
	EGRP("ACHIP_DEBUG2", 2, pins_adbg2)
};

static const unsigned pins_aua2axi1[] = { D(2,0), D(2,1), D(2,2) };
static const unsigned pins_aua2axi2[] = { D(1,0), D(1,1), D(1,2) };
static const sp7021grp_t sp7021grps_au2x[] = {
	EGRP("ACHIP_UA2AXI1", 1, pins_aua2axi1),
	EGRP("ACHIP_UA2AXI2", 2, pins_aua2axi2)
};

static const unsigned pins_fpga[] = {
	D(0,2), D(0,3), D(0,4), D(0,5), D(0,6), D(0,7),
	D(1,0), D(1,1), D(1,2), D(1,3), D(1,4), D(1,5),
	D(1,6), D(1,7), D(2,0), D(2,1), D(2,2), D(2,3),
	D(2,4), D(2,5), D(2,6), D(2,7), D(3,0), D(3,1),
	D(3,2), D(3,3), D(3,4), D(3,5), D(3,6), D(3,7),
	D(4,0), D(4,1), D(4,2), D(4,3), D(4,4), D(4,5),
	D(4,6), D(4,7), D(5,0), D(5,1), D(5,2)
};
static const sp7021grp_t sp7021grps_fpga[] = {
	EGRP("FPGA_IFX", 1, pins_fpga)
};

static const unsigned pins_hdmi1[] = { D(10,6), D(12,2), D(12,1) };
static const unsigned pins_hdmi2[] = { D(8,3), D(8,5), D(8,6) };
static const unsigned pins_hdmi3[] = { D(7,4), D(7,6), D(7,7) };
static const sp7021grp_t sp7021grps_hdmi[] = {
	EGRP("HDMI_TX1", 1, pins_hdmi1),
	EGRP("HDMI_TX2", 2, pins_hdmi2),
	EGRP("HDMI_TX3", 3, pins_hdmi3)
};

static const unsigned pins_eadc[] = {
	D(1,0), D(1,1), D(1,2), D(1,3), D(1,4), D(1,5), D(1,6)
};
static const sp7021grp_t sp7021grps_eadc[] = {
	EGRP("AUD_EXT_ADC_IFX0", 1, pins_eadc)
};

static const unsigned pins_edac[] = {
	D(2,5), D(2,6), D(2,7), D(3,0), D(3,1), D(3,2), D(3,4)
};
static const sp7021grp_t sp7021grps_edac[] = {
	EGRP("AUD_EXT_DAC_IFX0", 1, pins_edac)
};

static const unsigned pins_spdi[] = { D(2,4) };
static const sp7021grp_t sp7021grps_spdi[] = {
	EGRP("AUD_IEC_RX0", 1, pins_spdi)
};
static const unsigned pins_spdo[] = { D(3,6) };
static const sp7021grp_t sp7021grps_spdo[] = {
	EGRP("AUD_IEC_TX0", 1, pins_spdo)
};

static const unsigned pins_tdmt[] = {
	D(2,5), D(2,6), D(2,7), D(3,0), D(3,1), D(3,2)
};
static const sp7021grp_t sp7021grps_tdmt[] = {
	EGRP("TDMTX_IFX0", 1, pins_tdmt)
};

static const unsigned pins_tdmr[] = {
	D(1,7), D(2,0), D(2,1), D(2,2)
};
static const sp7021grp_t sp7021grps_tdmr[] = {
	EGRP("TDMRX_IFX0", 1, pins_tdmr)
};

static const unsigned pins_pdmr[] = {
	D(1,7), D(2,0), D(2,1), D(2,2), D(2,3)
};
static const sp7021grp_t sp7021grps_pdmr[] = {
	EGRP("PDMRX_IFX0", 1, pins_pdmr)
};

static const unsigned pins_pcmt[] = {
	D(3,7), D(4,0), D(4,1), D(4,2), D(4,3), D(4,4)
};
static const sp7021grp_t sp7021grps_pcmt[] = {
	EGRP("PCM_IEC_TX", 1, pins_pcmt)
};

static const unsigned pins_lcdi[] = {
	D(1,4), D(1,5), D(1,6), D(1,7),
	D(2,0), D(2,1), D(2,2), D(2,3), D(2,4), D(2,5), D(2,6), D(2,7),
	D(3,0), D(3,1), D(3,2), D(3,3), D(3,4), D(3,5), D(3,6), D(3,7),
	D(4,0), D(4,1), D(4,2), D(4,3), D(4,4), D(4,5), D(4,6), D(4,7)
};
static const sp7021grp_t sp7021grps_lcdi[] = {
	EGRP("LCDIF", 1, pins_lcdi)
};

static const unsigned pins_dvdd[] = {
	D(7,0), D(7,1), D(7,2), D(7,3), D(7,4), D(7,5), D(7,6), D(7,7),
	D(8,0), D(8,1), D(8,2), D(8,3), D(8,4), D(8,5)
};
static const sp7021grp_t sp7021grps_dvdd[] = {
	EGRP("DVD_DSP_DEBUG", 1, pins_dvdd)
};

static const unsigned pins_i2cd[] = { D(1,0), D(1,1) };
static const sp7021grp_t sp7021grps_i2cd[] = {
	EGRP("I2C_DEBUG", 1, pins_i2cd)
};

static const unsigned pins_i2cs[] = { D(0,0), D(0,1) };
static const sp7021grp_t sp7021grps_i2cs[] = {
	EGRP("I2C_SLAVE", 1, pins_i2cs)
};

static const unsigned pins_wakp[] = { D(10,5) };
static const sp7021grp_t sp7021grps_wakp[] = {
	EGRP("WAKEUP", 1, pins_wakp)
};

static const unsigned pins_u2ax[] = {
	D(2,0), D(2,1), D(3,0), D(3,1)
};
static const sp7021grp_t sp7021grps_u2ax[] = {
	EGRP("UART2AXI", 1, pins_u2ax)
};

static const unsigned pins_u0ic[] = {
	D(0,0), D(0,1), D(0,4), D(0,5), D(1,0), D(1,1)
};
static const sp7021grp_t sp7021grps_u0ic[] = {
	EGRP("USB0_I2C", 1, pins_u0ic)
};

static const unsigned pins_u1ic[] = {
	D(0,2), D(0,3), D(0,6), D(0,7), D(1,2), D(1,3)
};
static const sp7021grp_t sp7021grps_u1ic[] = {
	EGRP("USB1_I2C", 1, pins_u1ic)
};

static const unsigned pins_u0ot[] = { D(11,2) };
static const sp7021grp_t sp7021grps_u0ot[] = {
	EGRP("USB0_OTG", 1, pins_u0ot)
};

static const unsigned pins_u1ot[] = { D(11,3) };
static const sp7021grp_t sp7021grps_u1ot[] = {
	EGRP("USB1_OTG", 1, pins_u1ot)
};

static const unsigned pins_uphd[] = {
	D(0,1), D(0,2), D(0,3), D(7,4), D(7,5), D(7,6),
	D(7,7), D(8,0), D(8,1), D(8,2), D(8,3), D(9,7),
	D(10,2), D(10,3), D(10,4)
};
static const sp7021grp_t sp7021grps_up0d[] = {
	EGRP("UPHY0_DEBUG", 1, pins_uphd)
};
static const sp7021grp_t sp7021grps_up1d[] = {
	EGRP("UPHY1_DEBUG", 1, pins_uphd)
};

static const unsigned pins_upex[] = {
	D(0,0), D(0,1), D(0,2), D(0,3), D(0,4), D(0,5), D(0,6), D(0,7),
	D(1,0), D(1,1), D(1,2), D(1,3), D(1,4), D(1,5), D(1,6), D(1,7),
	D(2,0), D(2,1), D(2,2), D(2,3), D(2,4), D(2,5), D(2,6), D(2,7),
	D(3,0), D(3,1), D(3,2), D(3,3), D(3,4), D(3,5), D(3,6), D(3,7),
	D(4,0), D(4,1), D(4,2), D(4,3), D(4,4), D(4,5), D(4,6), D(4,7),
	D(5,0), D(5,1), D(5,2), D(5,3), D(5,4), D(5,5), D(5,6), D(5,7),
	D(6,0), D(6,1), D(6,2), D(6,3), D(6,4), D(6,5), D(6,6), D(6,7),
	D(7,0), D(7,1), D(7,2), D(7,3), D(7,4), D(7,5), D(7,6), D(7,7),
	D(8,0), D(8,1), D(8,2), D(8,3), D(8,4), D(8,5), D(8,6), D(8,7),
	D(9,0), D(9,1), D(9,2), D(9,3), D(9,4), D(9,5), D(9,6), D(9,7),
	D(10,0), D(10,1), D(10,2), D(10,3), D(10,4), D(10,5), D(10,6), D(10,7)
};
static const sp7021grp_t sp7021grps_upex[] = {
	EGRP("UPHY0_EXT", 1, pins_upex)
};

static const unsigned pins_prp1[] = {
	D(0,6), D(0,7),
	D(1,0), D(1,1), D(1,2), D(1,3), D(1,4), D(1,5), D(1,6), D(1,7),
	D(2,1), D(2,2), D(2,3), D(2,4), D(2,5), D(2,6), D(2,7),
	D(3,0), D(3,1), D(3,2)
};
static const unsigned pins_prp2[] = {
	D(3,4), D(3,6), D(3,7),
	D(4,0), D(4,1), D(4,2), D(4,3), D(4,4), D(4,5), D(4,6), D(4,7),
	D(5,0), D(5,1), D(5,2), D(5,3), D(5,4), D(5,5), D(5,6), D(5,7),
	D(6,4)
};
static const sp7021grp_t sp7021grps_prbp[] = {
	EGRP("PROBE_PORT1", 1, pins_prp1),
	EGRP("PROBE_PORT2", 2, pins_prp2)
};

static const unsigned pins_anai[] = { D(0,4), D(0,5) };
static const sp7021grp_t sp7021grps_anai[] = {
	EGRP("ANA_I2C_IF", 1, pins_anai)
};

static const unsigned pins_anat[] = {
	D(0,0), D(0,1), D(0,2), D(0,3), D(0,4), D(0,5), D(0,6), D(0,7),
	D(1,0), D(1,1), D(1,2), D(1,3), D(1,4), D(1,5), D(1,6),
	D(11,0)
};
static const sp7021grp_t sp7021grps_anat[] = {
	EGRP("ANA_TEST_IF", 1, pins_anat)
};

func_t list_funcs[] = {
	FNCE("SPI_FLASH",        1, 0,  2, sp7021grps_spif),
	FNCE("SPI_FLASH_4BIT",   1, 2,  2, sp7021grps_spi4),
	FNCE("SPI_NAND",         1, 4,  1, sp7021grps_snan),
	FNCE("CARD0_EMMC",       1, 5,  1, sp7021grps_emmc),
	FNCE("SD_CARD",          1, 6,  1, sp7021grps_sdsd),
	FNCE("UA0",              1, 7,  1, sp7021grps_uar0),
	FNCE("ACHIP_DEBUG",      1, 8,  2, sp7021grps_adbg),
	FNCE("ACHIP_UA2AXI",     1, 10, 2, sp7021grps_au2x),
	FNCE("FPGA_IFX",         1, 12, 1, sp7021grps_fpga),
	FNCE("HDMI_TX",          1, 13, 2, sp7021grps_hdmi),
	FNCE("AUD_EXT_ADC_IFX0", 1, 15, 1, sp7021grps_eadc),   // I2S audio in
	FNCE("AUD_EXT_DAC_IFX0", 2, 0,  1, sp7021grps_edac),   // I2S audio out
	FNCE("SPDIF_RX",         2, 2,  1, sp7021grps_spdi),
	FNCE("SPDIF_TX",         2, 3,  1, sp7021grps_spdo),
	FNCE("TDMTX_IFX0",       2, 4,  1, sp7021grps_tdmt),
	FNCE("TDMRX_IFX0",       2, 5,  1, sp7021grps_tdmr),
	FNCE("PDMRX_IFX0",       2, 6,  1, sp7021grps_pdmr),
	FNCE("PCM_IEC_TX",       2, 7,  1, sp7021grps_pcmt),
	FNCE("DVD_DSP_DEBUG",    2, 8,  1, sp7021grps_dvdd),
	FNCE("I2C_DEBUG",        2, 9,  1, sp7021grps_i2cd),
	FNCE("I2C_SLAVE",        2, 10, 1, sp7021grps_i2cs),   // I2C slave
	FNCE("WAKEUP",           2, 11, 1, sp7021grps_wakp),
	FNCE("UART2AXI",         2, 12, 2, sp7021grps_u2ax),
	FNCE("USB0_I2C",         2, 14, 2, sp7021grps_u0ic),
	FNCE("USB1_I2C",         3, 0,  2, sp7021grps_u1ic),
	FNCE("USB0_OTG",         3, 2,  1, sp7021grps_u0ot),
	FNCE("USB1_OTG",         3, 3,  1, sp7021grps_u1ot),
	FNCE("UPHY0_DEBUG",      3, 4,  1, sp7021grps_up0d),
	FNCE("UPHY1_DEBUG",      3, 5,  1, sp7021grps_up1d),
	FNCE("UPHY0_EXT",        3, 6,  1, sp7021grps_upex),
	FNCE("PROBE_PORT",       3, 7,  2, sp7021grps_prbp),
	FNCE("ANA_I2C_IF",       3, 7,  2, sp7021grps_anai),
	FNCE("ANA_TEST_IF",      3, 7,  2, sp7021grps_anat),
	FNCE("LCDIF",            4, 6,  1, sp7021grps_lcdi),
};

const int list_funcsSZ = ARRAY_SIZE(list_funcs);

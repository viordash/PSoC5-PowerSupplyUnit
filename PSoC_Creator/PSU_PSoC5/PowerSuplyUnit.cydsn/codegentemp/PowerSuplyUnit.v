// ======================================================================
// PowerSuplyUnit.v generated from TopDesign.cysch
// 06/08/2017 at 22:53
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 19
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: cy_vref_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// ADC_SAR_v3_0(ADC_Clock=1, ADC_Clock_Frequency=1800000, ADC_Input_Range=0, ADC_Power=0, ADC_Reference=1, ADC_Resolution=12, ADC_SampleMode=0, Enable_next_out=false, Ref_Voltage=1.024, Ref_Voltage_mV=1024, rm_int=false, Sample_Precharge=6, Sample_Rate=100000, Sample_Rate_def=631579, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ADC_SAR_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=ADC_VoltageChanelB, CY_INSTANCE_SHORT_NAME=ADC_VoltageChanelB, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=ADC_VoltageChanelB, )
module ADC_SAR_v3_0_0 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    vdac_ref,
    eos);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       vdac_ref;
    electrical  vdac_ref;
    output      eos;


          wire [3:0] vp_ctl;
          wire [3:0] vn_ctl;
          wire  Net_381;
    electrical  Net_255;
    electrical  Net_267;
    electrical  Net_210;
    electrical  Net_209;
          wire [11:0] Net_207;
          wire  Net_252;
          wire  Net_205;
          wire  Net_378;
          wire  Net_376;
    electrical  Net_368;
    electrical  Net_235;
    electrical  Net_216;
    electrical  Net_233;
          wire  Net_221;
    electrical  Net_248;
    electrical  Net_257;
    electrical  Net_149;
    electrical  Net_126;
    electrical  Net_215;
          wire  Net_188;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_248, Net_233);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


    ZeroTerminal ZeroTerminal_1 (
        .z(vp_ctl[0]));

    ZeroTerminal ZeroTerminal_2 (
        .z(vp_ctl[2]));

    ZeroTerminal ZeroTerminal_3 (
        .z(vn_ctl[1]));

    ZeroTerminal ZeroTerminal_4 (
        .z(vn_ctl[3]));

    ZeroTerminal ZeroTerminal_5 (
        .z(vp_ctl[1]));

    ZeroTerminal ZeroTerminal_6 (
        .z(vp_ctl[3]));

    ZeroTerminal ZeroTerminal_7 (
        .z(vn_ctl[0]));

    ZeroTerminal ZeroTerminal_8 (
        .z(vn_ctl[2]));


	cy_clock_v1_0
		#(.id("32fa1dd9-a04c-4828-a353-ce0f3fc17b02/696a0979-21fc-4185-bf38-6c79febcde7a"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("555555555.555556"),
		  .is_direct(0),
		  .is_digital(1))
		theACLK
		 (.clock_out(Net_376));


	// Clock_VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_188 = Net_221;

    cy_psoc5_sar_v2_0 ADC_SAR (
        .clock(Net_188),
        .sof_udb(soc),
        .clk_udb(),
        .vp_ctl_udb(vp_ctl[3:0]),
        .vn_ctl_udb(vn_ctl[3:0]),
        .vplus(vplus),
        .vminus(Net_126),
        .irq(Net_252),
        .data_out(Net_207[11:0]),
        .eof_udb(eoc),
        .pump_clock(Net_188),
        .ext_pin(Net_215),
        .vrefhi_out(Net_257),
        .vref(Net_248),
        .next_out(eos));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_215, Net_210);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	wire [0:0] tmpOE__Bypass_net;
	wire [0:0] tmpFB_0__Bypass_net;
	wire [0:0] tmpIO_0__Bypass_net;
	wire [0:0] tmpINTERRUPT_0__Bypass_net;
	electrical [0:0] tmpSIOVREF__Bypass_net;

	cy_psoc3_pins_v1_10
		#(.id("32fa1dd9-a04c-4828-a353-ce0f3fc17b02/16a808f6-2e13-45b9-bce0-b001c8655113"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Bypass
		 (.oe(tmpOE__Bypass_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Bypass_net[0:0]}),
		  .analog({Net_210}),
		  .io({tmpIO_0__Bypass_net[0:0]}),
		  .siovref(tmpSIOVREF__Bypass_net),
		  .interrupt({tmpINTERRUPT_0__Bypass_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Bypass_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_126, Net_149);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 noconnect (
        .noconnect(Net_209));


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("89B398AD-36A8-4627-9212-707F2986319E"),
		  .name("1.024V"))
		vRef_1024
		 (.vout(Net_233));


	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_257, Net_149);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_255));

    cy_analog_noconnect_v1_0 noconnect_1 (
        .noconnect(Net_368));


    assign Net_221 = Net_381 | Net_376;

    assign Net_381 = 1'h0;



endmodule

// ADC_DelSig_v3_20(ADC_Alignment=0, ADC_Alignment_Config2=0, ADC_Alignment_Config3=0, ADC_Alignment_Config4=0, ADC_Charge_Pump_Clock=true, ADC_Clock=1, ADC_CLOCK_FREQUENCY=128018, ADC_Input_Mode=0, ADC_Input_Range=8, ADC_Input_Range_Config2=4, ADC_Input_Range_Config3=4, ADC_Input_Range_Config4=4, ADC_Power=1, ADC_Reference=2, ADC_Reference_Config2=0, ADC_Reference_Config3=0, ADC_Reference_Config4=0, ADC_Resolution=14, ADC_Resolution_Config2=16, ADC_Resolution_Config3=16, ADC_Resolution_Config4=16, Clock_Frequency=64000, Comment_Config1=Default Config, Comment_Config2=Second Config, Comment_Config3=Third Config, Comment_Config4=Fourth Config, Config1_Name=CFG1, Config2_Name=CFG2, Config3_Name=CFG3, Config4_Name=CFG4, Configs=4, Conversion_Mode=2, Conversion_Mode_Config2=2, Conversion_Mode_Config3=2, Conversion_Mode_Config4=2, Enable_Vref_Vss=true, EnableModulatorInput=false, Input_Buffer_Gain=1, Input_Buffer_Gain_Config2=1, Input_Buffer_Gain_Config3=1, Input_Buffer_Gain_Config4=1, Input_Buffer_Mode=1, Input_Buffer_Mode_Config2=1, Input_Buffer_Mode_Config3=1, Input_Buffer_Mode_Config4=1, Ref_Voltage=1.024, Ref_Voltage_Config2=1.024, Ref_Voltage_Config3=1.024, Ref_Voltage_Config4=1.024, rm_int=false, Sample_Rate=2783, Sample_Rate_Config2=2000, Sample_Rate_Config3=2000, Sample_Rate_Config4=2000, Start_of_Conversion=0, Vdda_Value=5, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ADC_DelSig_v3_20, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=ADC_Current, CY_INSTANCE_SHORT_NAME=ADC_Current, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=20, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=ADC_Current, )
module ADC_DelSig_v3_20_1 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    nVref,
    mi);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       nVref;
    electrical  nVref;
    input       mi;


          wire  Net_268;
          wire  Net_270;
          wire  Net_252;
          wire  Net_275;
          wire  Net_250;
    electrical  Net_249;
    electrical  Net_257;
    electrical  Net_248;
    electrical  Net_23;
          wire  Net_247;
          wire  aclock;
          wire [3:0] mod_dat;
          wire  mod_reset;
    electrical  Net_352;
          wire  Net_246;
          wire [7:0] Net_245;
          wire  Net_482;
    electrical  Net_34;
    electrical  Net_35;
    electrical  Net_244;
          wire  Net_93;
    electrical  Net_20;
    electrical  Net_690;
    electrical  Net_686;
    electrical  Net_520;
          wire  Net_481;
    electrical  Net_677;
    electrical  Net_41;
    electrical  Net_573;
    electrical  Net_109;
          wire  Net_488;

	// cy_analog_virtualmux_6 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_6_connect(Net_690, Net_35);
	defparam cy_analog_virtualmux_6_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_34));

	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_677, Net_34);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    cy_psoc3_ds_mod_v4_0 DSM (
        .vplus(vplus),
        .vminus(Net_520),
        .modbit(Net_481),
        .reset_udb(Net_482),
        .aclock(Net_488),
        .mod_dat(mod_dat[3:0]),
        .dout_udb(Net_245[7:0]),
        .reset_dec(mod_reset),
        .dec_clock(aclock),
        .extclk_cp_udb(Net_93),
        .clk_udb(1'b0),
        .ext_pin_1(Net_573),
        .ext_pin_2(Net_41),
        .ext_vssa(Net_109),
        .qtz_ref(Net_677));
    defparam DSM.resolution = 14;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_5 (
        .noconnect(Net_352));

	// cy_analog_virtualmux_5 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_5_connect(Net_109, nVref);
	defparam cy_analog_virtualmux_5_connect.sig_width = 1;


	cy_clock_v1_0
		#(.id("2c96cbc0-bb62-4679-a9ea-dced38ba4eac/b7604721-db56-4477-98c2-8fae77869066"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(1),
		  .period("0"),
		  .is_direct(0),
		  .is_digital(1))
		Ext_CP_Clk
		 (.clock_out(Net_93));


	wire [0:0] tmpOE__Bypass_P32_net;
	wire [0:0] tmpFB_0__Bypass_P32_net;
	wire [0:0] tmpIO_0__Bypass_P32_net;
	wire [0:0] tmpINTERRUPT_0__Bypass_P32_net;
	electrical [0:0] tmpSIOVREF__Bypass_P32_net;

	cy_psoc3_pins_v1_10
		#(.id("2c96cbc0-bb62-4679-a9ea-dced38ba4eac/93327f79-f616-44c2-ae10-d5db5cc52542"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Bypass_P32
		 (.oe(tmpOE__Bypass_P32_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Bypass_P32_net[0:0]}),
		  .analog({Net_23}),
		  .io({tmpIO_0__Bypass_P32_net[0:0]}),
		  .siovref(tmpSIOVREF__Bypass_P32_net),
		  .interrupt({tmpINTERRUPT_0__Bypass_P32_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Bypass_P32_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_257));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_249));

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_41, Net_23);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_573, Net_249);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_520, vminus);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


	// Clock_VirtualMux (cy_virtualmux_v1_0)
	assign Net_488 = Net_250;


	cy_clock_v1_0
		#(.id("2c96cbc0-bb62-4679-a9ea-dced38ba4eac/edd15f43-b66b-457b-be3a-5342345270c8"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("7812500000"),
		  .is_direct(0),
		  .is_digital(0))
		theACLK
		 (.clock_out(Net_250));


    ZeroTerminal ZeroTerminal_2 (
        .z(Net_482));

	// Clock_VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_481 = Net_252;

    cy_psoc3_decimator_v1_0 DEC (
        .aclock(aclock),
        .mod_dat(mod_dat[3:0]),
        .ext_start(soc),
        .mod_reset(mod_reset),
        .interrupt(eoc));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_252));


    assign Net_268 = Net_270 | Net_93;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_270));



endmodule

// PGA_v2_0(Gain=0, Power=3, VddaValue=5, Vref_Input=1, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=PGA_v2_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PGA_1, CY_INSTANCE_SHORT_NAME=PGA_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=PGA_1, )
module PGA_v2_0_2 (
    Vin,
    Vref,
    Vout);
    inout       Vin;
    electrical  Vin;
    inout       Vref;
    electrical  Vref;
    inout       Vout;
    electrical  Vout;


    electrical  Net_75;
          wire  Net_41;
          wire  Net_40;
    electrical  Net_17;
          wire  Net_39;
          wire  Net_38;
          wire  Net_37;

    cy_psoc3_scblock_v1_0 SC (
        .vin(Vin),
        .vref(Net_17),
        .vout(Vout),
        .modout_sync(Net_41),
        .aclk(Net_37),
        .clk_udb(Net_38),
        .dyn_cntl(Net_39),
        .bst_clk(Net_40));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_37));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_38));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_39));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_40));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_17, Vref);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_75));



endmodule

// Component: AMuxHw_v1_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxHw_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxHw_v1_50\AMuxHw_v1_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxHw_v1_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\AMuxHw_v1_50\AMuxHw_v1_50.v"
`endif

// ADC_SAR_v3_0(ADC_Clock=1, ADC_Clock_Frequency=1800000, ADC_Input_Range=0, ADC_Power=0, ADC_Reference=1, ADC_Resolution=12, ADC_SampleMode=0, Enable_next_out=false, Ref_Voltage=1.024, Ref_Voltage_mV=1024, rm_int=false, Sample_Precharge=6, Sample_Rate=100000, Sample_Rate_def=631579, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ADC_SAR_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=ADC_VoltageChanelA, CY_INSTANCE_SHORT_NAME=ADC_VoltageChanelA, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=ADC_VoltageChanelA, )
module ADC_SAR_v3_0_3 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    vdac_ref,
    eos);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       vdac_ref;
    electrical  vdac_ref;
    output      eos;


          wire [3:0] vp_ctl;
          wire [3:0] vn_ctl;
          wire  Net_381;
    electrical  Net_255;
    electrical  Net_267;
    electrical  Net_210;
    electrical  Net_209;
          wire [11:0] Net_207;
          wire  Net_252;
          wire  Net_205;
          wire  Net_378;
          wire  Net_376;
    electrical  Net_368;
    electrical  Net_235;
    electrical  Net_216;
    electrical  Net_233;
          wire  Net_221;
    electrical  Net_248;
    electrical  Net_257;
    electrical  Net_149;
    electrical  Net_126;
    electrical  Net_215;
          wire  Net_188;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_248, Net_233);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


    ZeroTerminal ZeroTerminal_1 (
        .z(vp_ctl[0]));

    ZeroTerminal ZeroTerminal_2 (
        .z(vp_ctl[2]));

    ZeroTerminal ZeroTerminal_3 (
        .z(vn_ctl[1]));

    ZeroTerminal ZeroTerminal_4 (
        .z(vn_ctl[3]));

    ZeroTerminal ZeroTerminal_5 (
        .z(vp_ctl[1]));

    ZeroTerminal ZeroTerminal_6 (
        .z(vp_ctl[3]));

    ZeroTerminal ZeroTerminal_7 (
        .z(vn_ctl[0]));

    ZeroTerminal ZeroTerminal_8 (
        .z(vn_ctl[2]));


	cy_clock_v1_0
		#(.id("e152c54b-07df-43bb-9730-e2f26eaf6a9e/696a0979-21fc-4185-bf38-6c79febcde7a"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("555555555.555556"),
		  .is_direct(0),
		  .is_digital(1))
		theACLK
		 (.clock_out(Net_376));


	// Clock_VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_188 = Net_221;

    cy_psoc5_sar_v2_0 ADC_SAR (
        .clock(Net_188),
        .sof_udb(soc),
        .clk_udb(),
        .vp_ctl_udb(vp_ctl[3:0]),
        .vn_ctl_udb(vn_ctl[3:0]),
        .vplus(vplus),
        .vminus(Net_126),
        .irq(Net_252),
        .data_out(Net_207[11:0]),
        .eof_udb(eoc),
        .pump_clock(Net_188),
        .ext_pin(Net_215),
        .vrefhi_out(Net_257),
        .vref(Net_248),
        .next_out(eos));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_215, Net_210);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	wire [0:0] tmpOE__Bypass_net;
	wire [0:0] tmpFB_0__Bypass_net;
	wire [0:0] tmpIO_0__Bypass_net;
	wire [0:0] tmpINTERRUPT_0__Bypass_net;
	electrical [0:0] tmpSIOVREF__Bypass_net;

	cy_psoc3_pins_v1_10
		#(.id("e152c54b-07df-43bb-9730-e2f26eaf6a9e/16a808f6-2e13-45b9-bce0-b001c8655113"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .use_annotation(1'b0),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b0),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .vtrip(2'b10),
		  .width(1))
		Bypass
		 (.oe(tmpOE__Bypass_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Bypass_net[0:0]}),
		  .analog({Net_210}),
		  .io({tmpIO_0__Bypass_net[0:0]}),
		  .siovref(tmpSIOVREF__Bypass_net),
		  .interrupt({tmpINTERRUPT_0__Bypass_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Bypass_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_126, Net_149);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 noconnect (
        .noconnect(Net_209));


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("89B398AD-36A8-4627-9212-707F2986319E"),
		  .name("1.024V"))
		vRef_1024
		 (.vout(Net_233));


	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_257, Net_149);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_255));

    cy_analog_noconnect_v1_0 noconnect_1 (
        .noconnect(Net_368));


    assign Net_221 = Net_381 | Net_376;

    assign Net_381 = 1'h0;



endmodule

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: B_PWM_v3_30
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_PWM_v3_30\B_PWM_v3_30.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=127, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=255, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=false, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=false, UseStatus=false, VerilogSectionReplacementString=sP16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=PWM_v3_30, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_2, CY_INSTANCE_SHORT_NAME=PWM_2, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=PWM_2, )
module PWM_v3_30_4 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v3_30 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 0;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=true, Compare1_8=false, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=127, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=255, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=false, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=false, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=true, UDB8=false, UseControl=true, UseInterrupt=false, UseStatus=false, VerilogSectionReplacementString=sP16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=PWM_v3_30, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=PWM_1, CY_INSTANCE_SHORT_NAME=PWM_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=PWM_1, )
module PWM_v3_30_5 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 16;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v3_30 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 16;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 0;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: B_Counter_v3_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Counter_v3_0\B_Counter_v3_0.v"
`endif

// Counter_v3_0(CaptureMode=0, CaptureModeSoftware=0, ClockMode=1, CompareMode=0, CompareModeSoftware=0, CompareStatusEdgeSense=true, CompareValue=128, CONTROL3=0, ControlRegRemoved=0, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InitCounterValue=128, InterruptOnCapture=false, InterruptOnCompare=false, InterruptOnOverUnderFlow=false, InterruptOnTC=false, Period=128, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, ReloadOnCapture=false, ReloadOnCompare=false, ReloadOnOverUnder=true, ReloadOnReset=true, Resolution=8, RunMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=true, UseInterrupt=true, VerilogSectionReplacementString=sC8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Counter_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MultiJog:Cnt8, CY_INSTANCE_SHORT_NAME=Cnt8, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=MultiJog_Cnt8, )
module Counter_v3_0_6 (
    reset,
    tc,
    comp,
    clock,
    interrupt,
    enable,
    capture,
    upCnt,
    downCnt,
    up_ndown,
    count);
    input       reset;
    output      tc;
    output      comp;
    input       clock;
    output      interrupt;
    input       enable;
    input       capture;
    input       upCnt;
    input       downCnt;
    input       up_ndown;
    input       count;

    parameter CaptureMode = 0;
    parameter ClockMode = 1;
    parameter CompareMode = 0;
    parameter CompareStatusEdgeSense = 1;
    parameter EnableMode = 0;
    parameter ReloadOnCapture = 0;
    parameter ReloadOnCompare = 0;
    parameter ReloadOnOverUnder = 1;
    parameter ReloadOnReset = 1;
    parameter Resolution = 8;
    parameter RunMode = 0;
    parameter UseInterrupt = 1;

          wire  Net_47;
          wire  Net_102;
          wire  Net_95;
          wire  Net_82;
          wire  Net_91;
          wire  Net_89;
          wire  Net_49;
          wire  Net_48;
          wire  Net_42;
          wire  Net_43;

	// int_vm (cy_virtualmux_v1_0)
	assign interrupt = Net_43;

	// TC_vm (cy_virtualmux_v1_0)
	assign tc = Net_49;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_82));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_89 = up_ndown;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_95));

	// vmEnableMode (cy_virtualmux_v1_0)
	assign Net_91 = enable;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

    B_Counter_v3_0 CounterUDB (
        .reset(reset),
        .tc_out(Net_49),
        .cmp_out(comp),
        .clock(clock),
        .irq_out(Net_43),
        .up_ndown(Net_89),
        .upcnt(upCnt),
        .dwncnt(downCnt),
        .enable(enable),
        .capture(capture),
        .count(count));
    defparam CounterUDB.CaptureMode = 0;
    defparam CounterUDB.ClockMode = 1;
    defparam CounterUDB.CompareMode = 0;
    defparam CounterUDB.CompareStatusEdgeSense = 1;
    defparam CounterUDB.EnableMode = 0;
    defparam CounterUDB.ReloadOnCapture = 0;
    defparam CounterUDB.ReloadOnCompare = 0;
    defparam CounterUDB.ReloadOnOverUnder = 1;
    defparam CounterUDB.ReloadOnReset = 1;
    defparam CounterUDB.Resolution = 8;
    defparam CounterUDB.RunMode = 0;
    defparam CounterUDB.UseInterrupt = 1;



endmodule

// Component: bQuadDec_v3_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v3_0\bQuadDec_v3_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v3_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\bQuadDec_v3_0\bQuadDec_v3_0.v"
`endif

// Component: not_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\not_v1_0\not_v1_0.v"
`endif

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// QuadDec_v3_0(Counter8bit=true, CounterResolution=1, CounterSize=8, CounterSizeReplacementString=int8, CounterSizeReplacementStringUnsigned=uint8, TypeCastReplacementString=int16, UsingGlitchFiltering=true, UsingIndexInput=false, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=QuadDec_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MultiJog, CY_INSTANCE_SHORT_NAME=MultiJog, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=MultiJog, )
module QuadDec_v3_0_7 (
    quad_A,
    quad_B,
    index,
    clock,
    interrupt);
    input       quad_A;
    input       quad_B;
    input       index;
    input       clock;
    output      interrupt;

    parameter CounterResolution = 1;
    parameter UsingGlitchFiltering = 1;
    parameter UsingIndexInput = 0;

          wire  Net_1126;
          wire  Net_1125;
          wire  Net_1124;
          wire  Net_1241;
          wire  Net_1123;
          wire  Net_1132;
          wire  Net_1131;
          wire  Net_1130;
          wire  Net_1243;
          wire  Net_1129;
          wire  Net_1287;
          wire  Net_1272;
          wire  Net_1290;
          wire  Net_1269;
          wire  Net_1264;
          wire  Net_1275;
          wire  Net_1276;
          wire  Net_1203;
          wire  Net_1260;
          wire  Net_1232;
          wire  Net_1229;
          wire  Net_1251;
          wire  Net_611;
          wire  Net_1151;
          wire  Net_1248;
          wire  Net_530;

    Counter_v3_0_6 Cnt8 (
        .reset(Net_1260),
        .tc(Net_1276),
        .comp(Net_1269),
        .clock(clock),
        .interrupt(Net_1123),
        .enable(1'b0),
        .capture(1'b0),
        .upCnt(1'b0),
        .downCnt(1'b0),
        .up_ndown(Net_1251),
        .count(Net_1203));
    defparam Cnt8.CaptureMode = 0;
    defparam Cnt8.ClockMode = 1;
    defparam Cnt8.CompareMode = 0;
    defparam Cnt8.CompareStatusEdgeSense = 1;
    defparam Cnt8.EnableMode = 0;
    defparam Cnt8.ReloadOnCapture = 0;
    defparam Cnt8.ReloadOnCompare = 0;
    defparam Cnt8.ReloadOnOverUnder = 1;
    defparam Cnt8.ReloadOnReset = 1;
    defparam Cnt8.Resolution = 8;
    defparam Cnt8.RunMode = 0;
    defparam Cnt8.UseInterrupt = 1;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign Net_1290 = Net_1276;

    bQuadDec_v3_0 bQuadDec (
        .quad_A(quad_A),
        .quad_B(quad_B),
        .index(Net_1232),
        .clock(clock),
        .dir(Net_1251),
        .reset(Net_1260),
        .enable(Net_1203),
        .overflow(Net_530),
        .underflow(Net_611),
        .interrupt(interrupt));
    defparam bQuadDec.CounterResolution = 1;
    defparam bQuadDec.UsingGlitchFiltering = 1;
    defparam bQuadDec.UsingIndexInput = 0;


    assign Net_1151 = ~Net_1251;


    assign Net_530 = Net_1248 & Net_1251;


    assign Net_611 = Net_1248 & Net_1151;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1232 = Net_1229;

    OneTerminal OneTerminal_1 (
        .o(Net_1229));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign Net_1272 = Net_1269;


    assign Net_1287 = ~Net_1272;


    assign Net_1248 = Net_1287 & Net_1290;



endmodule

// Component: CyStatusReg_v1_90
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyStatusReg_v1_90\CyStatusReg_v1_90.v"
`endif

// PWM_v3_30(CaptureMode=0, Clock_CheckTolerance=true, Clock_desired_freq=12, Clock_desired_freq_unit=6, Clock_divisor=1, Clock_FractDividerDenominator=0, Clock_FractDividerNumerator=0, Clock_FractDividerUsed=false, Clock_is_direct=false, Clock_is_divider=false, Clock_is_freq=true, Clock_minus_tolerance=5, Clock_ph_align_clock_id=, Clock_ph_align_clock_name=, Clock_plus_tolerance=5, Clock_source_clock_id=, Clock_source_clock_name=, Compare1_16=false, Compare1_8=true, Compare2_16=false, Compare2_8=false, CompareStatusEdgeSense=true, CompareType1=1, CompareType1Software=0, CompareType2=1, CompareType2Software=0, CompareValue1=127, CompareValue2=63, CONTROL3=0, ControlReg=true, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeadBand=0, DeadBand2_4=0, DeadBand256=0, DeadBandUsed=0, DeadTime=1, DitherOffset=0, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, InterruptOnCMP1=false, InterruptOnCMP2=false, InterruptOnKill=false, InterruptOnTC=false, IntOnCMP1=0, IntOnCMP2=0, IntOnKill=0, IntOnTC=0, KillMode=0, KillModeMinTime=0, MinimumKillTime=1, OneCompare=true, Period=255, PWMMode=0, PWMModeCenterAligned=0, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=sSTSReg_rstSts, RunMode=0, Status=true, TermMode_capture=0, TermMode_clock=0, TermMode_cmp_sel=0, TermMode_enable=0, TermMode_interrupt=0, TermMode_kill=0, TermMode_ph1=0, TermMode_ph2=0, TermMode_pwm=0, TermMode_pwm1=0, TermMode_pwm2=0, TermMode_reset=0, TermMode_tc=0, TermMode_trigger=0, TermVisibility_capture=false, TermVisibility_clock=true, TermVisibility_cmp_sel=false, TermVisibility_enable=false, TermVisibility_interrupt=true, TermVisibility_kill=false, TermVisibility_ph1=false, TermVisibility_ph2=false, TermVisibility_pwm=true, TermVisibility_pwm1=false, TermVisibility_pwm2=false, TermVisibility_reset=true, TermVisibility_tc=true, TermVisibility_trigger=false, TriggerMode=0, UDB16=false, UDB8=true, UseControl=true, UseInterrupt=true, UseStatus=true, VerilogSectionReplacementString=sP8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=PWM_v3_30, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=FanCtrl, CY_INSTANCE_SHORT_NAME=FanCtrl, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=30, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=FanCtrl, )
module PWM_v3_30_8 (
    reset,
    clock,
    tc,
    pwm1,
    pwm2,
    interrupt,
    capture,
    kill,
    enable,
    trigger,
    cmp_sel,
    pwm,
    ph1,
    ph2);
    input       reset;
    input       clock;
    output      tc;
    output      pwm1;
    output      pwm2;
    output      interrupt;
    input       capture;
    input       kill;
    input       enable;
    input       trigger;
    input       cmp_sel;
    output      pwm;
    output      ph1;
    output      ph2;

    parameter Resolution = 8;

          wire  Net_114;
          wire  Net_113;
          wire  Net_107;
          wire  Net_96;
          wire  Net_55;
          wire  Net_57;
          wire  Net_101;
          wire  Net_54;
          wire  Net_63;

    B_PWM_v3_30 PWMUDB (
        .reset(reset),
        .clock(clock),
        .tc(Net_101),
        .pwm1(pwm1),
        .pwm2(pwm2),
        .interrupt(Net_55),
        .kill(kill),
        .capture(capture),
        .enable(enable),
        .cmp_sel(cmp_sel),
        .trigger(trigger),
        .pwm(Net_96),
        .ph1(ph1),
        .ph2(ph2));
    defparam PWMUDB.CaptureMode = 0;
    defparam PWMUDB.CompareStatusEdgeSense = 1;
    defparam PWMUDB.CompareType1 = 1;
    defparam PWMUDB.CompareType2 = 1;
    defparam PWMUDB.DeadBand = 0;
    defparam PWMUDB.DitherOffset = 0;
    defparam PWMUDB.EnableMode = 0;
    defparam PWMUDB.KillMode = 0;
    defparam PWMUDB.PWMMode = 0;
    defparam PWMUDB.Resolution = 8;
    defparam PWMUDB.RunMode = 0;
    defparam PWMUDB.TriggerMode = 0;
    defparam PWMUDB.UseStatus = 1;

	// vmCompare (cy_virtualmux_v1_0)
	assign pwm = Net_96;

	// vmIRQ (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// vmTC (cy_virtualmux_v1_0)
	assign tc = Net_101;

    OneTerminal OneTerminal_1 (
        .o(Net_113));

	// FFKillMux (cy_virtualmux_v1_0)
	assign Net_107 = Net_114;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_114));



endmodule

// Component: PulseConvert_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0\PulseConvert_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\PulseConvert_v1_0\PulseConvert_v1_0.v"
`endif

// Component: cy_srff_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_srff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_srff_v1_0\cy_srff_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_srff_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_srff_v1_0\cy_srff_v1_0.v"
`endif

// Timer_v2_70(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeviceFamily=PSoC5, EnableMode=0, FF16=true, FF8=false, FixedFunction=true, FixedFunctionUsed=1, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=false, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=0, NumberOfCaptures=1, param45=1, Period=1999, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=rstSts, RunMode=0, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=0, VerilogSectionReplacementString=sT16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Timer_v2_70, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MultiJog_Timer, CY_INSTANCE_SHORT_NAME=MultiJog_Timer, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=MultiJog_Timer, )
module Timer_v2_70_9 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 0;
    parameter Resolution = 16;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    cy_psoc3_timer_v1_0 TimerHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_266),
        .kill(Net_260),
        .clock(clock),
        .tc(Net_51),
        .compare(Net_261),
        .interrupt(Net_57));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_57;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_51;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// Component: B_Timer_v2_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70\B_Timer_v2_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70\B_Timer_v2_70.v"
`endif

// Timer_v2_70(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeviceFamily=PSoC5, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=false, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=0, NumberOfCaptures=1, param45=1, Period=39, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=rstSts, RunMode=1, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=true, UDBControlReg=true, UsesHWEnable=0, VerilogSectionReplacementString=sT8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Timer_v2_70, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=MultiJog_FreqMeter, CY_INSTANCE_SHORT_NAME=MultiJog_FreqMeter, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0 Update 1, INSTANCE_NAME=MultiJog_FreqMeter, )
module Timer_v2_70_10 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 0;
    parameter Resolution = 8;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_53;

    B_Timer_v2_70 TimerUDB (
        .reset(reset),
        .interrupt(Net_55),
        .enable(enable),
        .trigger(trigger),
        .capture_in(capture),
        .capture_out(capture_out),
        .tc(Net_53),
        .clock(clock));
    defparam TimerUDB.Capture_Count = 2;
    defparam TimerUDB.CaptureCounterEnabled = 0;
    defparam TimerUDB.CaptureMode = 0;
    defparam TimerUDB.EnableMode = 0;
    defparam TimerUDB.InterruptOnCapture = 0;
    defparam TimerUDB.Resolution = 8;
    defparam TimerUDB.RunMode = 1;
    defparam TimerUDB.TriggerMode = 0;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// top
module top ;

    electrical  VoltChB;
          wire  Net_13761;
          wire  Net_13042;
          wire  Net_13041;
          wire  Net_13040;
          wire  Net_13039;
          wire  Net_13038;
          wire  Net_13733;
          wire  Net_11747;
          wire  Net_11746;
          wire  Net_11745;
          wire  Net_11744;
          wire  Net_11743;
          wire [7:0] Net_13055;
          wire  Net_13054;
    electrical  NegVoltChA;
          wire  Net_13053;
          wire  Net_13052;
          wire  Net_13051;
          wire  Net_13137;
          wire  Net_13401;
          wire  Net_13710;
          wire  Net_12791;
          wire  Net_10693;
          wire  Net_10692;
          wire  Net_10712;
          wire  Net_10711;
          wire  Net_10710;
          wire  PwmChA;
          wire  Net_10717;
          wire  Net_10716;
          wire  Net_10715;
          wire  Net_10714;
    electrical  Net_10606;
    electrical  Net_10605;
    electrical  Net_10604;
    electrical  Net_10603;
    electrical  Net_10602;
    electrical  Net_10601;
    electrical  Net_10600;
    electrical  Net_10599;
    electrical  Net_10598;
    electrical  Net_10597;
    electrical  Net_10596;
    electrical  Net_10595;
    electrical  Net_10594;
    electrical  Net_10593;
    electrical  Net_10592;
    electrical  Net_10591;
    electrical  Net_10590;
    electrical  Net_10796;
    electrical  Net_10795;
    electrical  Net_10794;
    electrical  Net_10793;
    electrical  Net_10800;
    electrical  Net_10799;
    electrical  Net_10798;
    electrical  Net_10797;
          wire  Net_10556;
          wire  OnChA;
          wire  Net_10552;
          wire  Net_10551;
    electrical  PosCurChB;
          wire  Net_10549;
          wire  PwmChB;
          wire  OnChB;
    electrical  PosCurChA;
    electrical  NegCurChA;
    electrical  NegCurChB;
          wire  Net_10548;
          wire  Net_10547;
          wire  Net_10546;
          wire  Net_10545;
          wire  Net_10544;
          wire  Net_10543;
          wire  Net_10542;
          wire  Net_10541;
          wire  Net_10540;
          wire  Net_10539;
    electrical  Net_10523;
    electrical  Net_10522;
    electrical  Net_10521;
    electrical  Net_10520;
    electrical  Net_10519;
    electrical  Net_10518;
    electrical  Net_10517;
    electrical  Net_10516;
    electrical  Net_10515;
    electrical  Net_10514;
    electrical  Net_10513;
    electrical  Net_10512;
    electrical  PosVoltChA;
    electrical  Net_10511;
    electrical  Net_10510;
    electrical  Net_10509;
    electrical  Net_10508;
    electrical  Net_10507;
    electrical  Net_317;
    electrical  Net_10613;
    electrical  Net_10472;
    electrical  Net_10476;
    electrical  Net_10455;
    electrical  Net_10454;
    electrical  Net_10453;
    electrical  Net_10452;
    electrical  Net_10451;
    electrical  Net_10450;
    electrical  Net_10449;
    electrical  Net_10448;
    electrical  Net_10447;
    electrical  Net_10446;
    electrical  Net_10445;
    electrical  Net_10444;
    electrical  Net_10443;
    electrical  Net_10442;
    electrical  Net_10441;
    electrical  Net_10440;
    electrical  Net_10439;
    electrical  Net_10438;
    electrical  Net_10803;
    electrical  Net_10801;
          wire [7:0] Net_12104;
          wire  Net_12103;
          wire  Net_12102;
          wire  Net_12101;
          wire  Net_12100;
          wire  Net_12099;
          wire  Net_13693;
          wire  Net_12098;
    electrical  Net_10802;
          wire  Net_10812;
          wire  Net_10811;
          wire  Net_10862;
    electrical  Net_10289;
    electrical  Net_10288;
    electrical  Net_10287;
    electrical  Net_10199;
    electrical  Net_10200;
    electrical  Net_10296;
    electrical  Net_10284;
    electrical  Net_10283;
    electrical  Net_10282;
    electrical  Net_10281;
    electrical  Net_10280;
    electrical  Net_10279;
    electrical  Net_10278;
    electrical  Net_10277;
    electrical  Net_10276;
    electrical  Net_10275;
    electrical  Net_10274;
    electrical  Net_10273;
    electrical  Net_10272;
    electrical  Net_10271;
    electrical  Net_10270;
    electrical  Net_10269;
    electrical  Net_10268;
    electrical  Net_10267;
          wire  Net_10165;
          wire  Net_704;
    electrical  Net_10182;
    electrical  Net_10181;
    electrical  Net_10180;
    electrical  Net_10179;
    electrical  Net_10178;
    electrical  Net_10177;
    electrical  Net_10176;
    electrical  Net_10175;
    electrical  Net_10174;
    electrical  Net_10173;
    electrical  Net_10172;
    electrical  Net_10171;
    electrical  Net_10170;
    electrical  Net_10169;
    electrical  Net_10168;
    electrical  Net_10167;
    electrical  Net_10166;
    electrical  Net_10194;
    electrical  Net_10193;
          wire  Net_746;
          wire  Net_745;
          wire  Net_743;
          wire  Net_742;
          wire  Net_741;
          wire  Net_740;
          wire  Net_739;
          wire  Net_738;
          wire  Net_737;
          wire  Net_736;
          wire  Net_735;
          wire  Net_10164;
    electrical  Net_660;
    electrical  Net_659;
          wire  Net_769;
          wire  Net_768;
          wire  Net_767;
          wire  Net_766;
          wire  Net_765;
          wire  Net_764;
          wire  Net_10163;
          wire  Net_10162;
          wire  Net_10161;
          wire  Net_10160;
          wire  Net_10159;
          wire  Net_10158;
          wire  Net_10157;
          wire  Net_10156;
          wire  Net_10155;
          wire  Net_10154;
          wire  Net_10153;
    electrical  Net_591;
    electrical  Net_587;
          wire  Net_9072;
          wire  Net_9071;
          wire  Net_9070;
          wire  Net_9069;
          wire  Net_9068;
          wire  Net_9067;
          wire  Net_9065;
          wire  Net_9064;
          wire  Net_9063;
    electrical  Net_505;
    electrical  Net_2646;
    electrical  Net_440;
    electrical  Net_1410;
    electrical  Net_413;
    electrical  Net_246;
    electrical  Net_415;
          wire  Net_161;
    electrical  Net_160;
          wire  Net_159;
          wire  Net_158;
          wire  Net_157;
    electrical  Net_156;
          wire  Net_13;
          wire  Net_11;
          wire  Net_10;
          wire  Net_9;
    electrical  Net_12;
          wire  Net_521;
    electrical  Net_520;
          wire  Net_519;
          wire  Net_518;
          wire  Net_517;
    electrical  Net_516;
          wire  Net_13752;
          wire  Net_13755;
          wire  Net_13742;
          wire  Net_13715;
          wire  Net_13753;
          wire  Net_13661;
          wire  Net_12021;
          wire  Net_13740;
          wire  Net_12888;
          wire  Net_13698;
          wire  Net_13591;
          wire  Net_10728;
          wire  Net_10739;
          wire  Net_10736;
          wire  Net_10727;
          wire  Net_11179;
          wire  Net_11749;
          wire  Net_13744;
    electrical  Net_10746;
    electrical  Net_10576;
    electrical  Net_10575;
    electrical  Net_10434;
    electrical  Net_10431;
    electrical  Net_10423;
    electrical  Net_10365;
    electrical  Net_10425;
    electrical  Net_10426;
    electrical  Net_10357;
    electrical [7:0] Net_10724;
          wire  Net_10708;
    electrical  Net_10696;
    electrical  Net_2761;
    electrical  Net_10609;
    electrical  Net_10607;
    electrical  Net_10580;
    electrical  Net_10588;
    electrical  Net_10585;
    electrical  Net_10558;
    electrical  Net_10557;
          wire  Net_10524;
    electrical  Net_290;
    electrical  Net_10621;
    electrical  Net_10506;
    electrical  Net_412;
    electrical  Net_10495;
    electrical  Net_10266;
          wire  Net_10498;
    electrical  Net_923;
    electrical  Net_928;
    electrical  Net_14740;
    electrical  Net_925;
    electrical  Net_916;
    electrical  Net_10298;
    electrical  Net_336;
    electrical  Net_14686;
    electrical  Net_10285;
    electrical  Net_10196;
    electrical  Net_14565;
    electrical  Net_10201;
    electrical  Net_658;
    electrical  Net_10187;
    electrical  Net_10186;
    electrical  Net_7047;
    electrical  Net_10183;
    electrical  Net_10184;
    electrical  Net_666;
          wire  Net_174;
    electrical  Net_7494;
    electrical  Net_7493;
    electrical  Net_7492;
    electrical  Net_697;
    electrical  Net_251;
    electrical  Net_5456;
    electrical  Net_4459;
    electrical  Net_281;
    electrical  Net_4555;
    electrical  Net_4570;
    electrical  Net_4701;
    electrical  Net_283;
    electrical  Net_388;
    electrical  Net_14670;
    electrical  Net_14666;
    electrical  Net_14679;
    electrical  Net_14681;
    electrical  Net_2647;
    electrical  Net_506;
    electrical  Net_2396;
    electrical  Net_1911;
    electrical  Net_410;
    electrical  Net_411;
    electrical  Net_1237;
    electrical  Net_399;
    electrical  Net_402;
    electrical  Net_397;
          wire  Net_949;
          wire  Net_733;
          wire  Net_779;
          wire  Net_734;
          wire  Net_168;
    electrical  Net_14532;
    electrical  Net_654;
    electrical  Net_651;
    electrical  Net_590;
    electrical  Net_10695;
    electrical  Net_586;
    electrical  Net_608;
    electrical  Net_578;
    electrical  Net_582;
    electrical  Net_580;
    electrical  Net_579;
    electrical  Net_547;
    electrical  Net_548;
    electrical  Net_155;
    electrical  Net_392;
    electrical  Net_342;
    electrical  Net_340;
    electrical  Net_339;
    electrical  Net_414;
    electrical  Net_313;
    electrical  Net_311;
    electrical  Net_310;
    electrical  Net_309;
    electrical  Net_304;
    electrical  Net_294;
    electrical  Net_292;
    electrical  Net_297;
    electrical  Net_285;
    electrical  Net_284;
    electrical  Net_282;
    electrical  Net_418;
    electrical  Net_5372;
    electrical  Net_228;
    electrical  Net_510;
    electrical  Net_227;
    electrical  Net_8;
    electrical  Net_7;

    ADC_SAR_v3_0_0 ADC_VoltageChanelB (
        .vplus(VoltChB),
        .vminus(Net_516),
        .soc(1'b0),
        .eoc(Net_518),
        .aclk(1'b0),
        .vdac_ref(Net_520),
        .eos(Net_521));

	wire [0:0] tmpOE__AGND_net;
	wire [0:0] tmpFB_0__AGND_net;
	wire [0:0] tmpIO_0__AGND_net;
	wire [0:0] tmpINTERRUPT_0__AGND_net;
	electrical [0:0] tmpSIOVREF__AGND_net;

	cy_psoc3_pins_v1_10
		#(.id("c4e8b15c-12dd-4567-bf67-f0a37b5b4564"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		AGND
		 (.oe(tmpOE__AGND_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__AGND_net[0:0]}),
		  .analog({Net_12}),
		  .io({tmpIO_0__AGND_net[0:0]}),
		  .siovref(tmpSIOVREF__AGND_net),
		  .interrupt({tmpINTERRUPT_0__AGND_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__AGND_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ADC_DelSig_v3_20_1 ADC_Current (
        .vplus(Net_7),
        .vminus(Net_8),
        .soc(1'b1),
        .eoc(Net_10),
        .aclk(1'b0),
        .nVref(Net_12),
        .mi(1'b0));

    PGA_v2_0_2 PGA_1 (
        .Vin(PosVoltChA),
        .Vref(NegVoltChA),
        .Vout(Net_155));

    // -- AMuxHw AMuxHw_1 start -- ***
    
    // -- AMuxHw Decoder Start--
    
    reg [1:0] AMuxHw_1_Decoder_one_hot;
    reg [0:0] AMuxHw_1_Decoder_old_id;
    wire  AMuxHw_1_Decoder_is_active;
    wire  AMuxHw_1_Decoder_enable;
    
    assign AMuxHw_1_Decoder_enable = 1'b1;
    
    genvar AMuxHw_1_Decoder_i;
    
    assign AMuxHw_1_Decoder_is_active = (Net_174 == AMuxHw_1_Decoder_old_id) && AMuxHw_1_Decoder_enable;
    
    always @(posedge Net_168)
    begin
        AMuxHw_1_Decoder_old_id = Net_174;
    end
    
    generate
        for (AMuxHw_1_Decoder_i = 0; AMuxHw_1_Decoder_i < 2; AMuxHw_1_Decoder_i = AMuxHw_1_Decoder_i + 1 )
        begin : AMuxHw_1_OutBit
            always @(posedge Net_168)
            begin
                AMuxHw_1_Decoder_one_hot[AMuxHw_1_Decoder_i] <= (AMuxHw_1_Decoder_old_id == AMuxHw_1_Decoder_i) && AMuxHw_1_Decoder_is_active;
            end
        end
    endgenerate
    
    // -- AMuxHw Decoder End--
    
    // -- AMuxHw Primitive A --
    
    cy_psoc3_amux_v1_0 #(
        .muxin_width(2),
        .hw_control(1),
        .one_active(1),
        .init_mux_sel(2'h0),
        .api_type(2'b10))
        AMuxHw_1_CYAMUXSIDE_A(
        .muxin({
            NegCurChA,
            PosCurChA
            }),
        .hw_ctrl_en(AMuxHw_1_Decoder_one_hot[1:0]),
        .vout(Net_7)
        );
    
    
    // -- AMuxHw Primitive B --
    
    cy_psoc3_amux_v1_0 #(
        .muxin_width(2),
        .hw_control(1),
        .one_active(1),
        .init_mux_sel(2'h0),
        .api_type(2'b10))
        AMuxHw_1_CYAMUXSIDE_B(
        .muxin({
            NegCurChB,
            PosCurChB
            }),
        .hw_ctrl_en(AMuxHw_1_Decoder_one_hot[1:0]),
        .vout(Net_8)
        );
    
    // -- AMuxHw AMuxHw_1 end -- ***

    ADC_SAR_v3_0_3 ADC_VoltageChanelA (
        .vplus(Net_155),
        .vminus(Net_156),
        .soc(1'b0),
        .eoc(Net_158),
        .aclk(1'b0),
        .vdac_ref(Net_160),
        .eos(Net_161));

    cy_annotation_universal_v1_0 PWR_20 (
        .connect({
            Net_14681
        })
    );
    defparam PWR_20.comp_name = "Power_v1_0";
    defparam PWR_20.port_names = "T1";
    defparam PWR_20.width = 1;

    cy_annotation_universal_v1_0 C_1 (
        .connect({
            Net_5372,
            Net_228
        })
    );
    defparam C_1.comp_name = "Capacitor_v1_0";
    defparam C_1.port_names = "T1, T2";
    defparam C_1.width = 2;

    cy_annotation_universal_v1_0 C_2 (
        .connect({
            Net_5372,
            Net_228
        })
    );
    defparam C_2.comp_name = "Capacitor_v1_0";
    defparam C_2.port_names = "T1, T2";
    defparam C_2.width = 2;

    cy_annotation_universal_v1_0 C_8 (
        .connect({
            Net_5372,
            Net_228
        })
    );
    defparam C_8.comp_name = "Capacitor_v1_0";
    defparam C_8.port_names = "T1, T2";
    defparam C_8.width = 2;

    cy_annotation_universal_v1_0 PWR_1 (
        .connect({
            Net_5372
        })
    );
    defparam PWR_1.comp_name = "Power_v1_0";
    defparam PWR_1.port_names = "T1";
    defparam PWR_1.width = 1;

    cy_annotation_universal_v1_0 PWR_19 (
        .connect({
            Net_285
        })
    );
    defparam PWR_19.comp_name = "Power_v1_0";
    defparam PWR_19.port_names = "T1";
    defparam PWR_19.width = 1;

    cy_annotation_universal_v1_0 C_3 (
        .connect({
            Net_283,
            Net_285
        })
    );
    defparam C_3.comp_name = "Capacitor_v1_0";
    defparam C_3.port_names = "T1, T2";
    defparam C_3.width = 2;

    cy_annotation_universal_v1_0 C_4 (
        .connect({
            Net_283,
            Net_285
        })
    );
    defparam C_4.comp_name = "Capacitor_v1_0";
    defparam C_4.port_names = "T1, T2";
    defparam C_4.width = 2;

    cy_annotation_universal_v1_0 Q_1 (
        .connect({
            Net_5372,
            Net_5456,
            Net_227
        })
    );
    defparam Q_1.comp_name = "PFET_En_v1_0";
    defparam Q_1.port_names = "D, G, S";
    defparam Q_1.width = 3;

    cy_annotation_universal_v1_0 Q_4 (
        .connect({
            Net_10298,
            Net_415,
            Net_285
        })
    );
    defparam Q_4.comp_name = "NFET_En_v1_0";
    defparam Q_4.port_names = "D, G, S";
    defparam Q_4.width = 3;

    cy_annotation_universal_v1_0 D_1 (
        .connect({
            Net_228,
            Net_227
        })
    );
    defparam D_1.comp_name = "Schottky_v1_0";
    defparam D_1.port_names = "A, K";
    defparam D_1.width = 2;

    cy_annotation_universal_v1_0 L_1 (
        .connect({
            Net_227,
            Net_510
        })
    );
    defparam L_1.comp_name = "Inductor_v1_0";
    defparam L_1.port_names = "T1, T2";
    defparam L_1.width = 2;

    cy_annotation_universal_v1_0 D_2 (
        .connect({
            Net_228,
            Net_227
        })
    );
    defparam D_2.comp_name = "Schottky_v1_0";
    defparam D_2.port_names = "A, K";
    defparam D_2.width = 2;

    cy_annotation_universal_v1_0 C_5 (
        .connect({
            Net_510,
            Net_228
        })
    );
    defparam C_5.comp_name = "Capacitor_v1_0";
    defparam C_5.port_names = "T1, T2";
    defparam C_5.width = 2;

    cy_annotation_universal_v1_0 C_9 (
        .connect({
            Net_5372,
            Net_228
        })
    );
    defparam C_9.comp_name = "Capacitor_v1_0";
    defparam C_9.port_names = "T1, T2";
    defparam C_9.width = 2;

    cy_annotation_universal_v1_0 C_6 (
        .connect({
            Net_510,
            Net_228
        })
    );
    defparam C_6.comp_name = "Capacitor_v1_0";
    defparam C_6.port_names = "T1, T2";
    defparam C_6.width = 2;

    cy_annotation_universal_v1_0 C_7 (
        .connect({
            Net_510,
            Net_228
        })
    );
    defparam C_7.comp_name = "Capacitor_v1_0";
    defparam C_7.port_names = "T1, T2";
    defparam C_7.width = 2;

    cy_annotation_universal_v1_0 GND_7 (
        .connect({
            Net_228
        })
    );
    defparam GND_7.comp_name = "Gnd_v1_0";
    defparam GND_7.port_names = "T1";
    defparam GND_7.width = 1;

    cy_annotation_universal_v1_0 R_1 (
        .connect({
            Net_228,
            Net_418
        })
    );
    defparam R_1.comp_name = "Resistor_v1_0";
    defparam R_1.port_names = "T1, T2";
    defparam R_1.width = 2;

    cy_annotation_universal_v1_0 R_2 (
        .connect({
            Net_228,
            Net_418
        })
    );
    defparam R_2.comp_name = "Resistor_v1_0";
    defparam R_2.port_names = "T1, T2";
    defparam R_2.width = 2;

    cy_annotation_universal_v1_0 Q_2 (
        .connect({
            Net_1911,
            Net_246,
            Net_418
        })
    );
    defparam Q_2.comp_name = "NFET_En_v1_0";
    defparam Q_2.port_names = "D, G, S";
    defparam Q_2.width = 3;

    cy_annotation_universal_v1_0 R_3 (
        .connect({
            Net_2396,
            Net_246
        })
    );
    defparam R_3.comp_name = "Resistor_v1_0";
    defparam R_3.port_names = "T1, T2";
    defparam R_3.width = 2;

    cy_annotation_universal_v1_0 R_4 (
        .connect({
            Net_5456,
            Net_251
        })
    );
    defparam R_4.comp_name = "Resistor_v1_0";
    defparam R_4.port_names = "T1, T2";
    defparam R_4.width = 2;

	wire [0:0] tmpOE__O_OUT_POLARITY_net;
	wire [0:0] tmpFB_0__O_OUT_POLARITY_net;
	wire [0:0] tmpIO_0__O_OUT_POLARITY_net;
	wire [0:0] tmpINTERRUPT_0__O_OUT_POLARITY_net;
	electrical [0:0] tmpSIOVREF__O_OUT_POLARITY_net;

	cy_psoc3_pins_v1_10
		#(.id("62478934-1833-4365-9269-5f010bd33840"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_OUT_POLARITY
		 (.oe(tmpOE__O_OUT_POLARITY_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_OUT_POLARITY_net[0:0]}),
		  .io({tmpIO_0__O_OUT_POLARITY_net[0:0]}),
		  .siovref(tmpSIOVREF__O_OUT_POLARITY_net),
		  .interrupt({tmpINTERRUPT_0__O_OUT_POLARITY_net[0:0]}),
		  .annotation({Net_10201}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_OUT_POLARITY_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 Q_3 (
        .connect({
            Net_283,
            Net_281,
            Net_282
        })
    );
    defparam Q_3.comp_name = "PFET_En_v1_0";
    defparam Q_3.port_names = "D, G, S";
    defparam Q_3.width = 3;

    cy_annotation_universal_v1_0 L_2 (
        .connect({
            Net_282,
            Net_284
        })
    );
    defparam L_2.comp_name = "Inductor_v1_0";
    defparam L_2.port_names = "T1, T2";
    defparam L_2.width = 2;

    cy_annotation_universal_v1_0 D_3 (
        .connect({
            Net_285,
            Net_282
        })
    );
    defparam D_3.comp_name = "Schottky_v1_0";
    defparam D_3.port_names = "A, K";
    defparam D_3.width = 2;

    cy_annotation_universal_v1_0 D_4 (
        .connect({
            Net_285,
            Net_282
        })
    );
    defparam D_4.comp_name = "Schottky_v1_0";
    defparam D_4.port_names = "A, K";
    defparam D_4.width = 2;

    cy_annotation_universal_v1_0 C_10 (
        .connect({
            Net_284,
            Net_285
        })
    );
    defparam C_10.comp_name = "Capacitor_v1_0";
    defparam C_10.port_names = "T1, T2";
    defparam C_10.width = 2;

    cy_annotation_universal_v1_0 C_11 (
        .connect({
            Net_284,
            Net_285
        })
    );
    defparam C_11.comp_name = "Capacitor_v1_0";
    defparam C_11.port_names = "T1, T2";
    defparam C_11.width = 2;

    cy_annotation_universal_v1_0 C_12 (
        .connect({
            Net_284,
            Net_285
        })
    );
    defparam C_12.comp_name = "Capacitor_v1_0";
    defparam C_12.port_names = "T1, T2";
    defparam C_12.width = 2;

    cy_annotation_universal_v1_0 R_8 (
        .connect({
            Net_336,
            Net_415
        })
    );
    defparam R_8.comp_name = "Resistor_v1_0";
    defparam R_8.port_names = "T1, T2";
    defparam R_8.width = 2;

    cy_annotation_universal_v1_0 C_13 (
        .connect({
            Net_283,
            Net_285
        })
    );
    defparam C_13.comp_name = "Capacitor_v1_0";
    defparam C_13.port_names = "T1, T2";
    defparam C_13.width = 2;

    cy_annotation_universal_v1_0 C_14 (
        .connect({
            Net_283,
            Net_285
        })
    );
    defparam C_14.comp_name = "Capacitor_v1_0";
    defparam C_14.port_names = "T1, T2";
    defparam C_14.width = 2;

    cy_annotation_universal_v1_0 R_6 (
        .connect({
            Net_284,
            Net_418
        })
    );
    defparam R_6.comp_name = "Resistor_v1_0";
    defparam R_6.port_names = "T1, T2";
    defparam R_6.width = 2;

    cy_annotation_universal_v1_0 R_5 (
        .connect({
            Net_284,
            Net_418
        })
    );
    defparam R_5.comp_name = "Resistor_v1_0";
    defparam R_5.port_names = "T1, T2";
    defparam R_5.width = 2;

    cy_annotation_universal_v1_0 R_7 (
        .connect({
            Net_4459,
            Net_281
        })
    );
    defparam R_7.comp_name = "Resistor_v1_0";
    defparam R_7.port_names = "T1, T2";
    defparam R_7.width = 2;

    cy_annotation_universal_v1_0 U_1 (
        .connect({
            Net_292,
            Net_251
        })
    );
    defparam U_1.comp_name = "ExtBuffer_v1_0";
    defparam U_1.port_names = "Vin, Vout";
    defparam U_1.width = 2;

    cy_annotation_universal_v1_0 U_2 (
        .connect({
            Net_294,
            Net_2396
        })
    );
    defparam U_2.comp_name = "ExtBuffer_v1_0";
    defparam U_2.port_names = "Vin, Vout";
    defparam U_2.width = 2;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_304
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 PWR_2 (
        .connect({
            Net_297
        })
    );
    defparam PWR_2.comp_name = "Power_v1_0";
    defparam PWR_2.port_names = "T1";
    defparam PWR_2.width = 1;

	wire [0:0] tmpOE__O_PwmChA_net;
	wire [0:0] tmpFB_0__O_PwmChA_net;
	wire [0:0] tmpIO_0__O_PwmChA_net;
	wire [0:0] tmpINTERRUPT_0__O_PwmChA_net;
	electrical [0:0] tmpSIOVREF__O_PwmChA_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_PwmChA
		 (.oe(tmpOE__O_PwmChA_net),
		  .y({PwmChA}),
		  .fb({tmpFB_0__O_PwmChA_net[0:0]}),
		  .io({tmpIO_0__O_PwmChA_net[0:0]}),
		  .siovref(tmpSIOVREF__O_PwmChA_net),
		  .interrupt({tmpINTERRUPT_0__O_PwmChA_net[0:0]}),
		  .annotation({Net_292}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_PwmChA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__O_OnChA_net;
	wire [0:0] tmpFB_0__O_OnChA_net;
	wire [0:0] tmpIO_0__O_OnChA_net;
	wire [0:0] tmpINTERRUPT_0__O_OnChA_net;
	electrical [0:0] tmpSIOVREF__O_OnChA_net;

	cy_psoc3_pins_v1_10
		#(.id("8c479f88-b6dd-4c6f-887d-62a221637cf3"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_OnChA
		 (.oe(tmpOE__O_OnChA_net),
		  .y({OnChA}),
		  .fb({tmpFB_0__O_OnChA_net[0:0]}),
		  .io({tmpIO_0__O_OnChA_net[0:0]}),
		  .siovref(tmpSIOVREF__O_OnChA_net),
		  .interrupt({tmpINTERRUPT_0__O_OnChA_net[0:0]}),
		  .annotation({Net_294}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_OnChA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 U_3 (
        .connect({
            Net_4555,
            Net_4459
        })
    );
    defparam U_3.comp_name = "ExtBuffer_v1_0";
    defparam U_3.port_names = "Vin, Vout";
    defparam U_3.width = 2;

    cy_annotation_universal_v1_0 U_4 (
        .connect({
            Net_4570,
            Net_336
        })
    );
    defparam U_4.comp_name = "ExtBuffer_v1_0";
    defparam U_4.port_names = "Vin, Vout";
    defparam U_4.width = 2;

    cy_annotation_universal_v1_0 PWR_5 (
        .connect({
            Net_283
        })
    );
    defparam PWR_5.comp_name = "Power_v1_0";
    defparam PWR_5.port_names = "T1";
    defparam PWR_5.width = 1;

	wire [0:0] tmpOE__O_PwmChB_net;
	wire [0:0] tmpFB_0__O_PwmChB_net;
	wire [0:0] tmpIO_0__O_PwmChB_net;
	wire [0:0] tmpINTERRUPT_0__O_PwmChB_net;
	electrical [0:0] tmpSIOVREF__O_PwmChB_net;

	cy_psoc3_pins_v1_10
		#(.id("96f32218-8078-40a2-b48b-bec8d7063ffb"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_PwmChB
		 (.oe(tmpOE__O_PwmChB_net),
		  .y({PwmChB}),
		  .fb({tmpFB_0__O_PwmChB_net[0:0]}),
		  .io({tmpIO_0__O_PwmChB_net[0:0]}),
		  .siovref(tmpSIOVREF__O_PwmChB_net),
		  .interrupt({tmpINTERRUPT_0__O_PwmChB_net[0:0]}),
		  .annotation({Net_388}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_PwmChB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__O_OnChB_net;
	wire [0:0] tmpFB_0__O_OnChB_net;
	wire [0:0] tmpIO_0__O_OnChB_net;
	wire [0:0] tmpINTERRUPT_0__O_OnChB_net;
	electrical [0:0] tmpSIOVREF__O_OnChB_net;

	cy_psoc3_pins_v1_10
		#(.id("960e6fc0-4de7-4bf8-b5ec-ba393e72baff"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_OnChB
		 (.oe(tmpOE__O_OnChB_net),
		  .y({OnChB}),
		  .fb({tmpFB_0__O_OnChB_net[0:0]}),
		  .io({tmpIO_0__O_OnChB_net[0:0]}),
		  .siovref(tmpSIOVREF__O_OnChB_net),
		  .interrupt({tmpINTERRUPT_0__O_OnChB_net[0:0]}),
		  .annotation({Net_392}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_OnChB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_9 (
        .connect({
            Net_311,
            Net_228
        })
    );
    defparam R_9.comp_name = "Resistor_v1_0";
    defparam R_9.port_names = "T1, T2";
    defparam R_9.width = 2;

    cy_annotation_universal_v1_0 R_10 (
        .connect({
            Net_313,
            Net_418
        })
    );
    defparam R_10.comp_name = "Resistor_v1_0";
    defparam R_10.port_names = "T1, T2";
    defparam R_10.width = 2;

	wire [0:0] tmpOE__I_NegCurChA_net;
	wire [0:0] tmpFB_0__I_NegCurChA_net;
	wire [0:0] tmpIO_0__I_NegCurChA_net;
	wire [0:0] tmpINTERRUPT_0__I_NegCurChA_net;
	electrical [0:0] tmpSIOVREF__I_NegCurChA_net;

	cy_psoc3_pins_v1_10
		#(.id("f767a47a-a62e-4ed7-bead-6ad6952cb45f"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_NegCurChA
		 (.oe(tmpOE__I_NegCurChA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_NegCurChA_net[0:0]}),
		  .analog({NegCurChA}),
		  .io({tmpIO_0__I_NegCurChA_net[0:0]}),
		  .siovref(tmpSIOVREF__I_NegCurChA_net),
		  .interrupt({tmpINTERRUPT_0__I_NegCurChA_net[0:0]}),
		  .annotation({Net_311}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_NegCurChA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I_PosCurChA_net;
	wire [0:0] tmpFB_0__I_PosCurChA_net;
	wire [0:0] tmpIO_0__I_PosCurChA_net;
	wire [0:0] tmpINTERRUPT_0__I_PosCurChA_net;
	electrical [0:0] tmpSIOVREF__I_PosCurChA_net;

	cy_psoc3_pins_v1_10
		#(.id("c07606f0-c673-4eec-9845-4845bf1cad7a"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_PosCurChA
		 (.oe(tmpOE__I_PosCurChA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_PosCurChA_net[0:0]}),
		  .analog({PosCurChA}),
		  .io({tmpIO_0__I_PosCurChA_net[0:0]}),
		  .siovref(tmpSIOVREF__I_PosCurChA_net),
		  .interrupt({tmpINTERRUPT_0__I_PosCurChA_net[0:0]}),
		  .annotation({Net_313}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_PosCurChA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_11 (
        .connect({
            Net_10558,
            Net_284
        })
    );
    defparam R_11.comp_name = "Resistor_v1_0";
    defparam R_11.port_names = "T1, T2";
    defparam R_11.width = 2;

    cy_annotation_universal_v1_0 R_12 (
        .connect({
            Net_10557,
            Net_418
        })
    );
    defparam R_12.comp_name = "Resistor_v1_0";
    defparam R_12.port_names = "T1, T2";
    defparam R_12.width = 2;

	wire [0:0] tmpOE__I_NegCurChB_net;
	wire [0:0] tmpFB_0__I_NegCurChB_net;
	wire [0:0] tmpIO_0__I_NegCurChB_net;
	wire [0:0] tmpINTERRUPT_0__I_NegCurChB_net;
	electrical [0:0] tmpSIOVREF__I_NegCurChB_net;

	cy_psoc3_pins_v1_10
		#(.id("a4cfe173-aaba-47a1-b26a-a17dc2a9fb90"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_NegCurChB
		 (.oe(tmpOE__I_NegCurChB_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_NegCurChB_net[0:0]}),
		  .analog({NegCurChB}),
		  .io({tmpIO_0__I_NegCurChB_net[0:0]}),
		  .siovref(tmpSIOVREF__I_NegCurChB_net),
		  .interrupt({tmpINTERRUPT_0__I_NegCurChB_net[0:0]}),
		  .annotation({Net_10557}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_NegCurChB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__I_PosCurChB_net;
	wire [0:0] tmpFB_0__I_PosCurChB_net;
	wire [0:0] tmpIO_0__I_PosCurChB_net;
	wire [0:0] tmpINTERRUPT_0__I_PosCurChB_net;
	electrical [0:0] tmpSIOVREF__I_PosCurChB_net;

	cy_psoc3_pins_v1_10
		#(.id("16933cd3-07f1-4401-aada-624a61fc0d48"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_PosCurChB
		 (.oe(tmpOE__I_PosCurChB_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_PosCurChB_net[0:0]}),
		  .analog({PosCurChB}),
		  .io({tmpIO_0__I_PosCurChB_net[0:0]}),
		  .siovref(tmpSIOVREF__I_PosCurChB_net),
		  .interrupt({tmpINTERRUPT_0__I_PosCurChB_net[0:0]}),
		  .annotation({Net_10558}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_PosCurChB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 D_5 (
        .connect({
            Net_339,
            Net_340
        })
    );
    defparam D_5.comp_name = "LED_v1_0";
    defparam D_5.port_names = "A, K";
    defparam D_5.width = 2;

    cy_annotation_universal_v1_0 D_6 (
        .connect({
            Net_339,
            Net_342
        })
    );
    defparam D_6.comp_name = "LED_v1_0";
    defparam D_6.port_names = "A, K";
    defparam D_6.width = 2;

    cy_annotation_universal_v1_0 R_13 (
        .connect({
            Net_340,
            Net_388
        })
    );
    defparam R_13.comp_name = "Resistor_v1_0";
    defparam R_13.port_names = "T1, T2";
    defparam R_13.width = 2;

    cy_annotation_universal_v1_0 R_14 (
        .connect({
            Net_392,
            Net_342
        })
    );
    defparam R_14.comp_name = "Resistor_v1_0";
    defparam R_14.port_names = "T1, T2";
    defparam R_14.width = 2;

    cy_annotation_universal_v1_0 PWR_4 (
        .connect({
            Net_339
        })
    );
    defparam PWR_4.comp_name = "Power_v1_0";
    defparam PWR_4.port_names = "T1";
    defparam PWR_4.width = 1;

    cy_annotation_universal_v1_0 C_16 (
        .connect({
            Net_402,
            Net_399
        })
    );
    defparam C_16.comp_name = "Capacitor_v1_0";
    defparam C_16.port_names = "T1, T2";
    defparam C_16.width = 2;

    cy_annotation_universal_v1_0 C_15 (
        .connect({
            Net_397,
            Net_399
        })
    );
    defparam C_15.comp_name = "Capacitor_v1_0";
    defparam C_15.port_names = "T1, T2";
    defparam C_15.width = 2;

    cy_annotation_universal_v1_0 PWR_7 (
        .connect({
            Net_402
        })
    );
    defparam PWR_7.comp_name = "Power_v1_0";
    defparam PWR_7.port_names = "T1";
    defparam PWR_7.width = 1;

    cy_annotation_universal_v1_0 GND_3 (
        .connect({
            Net_285
        })
    );
    defparam GND_3.comp_name = "Gnd_v1_0";
    defparam GND_3.port_names = "T1";
    defparam GND_3.width = 1;

    cy_annotation_universal_v1_0 GND_2 (
        .connect({
            Net_399
        })
    );
    defparam GND_2.comp_name = "Gnd_v1_0";
    defparam GND_2.port_names = "T1";
    defparam GND_2.width = 1;

    cy_annotation_universal_v1_0 GND_4 (
        .connect({
            Net_309
        })
    );
    defparam GND_4.comp_name = "Gnd_v1_0";
    defparam GND_4.port_names = "T1";
    defparam GND_4.width = 1;

    cy_annotation_universal_v1_0 PWR_8 (
        .connect({
            Net_4701
        })
    );
    defparam PWR_8.comp_name = "Power_v1_0";
    defparam PWR_8.port_names = "T1";
    defparam PWR_8.width = 1;

    cy_annotation_universal_v1_0 PWR_6 (
        .connect({
            Net_397
        })
    );
    defparam PWR_6.comp_name = "Power_v1_0";
    defparam PWR_6.port_names = "T1";
    defparam PWR_6.width = 1;

    cy_annotation_universal_v1_0 U_5 (
        .connect({
            Net_399,
            Net_397,
            Net_402
        })
    );
    defparam U_5.comp_name = "VREG_v1_0";
    defparam U_5.port_names = "REF, VIN, VOUT";
    defparam U_5.width = 3;

    cy_annotation_universal_v1_0 U_6 (
        .connect({
            Net_411,
            Net_414,
            Net_410,
            Net_413,
            Net_412
        })
    );
    defparam U_6.comp_name = "ExtOpAmp_v1_0";
    defparam U_6.port_names = "N, O, P, VN, VP";
    defparam U_6.width = 5;

    cy_annotation_universal_v1_0 R_16 (
        .connect({
            Net_285,
            Net_411
        })
    );
    defparam R_16.comp_name = "Resistor_v1_0";
    defparam R_16.port_names = "T1, T2";
    defparam R_16.width = 2;

    cy_annotation_universal_v1_0 R_15 (
        .connect({
            Net_418,
            Net_410
        })
    );
    defparam R_15.comp_name = "Resistor_v1_0";
    defparam R_15.port_names = "T1, T2";
    defparam R_15.width = 2;

    cy_annotation_universal_v1_0 R_17 (
        .connect({
            Net_411,
            Net_414
        })
    );
    defparam R_17.comp_name = "Resistor_v1_0";
    defparam R_17.port_names = "T1, T2";
    defparam R_17.width = 2;

    cy_annotation_universal_v1_0 GND_5 (
        .connect({
            Net_1410
        })
    );
    defparam GND_5.comp_name = "Gnd_v1_0";
    defparam GND_5.port_names = "T1";
    defparam GND_5.width = 1;

    cy_annotation_universal_v1_0 R_18 (
        .connect({
            Net_410,
            Net_1410
        })
    );
    defparam R_18.comp_name = "Resistor_v1_0";
    defparam R_18.port_names = "T1, T2";
    defparam R_18.width = 2;

    cy_annotation_universal_v1_0 R_43 (
        .connect({
            Net_412,
            Net_10506
        })
    );
    defparam R_43.comp_name = "Resistor_v1_0";
    defparam R_43.port_names = "T1, T2";
    defparam R_43.width = 2;

    cy_annotation_universal_v1_0 GND_23 (
        .connect({
            Net_413
        })
    );
    defparam GND_23.comp_name = "Gnd_v1_0";
    defparam GND_23.port_names = "T1";
    defparam GND_23.width = 1;

    cy_annotation_universal_v1_0 R_19 (
        .connect({
            Net_1237,
            Net_414
        })
    );
    defparam R_19.comp_name = "Resistor_v1_0";
    defparam R_19.port_names = "T1, T2";
    defparam R_19.width = 2;

    cy_annotation_universal_v1_0 R_20 (
        .connect({
            Net_440,
            Net_1237
        })
    );
    defparam R_20.comp_name = "Resistor_v1_0";
    defparam R_20.port_names = "T1, T2";
    defparam R_20.width = 2;

    cy_annotation_universal_v1_0 GND_6 (
        .connect({
            Net_440
        })
    );
    defparam GND_6.comp_name = "Gnd_v1_0";
    defparam GND_6.port_names = "T1";
    defparam GND_6.width = 1;

	wire [0:0] tmpOE__I_VoltChB_net;
	wire [0:0] tmpFB_0__I_VoltChB_net;
	wire [0:0] tmpIO_0__I_VoltChB_net;
	wire [0:0] tmpINTERRUPT_0__I_VoltChB_net;
	electrical [0:0] tmpSIOVREF__I_VoltChB_net;

	cy_psoc3_pins_v1_10
		#(.id("25429233-d711-4cec-b6dc-13028ae3d6d7"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_VoltChB
		 (.oe(tmpOE__I_VoltChB_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_VoltChB_net[0:0]}),
		  .analog({VoltChB}),
		  .io({tmpIO_0__I_VoltChB_net[0:0]}),
		  .siovref(tmpSIOVREF__I_VoltChB_net),
		  .interrupt({tmpINTERRUPT_0__I_VoltChB_net[0:0]}),
		  .annotation({Net_1237}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_VoltChB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_21 (
        .connect({
            Net_510,
            Net_2647
        })
    );
    defparam R_21.comp_name = "Resistor_v1_0";
    defparam R_21.port_names = "T1, T2";
    defparam R_21.width = 2;

	wire [0:0] tmpOE__I_PosVoltChA_net;
	wire [0:0] tmpFB_0__I_PosVoltChA_net;
	wire [0:0] tmpIO_0__I_PosVoltChA_net;
	wire [0:0] tmpINTERRUPT_0__I_PosVoltChA_net;
	electrical [0:0] tmpSIOVREF__I_PosVoltChA_net;

	cy_psoc3_pins_v1_10
		#(.id("d53b06cd-8d42-4f10-b1e7-f6d886a2c2bb"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_PosVoltChA
		 (.oe(tmpOE__I_PosVoltChA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_PosVoltChA_net[0:0]}),
		  .analog({PosVoltChA}),
		  .io({tmpIO_0__I_PosVoltChA_net[0:0]}),
		  .siovref(tmpSIOVREF__I_PosVoltChA_net),
		  .interrupt({tmpINTERRUPT_0__I_PosVoltChA_net[0:0]}),
		  .annotation({Net_506}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_PosVoltChA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_23 (
        .connect({
            Net_2647,
            Net_2646
        })
    );
    defparam R_23.comp_name = "Resistor_v1_0";
    defparam R_23.port_names = "T1, T2";
    defparam R_23.width = 2;

    cy_annotation_universal_v1_0 GND_9 (
        .connect({
            Net_2646
        })
    );
    defparam GND_9.comp_name = "Gnd_v1_0";
    defparam GND_9.port_names = "T1";
    defparam GND_9.width = 1;

    cy_annotation_universal_v1_0 R_25 (
        .connect({
            Net_418,
            Net_506
        })
    );
    defparam R_25.comp_name = "Resistor_v1_0";
    defparam R_25.port_names = "T1, T2";
    defparam R_25.width = 2;

	wire [0:0] tmpOE__I_NegVoltChA_net;
	wire [0:0] tmpFB_0__I_NegVoltChA_net;
	wire [0:0] tmpIO_0__I_NegVoltChA_net;
	wire [0:0] tmpINTERRUPT_0__I_NegVoltChA_net;
	electrical [0:0] tmpSIOVREF__I_NegVoltChA_net;

	cy_psoc3_pins_v1_10
		#(.id("57dbffdf-2e0b-49a0-9f5d-9f2c5d9ff632"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_NegVoltChA
		 (.oe(tmpOE__I_NegVoltChA_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__I_NegVoltChA_net[0:0]}),
		  .analog({NegVoltChA}),
		  .io({tmpIO_0__I_NegVoltChA_net[0:0]}),
		  .siovref(tmpSIOVREF__I_NegVoltChA_net),
		  .interrupt({tmpINTERRUPT_0__I_NegVoltChA_net[0:0]}),
		  .annotation({Net_2647}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_NegVoltChA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GND_8 (
        .connect({
            Net_505
        })
    );
    defparam GND_8.comp_name = "Gnd_v1_0";
    defparam GND_8.port_names = "T1";
    defparam GND_8.width = 1;

    cy_annotation_universal_v1_0 R_26 (
        .connect({
            Net_506,
            Net_505
        })
    );
    defparam R_26.comp_name = "Resistor_v1_0";
    defparam R_26.port_names = "T1, T2";
    defparam R_26.width = 2;

    cy_annotation_universal_v1_0 R_22 (
        .connect({
            Net_547,
            Net_548
        })
    );
    defparam R_22.comp_name = "Resistor_v1_0";
    defparam R_22.port_names = "T1, T2";
    defparam R_22.width = 2;

    cy_annotation_universal_v1_0 GND_10 (
        .connect({
            Net_547
        })
    );
    defparam GND_10.comp_name = "Gnd_v1_0";
    defparam GND_10.port_names = "T1";
    defparam GND_10.width = 1;

    cy_annotation_universal_v1_0 PWR_11 (
        .connect({
            Net_580
        })
    );
    defparam PWR_11.comp_name = "Power_v1_0";
    defparam PWR_11.port_names = "T1";
    defparam PWR_11.width = 1;

    CyControlReg_v1_80 AdcCurrentChanel (
        .control_1(Net_9063),
        .control_2(Net_9064),
        .control_3(Net_9065),
        .control_0(Net_174),
        .control_4(Net_9067),
        .control_5(Net_9068),
        .control_6(Net_9069),
        .control_7(Net_9070),
        .clock(1'b0),
        .reset(1'b0));
    defparam AdcCurrentChanel.Bit0Mode = 0;
    defparam AdcCurrentChanel.Bit1Mode = 0;
    defparam AdcCurrentChanel.Bit2Mode = 0;
    defparam AdcCurrentChanel.Bit3Mode = 0;
    defparam AdcCurrentChanel.Bit4Mode = 0;
    defparam AdcCurrentChanel.Bit5Mode = 0;
    defparam AdcCurrentChanel.Bit6Mode = 0;
    defparam AdcCurrentChanel.Bit7Mode = 0;
    defparam AdcCurrentChanel.BitValue = 0;
    defparam AdcCurrentChanel.BusDisplay = 1;
    defparam AdcCurrentChanel.ExtrReset = 0;
    defparam AdcCurrentChanel.NumOutputs = 1;

    cy_annotation_universal_v1_0 D_7 (
        .connect({
            Net_579,
            Net_578
        })
    );
    defparam D_7.comp_name = "Diode_v1_0";
    defparam D_7.port_names = "A, K";
    defparam D_7.width = 2;

    cy_annotation_universal_v1_0 R_24 (
        .connect({
            Net_580,
            Net_579
        })
    );
    defparam R_24.comp_name = "Resistor_v1_0";
    defparam R_24.port_names = "T1, T2";
    defparam R_24.width = 2;

    cy_annotation_universal_v1_0 D_8 (
        .connect({
            Net_579,
            Net_582
        })
    );
    defparam D_8.comp_name = "Diode_v1_0";
    defparam D_8.port_names = "A, K";
    defparam D_8.width = 2;

    cy_annotation_universal_v1_0 R_27 (
        .connect({
            Net_587,
            Net_10695
        })
    );
    defparam R_27.comp_name = "Resistor_v1_0";
    defparam R_27.port_names = "T1, T2";
    defparam R_27.width = 2;

    cy_annotation_universal_v1_0 Q_5 (
        .connect({
            Net_651,
            Net_590,
            Net_591
        })
    );
    defparam Q_5.comp_name = "NPN_v1_0";
    defparam Q_5.port_names = "B, C, E";
    defparam Q_5.width = 3;

    cy_annotation_universal_v1_0 R_28 (
        .connect({
            Net_654,
            Net_651
        })
    );
    defparam R_28.comp_name = "Resistor_v1_0";
    defparam R_28.port_names = "T1, T2";
    defparam R_28.width = 2;

    cy_annotation_universal_v1_0 GND_11 (
        .connect({
            Net_591
        })
    );
    defparam GND_11.comp_name = "Gnd_v1_0";
    defparam GND_11.port_names = "T1";
    defparam GND_11.width = 1;

    cy_annotation_universal_v1_0 PWR_12 (
        .connect({
            Net_587
        })
    );
    defparam PWR_12.comp_name = "Power_v1_0";
    defparam PWR_12.port_names = "T1";
    defparam PWR_12.width = 1;

	wire [0:0] tmpOE__O_LCD_WR_net;
	wire [0:0] tmpFB_0__O_LCD_WR_net;
	wire [0:0] tmpIO_0__O_LCD_WR_net;
	wire [0:0] tmpINTERRUPT_0__O_LCD_WR_net;
	electrical [0:0] tmpSIOVREF__O_LCD_WR_net;

	cy_psoc3_pins_v1_10
		#(.id("83791a4a-92fc-42c2-a75f-a9487b4cf1cd"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_LCD_WR
		 (.oe(tmpOE__O_LCD_WR_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_LCD_WR_net[0:0]}),
		  .io({tmpIO_0__O_LCD_WR_net[0:0]}),
		  .siovref(tmpSIOVREF__O_LCD_WR_net),
		  .interrupt({tmpINTERRUPT_0__O_LCD_WR_net[0:0]}),
		  .annotation({Net_582}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_LCD_WR_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__O_LCD_RD_net;
	wire [0:0] tmpFB_0__O_LCD_RD_net;
	wire [0:0] tmpIO_0__O_LCD_RD_net;
	wire [0:0] tmpINTERRUPT_0__O_LCD_RD_net;
	electrical [0:0] tmpSIOVREF__O_LCD_RD_net;

	cy_psoc3_pins_v1_10
		#(.id("16481ea6-2029-4aad-8cb1-d5b330561715"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_LCD_RD
		 (.oe(tmpOE__O_LCD_RD_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_LCD_RD_net[0:0]}),
		  .io({tmpIO_0__O_LCD_RD_net[0:0]}),
		  .siovref(tmpSIOVREF__O_LCD_RD_net),
		  .interrupt({tmpINTERRUPT_0__O_LCD_RD_net[0:0]}),
		  .annotation({Net_578}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_LCD_RD_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__O_LCD_CD_net;
	wire [0:0] tmpFB_0__O_LCD_CD_net;
	wire [0:0] tmpIO_0__O_LCD_CD_net;
	wire [0:0] tmpINTERRUPT_0__O_LCD_CD_net;
	electrical [0:0] tmpSIOVREF__O_LCD_CD_net;

	cy_psoc3_pins_v1_10
		#(.id("077f9da7-9d68-4d3e-84cd-408709ee22cf"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_LCD_CD
		 (.oe(tmpOE__O_LCD_CD_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_LCD_CD_net[0:0]}),
		  .io({tmpIO_0__O_LCD_CD_net[0:0]}),
		  .siovref(tmpSIOVREF__O_LCD_CD_net),
		  .interrupt({tmpINTERRUPT_0__O_LCD_CD_net[0:0]}),
		  .annotation({Net_608}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_LCD_CD_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__O_LCD_RES_net;
	wire [0:0] tmpFB_0__O_LCD_RES_net;
	wire [0:0] tmpIO_0__O_LCD_RES_net;
	wire [0:0] tmpINTERRUPT_0__O_LCD_RES_net;
	electrical [0:0] tmpSIOVREF__O_LCD_RES_net;

	cy_psoc3_pins_v1_10
		#(.id("cbf8705d-2f20-4650-90d9-50be23addb49"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_LCD_RES
		 (.oe(tmpOE__O_LCD_RES_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_LCD_RES_net[0:0]}),
		  .io({tmpIO_0__O_LCD_RES_net[0:0]}),
		  .siovref(tmpSIOVREF__O_LCD_RES_net),
		  .interrupt({tmpINTERRUPT_0__O_LCD_RES_net[0:0]}),
		  .annotation({Net_586}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_LCD_RES_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [7:0] tmpOE__LCD_DB_net;
	wire [7:0] tmpFB_7__LCD_DB_net;
	wire [7:0] tmpIO_7__LCD_DB_net;
	wire [0:0] tmpINTERRUPT_0__LCD_DB_net;
	electrical [0:0] tmpSIOVREF__LCD_DB_net;

	cy_psoc3_pins_v1_10
		#(.id("264be2d3-9481-494b-8d9c-c1905a45e9cc"),
		  .drive_mode(24'b110_110_110_110_110_110_110_110),
		  .ibuf_enabled(8'b1_1_1_1_1_1_1_1),
		  .init_dr_st(8'b0_0_0_0_0_0_0_0),
		  .input_clk_en(0),
		  .input_sync(8'b0_0_0_0_0_0_0_0),
		  .input_sync_mode(8'b0_0_0_0_0_0_0_0),
		  .intr_mode(16'b00_00_00_00_00_00_00_00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(",,,,,,,"),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(8'b1_1_1_1_1_1_1_1),
		  .oe_reset(0),
		  .oe_sync(8'b0_0_0_0_0_0_0_0),
		  .output_clk_en(0),
		  .output_clock_mode(8'b0_0_0_0_0_0_0_0),
		  .output_conn(8'b0_0_0_0_0_0_0_0),
		  .output_mode(8'b0_0_0_0_0_0_0_0),
		  .output_reset(0),
		  .output_sync(8'b0_0_0_0_0_0_0_0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(",,,,,,,"),
		  .pin_mode("BBBBBBBB"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(8'b1_1_1_1_1_1_1_1),
		  .sio_ibuf(""),
		  .sio_info(16'b00_00_00_00_00_00_00_00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(8'b0_0_0_0_0_0_0_0),
		  .spanning(0),
		  .use_annotation(8'b1_1_1_1_1_1_1_1),
		  .vtrip(16'b00_00_00_00_00_00_00_00),
		  .width(8),
		  .ovt_hyst_trim(8'b0_0_0_0_0_0_0_0),
		  .ovt_needed(8'b0_0_0_0_0_0_0_0),
		  .ovt_slew_control(16'b00_00_00_00_00_00_00_00),
		  .input_buffer_sel(16'b00_00_00_00_00_00_00_00))
		LCD_DB
		 (.oe(tmpOE__LCD_DB_net),
		  .y({8'b0}),
		  .fb({tmpFB_7__LCD_DB_net[7:0]}),
		  .io({tmpIO_7__LCD_DB_net[7:0]}),
		  .siovref(tmpSIOVREF__LCD_DB_net),
		  .interrupt({tmpINTERRUPT_0__LCD_DB_net[0:0]}),
		  .annotation({Net_10724[7:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LCD_DB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_10708, Net_10708, Net_10708, Net_10708, Net_10708, Net_10708, Net_10708, Net_10708} : {Net_10708, Net_10708, Net_10708, Net_10708, Net_10708, Net_10708, Net_10708, Net_10708};

    cy_annotation_universal_v1_0 TP_2 (
        .connect({
            Net_10696
        })
    );
    defparam TP_2.comp_name = "TestPoint_v1_0";
    defparam TP_2.port_names = "T1";
    defparam TP_2.width = 1;

    cy_annotation_universal_v1_0 PWR_13 (
        .connect({
            Net_310
        })
    );
    defparam PWR_13.comp_name = "Power_v1_0";
    defparam PWR_13.port_names = "T1";
    defparam PWR_13.width = 1;

	wire [0:0] tmpOE__O_OUT_ON_net;
	wire [0:0] tmpFB_0__O_OUT_ON_net;
	wire [0:0] tmpIO_0__O_OUT_ON_net;
	wire [0:0] tmpINTERRUPT_0__O_OUT_ON_net;
	electrical [0:0] tmpSIOVREF__O_OUT_ON_net;

	cy_psoc3_pins_v1_10
		#(.id("05f78e28-f059-4c27-b1c7-4396f26f8b4a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_OUT_ON
		 (.oe(tmpOE__O_OUT_ON_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_OUT_ON_net[0:0]}),
		  .io({tmpIO_0__O_OUT_ON_net[0:0]}),
		  .siovref(tmpSIOVREF__O_OUT_ON_net),
		  .interrupt({tmpINTERRUPT_0__O_OUT_ON_net[0:0]}),
		  .annotation({Net_14532}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_OUT_ON_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__O_LCD_BKL_net;
	wire [0:0] tmpFB_0__O_LCD_BKL_net;
	wire [0:0] tmpIO_0__O_LCD_BKL_net;
	wire [0:0] tmpINTERRUPT_0__O_LCD_BKL_net;
	electrical [0:0] tmpSIOVREF__O_LCD_BKL_net;

	cy_psoc3_pins_v1_10
		#(.id("a070d718-8e8d-465b-99c7-e6b0fedd710a"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(3),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_LCD_BKL
		 (.oe(tmpOE__O_LCD_BKL_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__O_LCD_BKL_net[0:0]}),
		  .io({tmpIO_0__O_LCD_BKL_net[0:0]}),
		  .siovref(tmpSIOVREF__O_LCD_BKL_net),
		  .interrupt({tmpINTERRUPT_0__O_LCD_BKL_net[0:0]}),
		  .annotation({Net_654}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_LCD_BKL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PWM_v3_30_4 PWM_2 (
        .reset(Net_949),
        .clock(Net_779),
        .tc(Net_10153),
        .pwm1(Net_10154),
        .pwm2(Net_10155),
        .interrupt(Net_10156),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(PwmChB),
        .ph1(Net_10162),
        .ph2(Net_10163));
    defparam PWM_2.Resolution = 16;

    CyControlReg_v1_80 Control_Reg_1 (
        .control_1(OnChA),
        .control_2(OnChB),
        .control_3(Net_949),
        .control_0(Net_733),
        .control_4(Net_764),
        .control_5(Net_765),
        .control_6(Net_766),
        .control_7(Net_767),
        .clock(1'b0),
        .reset(1'b0));
    defparam Control_Reg_1.Bit0Mode = 0;
    defparam Control_Reg_1.Bit1Mode = 0;
    defparam Control_Reg_1.Bit2Mode = 0;
    defparam Control_Reg_1.Bit3Mode = 0;
    defparam Control_Reg_1.Bit4Mode = 0;
    defparam Control_Reg_1.Bit5Mode = 0;
    defparam Control_Reg_1.Bit6Mode = 0;
    defparam Control_Reg_1.Bit7Mode = 0;
    defparam Control_Reg_1.BitValue = 0;
    defparam Control_Reg_1.BusDisplay = 0;
    defparam Control_Reg_1.ExtrReset = 0;
    defparam Control_Reg_1.NumOutputs = 4;

    cy_annotation_universal_v1_0 Q_6 (
        .connect({
            Net_659,
            Net_14565,
            Net_660
        })
    );
    defparam Q_6.comp_name = "NPN_v1_0";
    defparam Q_6.port_names = "B, C, E";
    defparam Q_6.width = 3;

    cy_annotation_universal_v1_0 R_31 (
        .connect({
            Net_659,
            Net_14532
        })
    );
    defparam R_31.comp_name = "Resistor_v1_0";
    defparam R_31.port_names = "T1, T2";
    defparam R_31.width = 2;

    cy_annotation_universal_v1_0 GND_12 (
        .connect({
            Net_660
        })
    );
    defparam GND_12.comp_name = "Gnd_v1_0";
    defparam GND_12.port_names = "T1";
    defparam GND_12.width = 1;


	cy_clock_v1_0
		#(.id("edca56d4-cf2d-435c-bf62-4b277d2f3864"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_2
		 (.clock_out(Net_734));


    PWM_v3_30_5 PWM_1 (
        .reset(Net_733),
        .clock(Net_734),
        .tc(Net_735),
        .pwm1(Net_736),
        .pwm2(Net_737),
        .interrupt(Net_738),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(PwmChA),
        .ph1(Net_745),
        .ph2(Net_746));
    defparam PWM_1.Resolution = 16;

    cy_annotation_universal_v1_0 K_2 (
        .connect({
            Net_10187,
            Net_10186,
            Net_10194,
            Net_10193,
            Net_666,
            Net_697,
            Net_14565,
            Net_658
        })
    );
    defparam K_2.comp_name = "Relay_v1_0";
    defparam K_2.port_names = "C1, C2, NC1, NC2, NO1, NO2, T1, T2";
    defparam K_2.width = 8;

    cy_annotation_universal_v1_0 P_4 (
        .connect({
            Net_10183,
            Net_10172,
            Net_10173,
            Net_10174,
            Net_10175,
            Net_10176,
            Net_10177,
            Net_10178,
            Net_10179,
            Net_10180,
            Net_10181,
            Net_7047,
            Net_10182,
            Net_10184,
            Net_10166,
            Net_10167,
            Net_10168,
            Net_10169,
            Net_10170,
            Net_10171
        })
    );
    defparam P_4.comp_name = "Connector20_v1_0";
    defparam P_4.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_4.width = 20;


	cy_clock_v1_0
		#(.id("7729782a-ac4f-4182-aa29-e89f95b186d9"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_1
		 (.clock_out(Net_168));



	cy_clock_v1_0
		#(.id("4194a6ed-e566-4c57-baa7-dc9f85c270e7"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_3
		 (.clock_out(Net_779));


    cy_annotation_universal_v1_0 PWR_14 (
        .connect({
            Net_658
        })
    );
    defparam PWR_14.comp_name = "Power_v1_0";
    defparam PWR_14.port_names = "T1";
    defparam PWR_14.width = 1;

    cy_annotation_universal_v1_0 P_3 (
        .connect({
            Net_14686,
            Net_10274,
            Net_10275,
            Net_10276,
            Net_10277,
            Net_10278,
            Net_10279,
            Net_10280,
            Net_10281,
            Net_10282,
            Net_10283,
            Net_10495,
            Net_10284,
            Net_10267,
            Net_10268,
            Net_10269,
            Net_10270,
            Net_10271,
            Net_10272,
            Net_10273
        })
    );
    defparam P_3.comp_name = "Connector20_v1_0";
    defparam P_3.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_3.width = 20;

    cy_annotation_universal_v1_0 F_1 (
        .connect({
            Net_10266,
            Net_10296
        })
    );
    defparam F_1.comp_name = "Fuse_v1_0";
    defparam F_1.port_names = "T1, T2";
    defparam F_1.width = 2;

    cy_annotation_universal_v1_0 SW_9 (
        .connect({
            Net_10296,
            Net_14686
        })
    );
    defparam SW_9.comp_name = "SwitchSPST_v1_0";
    defparam SW_9.port_names = "T1, T2";
    defparam SW_9.width = 2;

    cy_annotation_universal_v1_0 C_17 (
        .connect({
            Net_14670,
            Net_14666
        })
    );
    defparam C_17.comp_name = "Capacitor_v1_0";
    defparam C_17.port_names = "T1, T2";
    defparam C_17.width = 2;

    cy_annotation_universal_v1_0 PWR_16 (
        .connect({
            Net_14666
        })
    );
    defparam PWR_16.comp_name = "Power_v1_0";
    defparam PWR_16.port_names = "T1";
    defparam PWR_16.width = 1;

    cy_annotation_universal_v1_0 PWR_15 (
        .connect({
            Net_14670
        })
    );
    defparam PWR_15.comp_name = "Power_v1_0";
    defparam PWR_15.port_names = "T1";
    defparam PWR_15.width = 1;

    cy_annotation_universal_v1_0 R_30 (
        .connect({
            Net_4701,
            Net_4570
        })
    );
    defparam R_30.comp_name = "Resistor_v1_0";
    defparam R_30.port_names = "T1, T2";
    defparam R_30.width = 2;

    cy_annotation_universal_v1_0 R_29 (
        .connect({
            Net_4701,
            Net_4555
        })
    );
    defparam R_29.comp_name = "Resistor_v1_0";
    defparam R_29.port_names = "T1, T2";
    defparam R_29.width = 2;

    cy_annotation_universal_v1_0 C_19 (
        .connect({
            Net_666,
            Net_7047
        })
    );
    defparam C_19.comp_name = "Capacitor_v1_0";
    defparam C_19.port_names = "T1, T2";
    defparam C_19.width = 2;

    cy_annotation_universal_v1_0 C_20 (
        .connect({
            Net_697,
            Net_7047
        })
    );
    defparam C_20.comp_name = "Capacitor_v1_0";
    defparam C_20.port_names = "T1, T2";
    defparam C_20.width = 2;

    cy_annotation_universal_v1_0 C_18 (
        .connect({
            Net_14681,
            Net_14679
        })
    );
    defparam C_18.comp_name = "Capacitor_v1_0";
    defparam C_18.port_names = "T1, T2";
    defparam C_18.width = 2;

    cy_annotation_universal_v1_0 PWR_18 (
        .connect({
            Net_228
        })
    );
    defparam PWR_18.comp_name = "Power_v1_0";
    defparam PWR_18.port_names = "T1";
    defparam PWR_18.width = 1;

    cy_annotation_universal_v1_0 PWR_21 (
        .connect({
            Net_14679
        })
    );
    defparam PWR_21.comp_name = "Power_v1_0";
    defparam PWR_21.port_names = "T1";
    defparam PWR_21.width = 1;

    cy_annotation_universal_v1_0 PWR_17 (
        .connect({
            Net_7492
        })
    );
    defparam PWR_17.comp_name = "Power_v1_0";
    defparam PWR_17.port_names = "T1";
    defparam PWR_17.width = 1;

    cy_annotation_universal_v1_0 U_7 (
        .connect({
            Net_7494,
            Net_7492,
            Net_7493
        })
    );
    defparam U_7.comp_name = "VREG_v1_0";
    defparam U_7.port_names = "REF, VIN, VOUT";
    defparam U_7.width = 3;

    cy_annotation_universal_v1_0 C_23 (
        .connect({
            Net_10183,
            Net_7047
        })
    );
    defparam C_23.comp_name = "Capacitor_v1_0";
    defparam C_23.port_names = "T1, T2";
    defparam C_23.width = 2;

    cy_annotation_universal_v1_0 C_24 (
        .connect({
            Net_10184,
            Net_7047
        })
    );
    defparam C_24.comp_name = "Capacitor_v1_0";
    defparam C_24.port_names = "T1, T2";
    defparam C_24.width = 2;

    cy_annotation_universal_v1_0 GND_14 (
        .connect({
            Net_7494
        })
    );
    defparam GND_14.comp_name = "Gnd_v1_0";
    defparam GND_14.port_names = "T1";
    defparam GND_14.width = 1;

    cy_annotation_universal_v1_0 PWR_22 (
        .connect({
            Net_7493
        })
    );
    defparam PWR_22.comp_name = "Power_v1_0";
    defparam PWR_22.port_names = "T1";
    defparam PWR_22.width = 1;

    cy_annotation_universal_v1_0 C_21 (
        .connect({
            Net_7492,
            Net_7494
        })
    );
    defparam C_21.comp_name = "Capacitor_v1_0";
    defparam C_21.port_names = "T1, T2";
    defparam C_21.width = 2;

    cy_annotation_universal_v1_0 C_22 (
        .connect({
            Net_7493,
            Net_7494
        })
    );
    defparam C_22.comp_name = "Capacitor_v1_0";
    defparam C_22.port_names = "T1, T2";
    defparam C_22.width = 2;

    cy_annotation_universal_v1_0 C_25 (
        .connect({
            Net_7493,
            Net_7494
        })
    );
    defparam C_25.comp_name = "Capacitor_v1_0";
    defparam C_25.port_names = "T1, T2";
    defparam C_25.width = 2;

    cy_annotation_universal_v1_0 C_26 (
        .connect({
            Net_7493,
            Net_7494
        })
    );
    defparam C_26.comp_name = "Capacitor_v1_0";
    defparam C_26.port_names = "T1, T2";
    defparam C_26.width = 2;

    cy_annotation_universal_v1_0 C_27 (
        .connect({
            Net_7493,
            Net_7494
        })
    );
    defparam C_27.comp_name = "Capacitor_v1_0";
    defparam C_27.port_names = "T1, T2";
    defparam C_27.width = 2;

    cy_annotation_universal_v1_0 C_28 (
        .connect({
            Net_7493,
            Net_7494
        })
    );
    defparam C_28.comp_name = "Capacitor_v1_0";
    defparam C_28.port_names = "T1, T2";
    defparam C_28.width = 2;

    cy_annotation_universal_v1_0 K_3 (
        .connect({
            Net_10183,
            Net_10184,
            Net_10187,
            Net_10186,
            Net_10186,
            Net_10187,
            Net_10196,
            Net_658
        })
    );
    defparam K_3.comp_name = "Relay_v1_0";
    defparam K_3.port_names = "C1, C2, NC1, NC2, NO1, NO2, T1, T2";
    defparam K_3.width = 8;

    cy_annotation_universal_v1_0 Q_7 (
        .connect({
            Net_10200,
            Net_10196,
            Net_10199
        })
    );
    defparam Q_7.comp_name = "NPN_v1_0";
    defparam Q_7.port_names = "B, C, E";
    defparam Q_7.width = 3;

    cy_annotation_universal_v1_0 R_32 (
        .connect({
            Net_10200,
            Net_10201
        })
    );
    defparam R_32.comp_name = "Resistor_v1_0";
    defparam R_32.port_names = "T1, T2";
    defparam R_32.width = 2;

    cy_annotation_universal_v1_0 GND_15 (
        .connect({
            Net_10199
        })
    );
    defparam GND_15.comp_name = "Gnd_v1_0";
    defparam GND_15.port_names = "T1";
    defparam GND_15.width = 1;

    cy_annotation_universal_v1_0 U_8 (
        .connect({
            Net_10285,
            Net_10289,
            Net_10285,
            Net_10288,
            Net_10287
        })
    );
    defparam U_8.comp_name = "ExtOpAmp_v1_0";
    defparam U_8.port_names = "N, O, P, VN, VP";
    defparam U_8.width = 5;

    cy_annotation_universal_v1_0 R_37 (
        .connect({
            Net_285,
            Net_10298
        })
    );
    defparam R_37.comp_name = "Resistor_v1_0";
    defparam R_37.port_names = "T1, T2";
    defparam R_37.width = 2;


	cy_clock_v1_0
		#(.id("5abab193-a23f-479f-a84f-c0cb6b6c3ca6"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("20000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_6
		 (.clock_out(Net_12021));


    QuadDec_v3_0_7 MultiJog (
        .quad_A(Net_13698),
        .quad_B(Net_11179),
        .index(1'b0),
        .clock(Net_12021),
        .interrupt(Net_10812));
    defparam MultiJog.CounterResolution = 1;
    defparam MultiJog.UsingGlitchFiltering = 1;
    defparam MultiJog.UsingIndexInput = 0;

	wire [0:0] tmpOE__I_MultiJogB_net;
	wire [0:0] tmpIO_0__I_MultiJogB_net;
	wire [0:0] tmpINTERRUPT_0__I_MultiJogB_net;
	electrical [0:0] tmpSIOVREF__I_MultiJogB_net;

	cy_psoc3_pins_v1_10
		#(.id("9f84a6b3-e495-46bc-81cf-d44925274f70"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_MultiJogB
		 (.oe(tmpOE__I_MultiJogB_net),
		  .y({1'b0}),
		  .fb({Net_11179}),
		  .io({tmpIO_0__I_MultiJogB_net[0:0]}),
		  .siovref(tmpSIOVREF__I_MultiJogB_net),
		  .interrupt({tmpINTERRUPT_0__I_MultiJogB_net[0:0]}),
		  .annotation({Net_10425}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_MultiJogB_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 D_12 (
        .connect({
            Net_10802,
            Net_10357
        })
    );
    defparam D_12.comp_name = "LED_v1_0";
    defparam D_12.port_names = "A, K";
    defparam D_12.width = 2;


	cy_clock_v1_0
		#(.id("9515cede-bc4c-4d33-9190-7eb2fa81fe4c"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_5
		 (.clock_out(Net_12098));


    cy_annotation_universal_v1_0 R_34 (
        .connect({
            Net_10802,
            Net_10575
        })
    );
    defparam R_34.comp_name = "Resistor_v1_0";
    defparam R_34.port_names = "T1, T2";
    defparam R_34.width = 2;

    CyStatusReg_v1_90 Buttons (
        .status_0(Net_10739),
        .status_1(Net_10736),
        .status_2(Net_10727),
        .status_3(Net_10728),
        .clock(Net_12098),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_12103),
        .status_bus(8'b0));
    defparam Buttons.Bit0Mode = 0;
    defparam Buttons.Bit1Mode = 0;
    defparam Buttons.Bit2Mode = 0;
    defparam Buttons.Bit3Mode = 0;
    defparam Buttons.Bit4Mode = 1;
    defparam Buttons.Bit5Mode = 1;
    defparam Buttons.Bit6Mode = 0;
    defparam Buttons.Bit7Mode = 0;
    defparam Buttons.BusDisplay = 0;
    defparam Buttons.Interrupt = 0;
    defparam Buttons.MaskValue = 0;
    defparam Buttons.NumInputs = 4;

    cy_annotation_universal_v1_0 D_11 (
        .connect({
            Net_10801,
            Net_10357
        })
    );
    defparam D_11.comp_name = "LED_v1_0";
    defparam D_11.port_names = "A, K";
    defparam D_11.width = 2;

	wire [0:0] tmpOE__O_Led_Polar_net;
	wire [0:0] tmpFB_0__O_Led_Polar_net;
	wire [0:0] tmpIO_0__O_Led_Polar_net;
	wire [0:0] tmpINTERRUPT_0__O_Led_Polar_net;
	electrical [0:0] tmpSIOVREF__O_Led_Polar_net;

	cy_psoc3_pins_v1_10
		#(.id("85a06cca-64b1-4fc2-9c88-11848c06c9de"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_Led_Polar
		 (.oe(tmpOE__O_Led_Polar_net),
		  .y({Net_13744}),
		  .fb({tmpFB_0__O_Led_Polar_net[0:0]}),
		  .io({tmpIO_0__O_Led_Polar_net[0:0]}),
		  .siovref(tmpSIOVREF__O_Led_Polar_net),
		  .interrupt({tmpINTERRUPT_0__O_Led_Polar_net[0:0]}),
		  .annotation({Net_10576}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_Led_Polar_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 D_13 (
        .connect({
            Net_10803,
            Net_10357
        })
    );
    defparam D_13.comp_name = "LED_v1_0";
    defparam D_13.port_names = "A, K";
    defparam D_13.width = 2;

	wire [0:0] tmpOE__O_Led_Error_net;
	wire [0:0] tmpFB_0__O_Led_Error_net;
	wire [0:0] tmpIO_0__O_Led_Error_net;
	wire [0:0] tmpINTERRUPT_0__O_Led_Error_net;
	electrical [0:0] tmpSIOVREF__O_Led_Error_net;

	cy_psoc3_pins_v1_10
		#(.id("2e17ee68-151c-48fd-a0e4-0e54129c9311"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_Led_Error
		 (.oe(tmpOE__O_Led_Error_net),
		  .y({Net_13742}),
		  .fb({tmpFB_0__O_Led_Error_net[0:0]}),
		  .io({tmpIO_0__O_Led_Error_net[0:0]}),
		  .siovref(tmpSIOVREF__O_Led_Error_net),
		  .interrupt({tmpINTERRUPT_0__O_Led_Error_net[0:0]}),
		  .annotation({Net_10746}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_Led_Error_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 R_33 (
        .connect({
            Net_10801,
            Net_10746
        })
    );
    defparam R_33.comp_name = "Resistor_v1_0";
    defparam R_33.port_names = "T1, T2";
    defparam R_33.width = 2;

    cy_annotation_universal_v1_0 R_35 (
        .connect({
            Net_10803,
            Net_10576
        })
    );
    defparam R_35.comp_name = "Resistor_v1_0";
    defparam R_35.port_names = "T1, T2";
    defparam R_35.width = 2;

	wire [0:0] tmpOE__O_Led_RiseRatePowerUp_net;
	wire [0:0] tmpFB_0__O_Led_RiseRatePowerUp_net;
	wire [0:0] tmpIO_0__O_Led_RiseRatePowerUp_net;
	wire [0:0] tmpINTERRUPT_0__O_Led_RiseRatePowerUp_net;
	electrical [0:0] tmpSIOVREF__O_Led_RiseRatePowerUp_net;

	cy_psoc3_pins_v1_10
		#(.id("5d571a5c-28da-4d3e-b644-98a38b81e072"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		O_Led_RiseRatePowerUp
		 (.oe(tmpOE__O_Led_RiseRatePowerUp_net),
		  .y({Net_13661}),
		  .fb({tmpFB_0__O_Led_RiseRatePowerUp_net[0:0]}),
		  .io({tmpIO_0__O_Led_RiseRatePowerUp_net[0:0]}),
		  .siovref(tmpSIOVREF__O_Led_RiseRatePowerUp_net),
		  .interrupt({tmpINTERRUPT_0__O_Led_RiseRatePowerUp_net[0:0]}),
		  .annotation({Net_10575}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__O_Led_RiseRatePowerUp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__MouseClk_net;
	wire [0:0] tmpFB_0__MouseClk_net;
	wire [0:0] tmpIO_0__MouseClk_net;
	electrical [0:0] tmpSIOVREF__MouseClk_net;

	cy_psoc3_pins_v1_10
		#(.id("44906eef-7414-4079-8114-eb0c25d01ec7"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b10),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MouseClk
		 (.oe(tmpOE__MouseClk_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__MouseClk_net[0:0]}),
		  .io({tmpIO_0__MouseClk_net[0:0]}),
		  .siovref(tmpSIOVREF__MouseClk_net),
		  .interrupt({Net_10498}),
		  .annotation({Net_925}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MouseClk_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 P1 (
        .connect({
            Net_923,
            Net_10445,
            Net_10446,
            Net_10447,
            Net_10448,
            Net_10449,
            Net_10450,
            Net_10451,
            Net_10452,
            Net_10453,
            Net_10454,
            Net_10438,
            Net_10455,
            Net_10439,
            Net_10440,
            Net_928,
            Net_10441,
            Net_10442,
            Net_10443,
            Net_10444
        })
    );
    defparam P1.comp_name = "Connector20_v1_0";
    defparam P1.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P1.width = 20;

	wire [0:0] tmpOE__MouseData_net;
	wire [0:0] tmpFB_0__MouseData_net;
	wire [0:0] tmpIO_0__MouseData_net;
	wire [0:0] tmpINTERRUPT_0__MouseData_net;
	electrical [0:0] tmpSIOVREF__MouseData_net;

	cy_psoc3_pins_v1_10
		#(.id("4a70367c-d65b-4b20-9eca-2d1b35eceea8"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		MouseData
		 (.oe(tmpOE__MouseData_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__MouseData_net[0:0]}),
		  .io({tmpIO_0__MouseData_net[0:0]}),
		  .siovref(tmpSIOVREF__MouseData_net),
		  .interrupt({tmpINTERRUPT_0__MouseData_net[0:0]}),
		  .annotation({Net_916}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__MouseData_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GND_19 (
        .connect({
            Net_10439
        })
    );
    defparam GND_19.comp_name = "Gnd_v1_0";
    defparam GND_19.port_names = "T1";
    defparam GND_19.width = 1;

    cy_annotation_universal_v1_0 PWR_25 (
        .connect({
            Net_10440
        })
    );
    defparam PWR_25.comp_name = "Power_v1_0";
    defparam PWR_25.port_names = "T1";
    defparam PWR_25.width = 1;

    cy_annotation_universal_v1_0 R_38 (
        .connect({
            Net_923,
            Net_916
        })
    );
    defparam R_38.comp_name = "Resistor_v1_0";
    defparam R_38.port_names = "T1, T2";
    defparam R_38.width = 2;

    cy_annotation_universal_v1_0 R_39 (
        .connect({
            Net_928,
            Net_925
        })
    );
    defparam R_39.comp_name = "Resistor_v1_0";
    defparam R_39.port_names = "T1, T2";
    defparam R_39.width = 2;

    cy_annotation_universal_v1_0 D_9 (
        .connect({
            Net_14740,
            Net_916
        })
    );
    defparam D_9.comp_name = "Zener_v1_0";
    defparam D_9.port_names = "A, K";
    defparam D_9.width = 2;

    cy_annotation_universal_v1_0 D_10 (
        .connect({
            Net_14740,
            Net_925
        })
    );
    defparam D_10.comp_name = "Zener_v1_0";
    defparam D_10.port_names = "A, K";
    defparam D_10.width = 2;

    cy_annotation_universal_v1_0 R_40 (
        .connect({
            Net_916,
            Net_10476
        })
    );
    defparam R_40.comp_name = "Resistor_v1_0";
    defparam R_40.port_names = "T1, T2";
    defparam R_40.width = 2;

    cy_annotation_universal_v1_0 PWR_26 (
        .connect({
            Net_10476
        })
    );
    defparam PWR_26.comp_name = "Power_v1_0";
    defparam PWR_26.port_names = "T1";
    defparam PWR_26.width = 1;

    cy_annotation_universal_v1_0 GND_21 (
        .connect({
            Net_14740
        })
    );
    defparam GND_21.comp_name = "Gnd_v1_0";
    defparam GND_21.port_names = "T1";
    defparam GND_21.width = 1;

    cy_annotation_universal_v1_0 R_41 (
        .connect({
            Net_925,
            Net_10472
        })
    );
    defparam R_41.comp_name = "Resistor_v1_0";
    defparam R_41.port_names = "T1, T2";
    defparam R_41.width = 2;

    cy_annotation_universal_v1_0 PWR_27 (
        .connect({
            Net_10472
        })
    );
    defparam PWR_27.comp_name = "Power_v1_0";
    defparam PWR_27.port_names = "T1";
    defparam PWR_27.width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		MouseISR
		 (.int_signal(Net_10498));


	wire [0:0] tmpOE__OneWire_net;
	wire [0:0] tmpFB_0__OneWire_net;
	wire [0:0] tmpIO_0__OneWire_net;
	wire [0:0] tmpINTERRUPT_0__OneWire_net;
	electrical [0:0] tmpSIOVREF__OneWire_net;

	cy_psoc3_pins_v1_10
		#(.id("1cd16c5b-3c8b-4dfc-962f-fd21697d79bf"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		OneWire
		 (.oe(tmpOE__OneWire_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__OneWire_net[0:0]}),
		  .io({tmpIO_0__OneWire_net[0:0]}),
		  .siovref(tmpSIOVREF__OneWire_net),
		  .interrupt({tmpINTERRUPT_0__OneWire_net[0:0]}),
		  .annotation({Net_290}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__OneWire_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 Vdd_2 (
        .connect({
            Net_10621
        })
    );
    defparam Vdd_2.comp_name = "Power_v1_0";
    defparam Vdd_2.port_names = "T1";
    defparam Vdd_2.width = 1;

    cy_annotation_universal_v1_0 GND_16 (
        .connect({
            Net_10613
        })
    );
    defparam GND_16.comp_name = "Gnd_v1_0";
    defparam GND_16.port_names = "T1";
    defparam GND_16.width = 1;

    cy_annotation_universal_v1_0 P_6 (
        .connect({
            Net_317,
            Net_10513,
            Net_10514,
            Net_10515,
            Net_10516,
            Net_10517,
            Net_10518,
            Net_10519,
            Net_10520,
            Net_10521,
            Net_10522,
            Net_290,
            Net_10523,
            Net_2761,
            Net_10507,
            Net_10508,
            Net_10509,
            Net_10510,
            Net_10511,
            Net_10512
        })
    );
    defparam P_6.comp_name = "Connector20_v1_0";
    defparam P_6.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_6.width = 20;

    cy_annotation_universal_v1_0 R_42 (
        .connect({
            Net_290,
            Net_10621
        })
    );
    defparam R_42.comp_name = "Resistor_v1_0";
    defparam R_42.port_names = "T1, T2";
    defparam R_42.width = 2;

    cy_annotation_universal_v1_0 C_34 (
        .connect({
            Net_412,
            Net_10285
        })
    );
    defparam C_34.comp_name = "Capacitor_v1_0";
    defparam C_34.port_names = "T1, T2";
    defparam C_34.width = 2;

    cy_annotation_universal_v1_0 GND_24 (
        .connect({
            Net_10285
        })
    );
    defparam GND_24.comp_name = "Gnd_v1_0";
    defparam GND_24.port_names = "T1";
    defparam GND_24.width = 1;

    cy_annotation_universal_v1_0 PWR_9 (
        .connect({
            Net_10506
        })
    );
    defparam PWR_9.comp_name = "Power_v1_0";
    defparam PWR_9.port_names = "T1";
    defparam PWR_9.width = 1;

	wire [0:0] tmpOE__FAN_CTRL_net;
	wire [0:0] tmpFB_0__FAN_CTRL_net;
	wire [0:0] tmpIO_0__FAN_CTRL_net;
	wire [0:0] tmpINTERRUPT_0__FAN_CTRL_net;
	electrical [0:0] tmpSIOVREF__FAN_CTRL_net;

	cy_psoc3_pins_v1_10
		#(.id("098539c6-72fc-445a-bbee-de8d2c7bc6b8"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		FAN_CTRL
		 (.oe(tmpOE__FAN_CTRL_net),
		  .y({Net_10524}),
		  .fb({tmpFB_0__FAN_CTRL_net[0:0]}),
		  .io({tmpIO_0__FAN_CTRL_net[0:0]}),
		  .siovref(tmpSIOVREF__FAN_CTRL_net),
		  .interrupt({tmpINTERRUPT_0__FAN_CTRL_net[0:0]}),
		  .annotation({Net_10580}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__FAN_CTRL_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    PWM_v3_30_8 FanCtrl (
        .reset(1'b0),
        .clock(Net_10540),
        .tc(Net_10541),
        .pwm1(Net_10542),
        .pwm2(Net_10543),
        .interrupt(Net_10544),
        .capture(1'b0),
        .kill(1'b1),
        .enable(1'b1),
        .trigger(1'b0),
        .cmp_sel(1'b0),
        .pwm(Net_10524),
        .ph1(Net_10551),
        .ph2(Net_10552));
    defparam FanCtrl.Resolution = 8;


	cy_clock_v1_0
		#(.id("638a4f95-3769-4114-8fce-0b10871cd95a"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_4
		 (.clock_out(Net_10540));


	wire [0:0] tmpOE__I_BtnChangePolarity_net;
	wire [0:0] tmpIO_0__I_BtnChangePolarity_net;
	wire [0:0] tmpINTERRUPT_0__I_BtnChangePolarity_net;
	electrical [0:0] tmpSIOVREF__I_BtnChangePolarity_net;

	cy_psoc3_pins_v1_10
		#(.id("e146d643-ef55-4dc5-a30f-d55a65fe2690"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_BtnChangePolarity
		 (.oe(tmpOE__I_BtnChangePolarity_net),
		  .y({1'b0}),
		  .fb({Net_10728}),
		  .io({tmpIO_0__I_BtnChangePolarity_net[0:0]}),
		  .siovref(tmpSIOVREF__I_BtnChangePolarity_net),
		  .interrupt({tmpINTERRUPT_0__I_BtnChangePolarity_net[0:0]}),
		  .annotation({Net_10434}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_BtnChangePolarity_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_7 (
        .connect({
            Net_10357,
            Net_10434
        })
    );
    defparam SW_7.comp_name = "SwitchSPST_v1_0";
    defparam SW_7.port_names = "T1, T2";
    defparam SW_7.width = 2;

	wire [0:0] tmpOE__I_BtnBipolarMode_net;
	wire [0:0] tmpIO_0__I_BtnBipolarMode_net;
	wire [0:0] tmpINTERRUPT_0__I_BtnBipolarMode_net;
	electrical [0:0] tmpSIOVREF__I_BtnBipolarMode_net;

	cy_psoc3_pins_v1_10
		#(.id("0753eaa2-82d3-4f73-a322-ca027780335a"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_BtnBipolarMode
		 (.oe(tmpOE__I_BtnBipolarMode_net),
		  .y({1'b0}),
		  .fb({Net_10727}),
		  .io({tmpIO_0__I_BtnBipolarMode_net[0:0]}),
		  .siovref(tmpSIOVREF__I_BtnBipolarMode_net),
		  .interrupt({tmpINTERRUPT_0__I_BtnBipolarMode_net[0:0]}),
		  .annotation({Net_10431}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_BtnBipolarMode_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_6 (
        .connect({
            Net_10357,
            Net_10797,
            Net_10800,
            Net_10798,
            Net_10431,
            Net_10799
        })
    );
    defparam SW_6.comp_name = "SwitchDT_v1_0";
    defparam SW_6.port_names = "C1, C2, NC1, NC2, NO1, NO2";
    defparam SW_6.width = 6;

	wire [0:0] tmpOE__I_BtnRiseRatePowerUp_net;
	wire [0:0] tmpIO_0__I_BtnRiseRatePowerUp_net;
	wire [0:0] tmpINTERRUPT_0__I_BtnRiseRatePowerUp_net;
	electrical [0:0] tmpSIOVREF__I_BtnRiseRatePowerUp_net;

	cy_psoc3_pins_v1_10
		#(.id("981dc9b9-9823-4052-9711-be2dabcfdf26"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_BtnRiseRatePowerUp
		 (.oe(tmpOE__I_BtnRiseRatePowerUp_net),
		  .y({1'b0}),
		  .fb({Net_10736}),
		  .io({tmpIO_0__I_BtnRiseRatePowerUp_net[0:0]}),
		  .siovref(tmpSIOVREF__I_BtnRiseRatePowerUp_net),
		  .interrupt({tmpINTERRUPT_0__I_BtnRiseRatePowerUp_net[0:0]}),
		  .annotation({Net_10423}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_BtnRiseRatePowerUp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_5 (
        .connect({
            Net_10357,
            Net_10793,
            Net_10796,
            Net_10794,
            Net_10423,
            Net_10795
        })
    );
    defparam SW_5.comp_name = "SwitchDT_v1_0";
    defparam SW_5.port_names = "C1, C2, NC1, NC2, NO1, NO2";
    defparam SW_5.width = 6;

	wire [0:0] tmpOE__I_BtnOk_net;
	wire [0:0] tmpIO_0__I_BtnOk_net;
	wire [0:0] tmpINTERRUPT_0__I_BtnOk_net;
	electrical [0:0] tmpSIOVREF__I_BtnOk_net;

	cy_psoc3_pins_v1_10
		#(.id("cb955d30-cde9-4fcc-bc7b-9ebdae1c5886"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_BtnOk
		 (.oe(tmpOE__I_BtnOk_net),
		  .y({1'b0}),
		  .fb({Net_10739}),
		  .io({tmpIO_0__I_BtnOk_net[0:0]}),
		  .siovref(tmpSIOVREF__I_BtnOk_net),
		  .interrupt({tmpINTERRUPT_0__I_BtnOk_net[0:0]}),
		  .annotation({Net_10365}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_BtnOk_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 GND_20 (
        .connect({
            Net_10357
        })
    );
    defparam GND_20.comp_name = "Gnd_v1_0";
    defparam GND_20.port_names = "T1";
    defparam GND_20.width = 1;

    cy_annotation_universal_v1_0 SW_4 (
        .connect({
            Net_10357,
            Net_10365
        })
    );
    defparam SW_4.comp_name = "SwitchSPST_v1_0";
    defparam SW_4.port_names = "T1, T2";
    defparam SW_4.width = 2;

    cy_annotation_universal_v1_0 R_36 (
        .connect({
            Net_10588,
            Net_10580
        })
    );
    defparam R_36.comp_name = "Resistor_v1_0";
    defparam R_36.port_names = "T1, T2";
    defparam R_36.width = 2;

    cy_annotation_universal_v1_0 R_44 (
        .connect({
            Net_10585,
            Net_10609
        })
    );
    defparam R_44.comp_name = "Resistor_v1_0";
    defparam R_44.port_names = "T1, T2";
    defparam R_44.width = 2;

    cy_annotation_universal_v1_0 PWR_3 (
        .connect({
            Net_10609
        })
    );
    defparam PWR_3.comp_name = "Power_v1_0";
    defparam PWR_3.port_names = "T1";
    defparam PWR_3.width = 1;

    cy_annotation_universal_v1_0 C_29 (
        .connect({
            Net_10585,
            Net_10607
        })
    );
    defparam C_29.comp_name = "Capacitor_v1_0";
    defparam C_29.port_names = "T1, T2";
    defparam C_29.width = 2;

    cy_annotation_universal_v1_0 P_1 (
        .connect({
            Net_10585,
            Net_10596,
            Net_10597,
            Net_10598,
            Net_10599,
            Net_10600,
            Net_10601,
            Net_10602,
            Net_10603,
            Net_10604,
            Net_10605,
            Net_10588,
            Net_10606,
            Net_10607,
            Net_10590,
            Net_10591,
            Net_10592,
            Net_10593,
            Net_10594,
            Net_10595
        })
    );
    defparam P_1.comp_name = "Connector20_v1_0";
    defparam P_1.port_names = "T1, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19, T2, T20, T3, T4, T5, T6, T7, T8, T9";
    defparam P_1.width = 20;

    cy_annotation_universal_v1_0 GND_13 (
        .connect({
            Net_10607
        })
    );
    defparam GND_13.comp_name = "Gnd_v1_0";
    defparam GND_13.port_names = "T1";
    defparam GND_13.width = 1;

    cy_annotation_universal_v1_0 R_45 (
        .connect({
            Net_2761,
            Net_10621
        })
    );
    defparam R_45.comp_name = "Resistor_v1_0";
    defparam R_45.port_names = "T1, T2";
    defparam R_45.width = 2;

    cy_annotation_universal_v1_0 C_30 (
        .connect({
            Net_2761,
            Net_10613
        })
    );
    defparam C_30.comp_name = "Capacitor_v1_0";
    defparam C_30.port_names = "T1, T2";
    defparam C_30.width = 2;

    cy_annotation_universal_v1_0 GND_17 (
        .connect({
            Net_317
        })
    );
    defparam GND_17.comp_name = "Gnd_v1_0";
    defparam GND_17.port_names = "T1";
    defparam GND_17.width = 1;

    CyControlReg_v1_80 LCD_DB_OutEnable (
        .control_1(Net_10714),
        .control_2(Net_10715),
        .control_3(Net_10716),
        .control_0(Net_10708),
        .control_4(Net_10717),
        .control_5(Net_10710),
        .control_6(Net_10711),
        .control_7(Net_10712),
        .clock(1'b0),
        .reset(1'b0));
    defparam LCD_DB_OutEnable.Bit0Mode = 0;
    defparam LCD_DB_OutEnable.Bit1Mode = 0;
    defparam LCD_DB_OutEnable.Bit2Mode = 0;
    defparam LCD_DB_OutEnable.Bit3Mode = 0;
    defparam LCD_DB_OutEnable.Bit4Mode = 0;
    defparam LCD_DB_OutEnable.Bit5Mode = 0;
    defparam LCD_DB_OutEnable.Bit6Mode = 0;
    defparam LCD_DB_OutEnable.Bit7Mode = 0;
    defparam LCD_DB_OutEnable.BitValue = 0;
    defparam LCD_DB_OutEnable.BusDisplay = 0;
    defparam LCD_DB_OutEnable.ExtrReset = 0;
    defparam LCD_DB_OutEnable.NumOutputs = 1;

	wire [0:0] tmpOE__I_MultiJogA_net;
	wire [0:0] tmpIO_0__I_MultiJogA_net;
	wire [0:0] tmpINTERRUPT_0__I_MultiJogA_net;
	electrical [0:0] tmpSIOVREF__I_MultiJogA_net;

	cy_psoc3_pins_v1_10
		#(.id("8d318d8b-cf7b-4b6b-b02c-ab1c5c49d0ba"),
		  .drive_mode(3'b010),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		I_MultiJogA
		 (.oe(tmpOE__I_MultiJogA_net),
		  .y({1'b0}),
		  .fb({Net_13698}),
		  .io({tmpIO_0__I_MultiJogA_net[0:0]}),
		  .siovref(tmpSIOVREF__I_MultiJogA_net),
		  .interrupt({tmpINTERRUPT_0__I_MultiJogA_net[0:0]}),
		  .annotation({Net_10426}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__I_MultiJogA_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_2 (
        .connect({
            Net_10357,
            Net_10425
        })
    );
    defparam SW_2.comp_name = "SwitchSPST_v1_0";
    defparam SW_2.port_names = "T1, T2";
    defparam SW_2.width = 2;

    cy_annotation_universal_v1_0 SW_1 (
        .connect({
            Net_10357,
            Net_10426
        })
    );
    defparam SW_1.comp_name = "SwitchSPST_v1_0";
    defparam SW_1.port_names = "T1, T2";
    defparam SW_1.width = 2;


	cy_clock_v1_0
		#(.id("e31eef97-6257-4d26-a8ab-6ce18b480b59"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		Clock_7
		 (.clock_out(Net_13740));


    PulseConvert_v1_0 PulseConvert_1 (
        .p_in(Net_13698),
        .p_out(Net_13744),
        .sample_clk(Net_13740),
        .out_clk(Net_12888));

    CyStatusReg_v1_90 MultiJog_Status (
        .status_0(Net_13591),
        .status_1(Net_13661),
        .status_2(1'b0),
        .status_3(1'b0),
        .clock(Net_13740),
        .status_4(1'b0),
        .status_5(1'b0),
        .status_6(1'b0),
        .status_7(1'b0),
        .intr(Net_13054),
        .status_bus(8'b0));
    defparam MultiJog_Status.Bit0Mode = 0;
    defparam MultiJog_Status.Bit1Mode = 0;
    defparam MultiJog_Status.Bit2Mode = 1;
    defparam MultiJog_Status.Bit3Mode = 0;
    defparam MultiJog_Status.Bit4Mode = 1;
    defparam MultiJog_Status.Bit5Mode = 0;
    defparam MultiJog_Status.Bit6Mode = 0;
    defparam MultiJog_Status.Bit7Mode = 0;
    defparam MultiJog_Status.BusDisplay = 0;
    defparam MultiJog_Status.Interrupt = 0;
    defparam MultiJog_Status.MaskValue = 0;
    defparam MultiJog_Status.NumInputs = 2;

    // -- SRFF Start --
    reg  cy_srff_1;
    always @(posedge Net_13740)
    begin
        cy_srff_1 <= (Net_13744 | Net_13591) & ~Net_11749;
    end
    assign Net_13591 = cy_srff_1;
    // -- SRFF End --

    Timer_v2_70_9 MultiJog_Timer (
        .reset(Net_13744),
        .interrupt(Net_11743),
        .enable(1'b1),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_11747),
        .tc(Net_11749),
        .clock(Net_12888));
    defparam MultiJog_Timer.CaptureCount = 2;
    defparam MultiJog_Timer.CaptureCounterEnabled = 0;
    defparam MultiJog_Timer.DeviceFamily = "PSoC5";
    defparam MultiJog_Timer.InterruptOnCapture = 0;
    defparam MultiJog_Timer.InterruptOnTC = 0;
    defparam MultiJog_Timer.Resolution = 16;
    defparam MultiJog_Timer.SiliconRevision = "0";


    assign Net_13753 = ~Net_13591;


	cy_clock_v1_0
		#(.id("58f0f612-373f-432d-b80a-0897e0b73be4"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("1E+15"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_8
		 (.clock_out(Net_13752));


    PulseConvert_v1_0 PulseConvert_2 (
        .p_in(Net_13752),
        .p_out(Net_13755),
        .sample_clk(Net_13740),
        .out_clk(Net_13744));

    // -- SRFF Start --
    reg  cy_srff_2;
    always @(posedge Net_13740)
    begin
        cy_srff_2 <= (Net_13715 | Net_13661) & ~Net_13753;
    end
    assign Net_13661 = cy_srff_2;
    // -- SRFF End --


    assign Net_13742 = Net_13753 | Net_13755;

    Timer_v2_70_10 MultiJog_FreqMeter (
        .reset(Net_13742),
        .interrupt(Net_13038),
        .enable(1'b1),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_13042),
        .tc(Net_13715),
        .clock(Net_13744));
    defparam MultiJog_FreqMeter.CaptureCount = 2;
    defparam MultiJog_FreqMeter.CaptureCounterEnabled = 0;
    defparam MultiJog_FreqMeter.DeviceFamily = "PSoC5";
    defparam MultiJog_FreqMeter.InterruptOnCapture = 0;
    defparam MultiJog_FreqMeter.InterruptOnTC = 0;
    defparam MultiJog_FreqMeter.Resolution = 8;
    defparam MultiJog_FreqMeter.SiliconRevision = "0";


	cy_clock_v1_0
		#(.id("228eccd9-1807-45d0-8510-b7bb37cac343"),
		  .source_clock_id("61737EF6-3B74-48f9-8B91-F7473A442AE7"),
		  .divisor(0),
		  .period("1000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		Clock_11
		 (.clock_out(Net_12888));




endmodule


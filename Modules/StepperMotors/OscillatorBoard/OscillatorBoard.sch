EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Driver_LED:STP16CP05 U1
U 1 1 5F173294
P 4300 2350
F 0 "U1" H 4300 3631 50  0000 C CNN
F 1 "STP16CP05" H 4300 3540 50  0000 C CNN
F 2 "Package_SO:QSOP-24_3.9x8.7mm_P0.635mm" H 4300 2350 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/stp16cp05.pdf" H 4300 2350 50  0001 C CNN
	1    4300 2350
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74469 U4
U 1 1 5F187F57
P 7000 2150
F 0 "U4" H 7000 3231 50  0000 C CNN
F 1 "74469" H 7000 3140 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm" H 7000 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74469" H 7000 2150 50  0001 C CNN
	1    7000 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 5F1A2882
P 5700 6300
F 0 "J2" V 5546 6348 50  0000 L CNN
F 1 "Conn_01x02_Female" V 5637 6348 50  0000 L CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x02_P2.00mm_Vertical" H 5700 6300 50  0001 C CNN
F 3 "~" H 5700 6300 50  0001 C CNN
	1    5700 6300
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 4850 4300 4850
Wire Wire Line
	5700 3450 4300 3450
Wire Wire Line
	5700 3050 7000 3050
Wire Wire Line
	5600 3200 7000 3200
Wire Wire Line
	5600 4250 4300 4250
Connection ~ 5600 3200
Connection ~ 5700 3450
Wire Wire Line
	5700 3450 5700 3050
Wire Wire Line
	5700 3450 5700 4600
$Comp
L Oscillator:MAX7375AXR105 U2
U 1 1 5F196CE0
P 4300 4550
F 0 "U2" H 4071 4596 50  0000 R CNN
F 1 "MAX7375AXR105" H 4071 4505 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 5400 4200 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX7375.pdf" H 4200 4550 50  0001 C CNN
	1    4300 4550
	1    0    0    -1  
$EndComp
Connection ~ 5600 4250
Wire Wire Line
	5600 3200 5600 4250
Connection ~ 5700 4850
$Comp
L Connector:Conn_01x03_Female J1
U 1 1 5F1A9676
P 2000 5450
F 0 "J1" H 2028 5476 50  0000 L CNN
F 1 "Conn_01x03_Female" H 2028 5385 50  0000 L CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x03_P2.00mm_Vertical" H 2000 5450 50  0001 C CNN
F 3 "~" H 2000 5450 50  0001 C CNN
	1    2000 5450
	-1   0    0    1   
$EndComp
Wire Wire Line
	5600 4250 5600 4950
Text Label 2200 5350 0    50   ~ 0
SDA
Text Label 2200 5450 0    50   ~ 0
SCL
Text Label 2200 5550 0    50   ~ 0
LCK
Text Label 5700 6300 3    50   ~ 0
GND
Text Label 5600 6300 3    50   ~ 0
VCC
Wire Wire Line
	5900 3150 5900 4700
Wire Wire Line
	5900 4700 6500 4700
Wire Wire Line
	7500 2550 7500 3150
$Comp
L Connector:Conn_01x01_Female J3
U 1 1 5F1ADB6B
P 9700 5200
F 0 "J3" H 9592 4975 50  0000 C CNN
F 1 "Conn_01x01_Female" H 9592 5066 50  0000 C CNN
F 2 "Connector_PinSocket_2.00mm:PinSocket_1x01_P2.00mm_Vertical" H 9700 5200 50  0001 C CNN
F 3 "~" H 9700 5200 50  0001 C CNN
	1    9700 5200
	1    0    0    -1  
$EndComp
Text Label 9500 5200 1    50   ~ 0
OUT
Wire Wire Line
	4700 1450 6500 1450
Wire Wire Line
	6500 1450 6500 1550
Wire Wire Line
	4700 1550 6450 1550
Wire Wire Line
	6450 1550 6450 1650
Wire Wire Line
	6450 1650 6500 1650
Wire Wire Line
	4700 1650 6350 1650
Wire Wire Line
	6350 1650 6350 1750
Wire Wire Line
	6350 1750 6500 1750
Wire Wire Line
	4700 1750 6250 1750
Wire Wire Line
	6250 1750 6250 1850
Wire Wire Line
	6250 1850 6500 1850
Wire Wire Line
	4700 1850 6150 1850
Wire Wire Line
	6150 1850 6150 1950
Wire Wire Line
	6150 1950 6500 1950
Wire Wire Line
	4700 1950 6050 1950
Wire Wire Line
	6050 1950 6050 2050
Wire Wire Line
	6050 2050 6500 2050
Wire Wire Line
	4700 2050 5950 2050
Wire Wire Line
	5950 2050 5950 2150
Wire Wire Line
	5950 2150 6500 2150
Wire Wire Line
	4700 2150 5850 2150
Wire Wire Line
	5850 2150 5850 2250
Wire Wire Line
	5850 2250 6500 2250
Wire Wire Line
	4700 2250 5450 2250
Wire Wire Line
	5450 2250 5450 3500
Wire Wire Line
	5450 3500 6500 3500
Wire Wire Line
	4700 2350 5400 2350
Wire Wire Line
	5400 2350 5400 3600
Wire Wire Line
	5400 3600 6500 3600
Wire Wire Line
	4700 2450 5350 2450
Wire Wire Line
	5350 2450 5350 3700
Wire Wire Line
	5350 3700 6500 3700
Wire Wire Line
	4700 2550 5300 2550
Wire Wire Line
	5300 2550 5300 3800
Wire Wire Line
	5300 3800 6500 3800
Wire Wire Line
	4700 2650 5250 2650
Wire Wire Line
	5250 2650 5250 3900
Wire Wire Line
	5250 3900 6500 3900
Wire Wire Line
	4700 2750 5200 2750
Wire Wire Line
	5200 2750 5200 4000
Wire Wire Line
	5200 4000 6500 4000
Wire Wire Line
	4700 2850 5150 2850
Wire Wire Line
	5150 2850 5150 4100
Wire Wire Line
	5150 4100 6500 4100
Wire Wire Line
	4700 2950 5100 2950
Wire Wire Line
	5100 2950 5100 4200
Wire Wire Line
	5100 4200 6500 4200
$Comp
L 74xGxx:74AUC1G08 U7
U 1 1 5F1BC4E1
P 8700 5200
F 0 "U7" H 8675 5467 50  0000 C CNN
F 1 "74AUC1G08" H 8675 5376 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 8700 5200 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 8700 5200 50  0001 C CNN
	1    8700 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 5200 9500 5200
Wire Wire Line
	7500 4500 8100 4500
Wire Wire Line
	6000 2450 6500 2450
Wire Wire Line
	6000 4400 6500 4400
Wire Wire Line
	6000 4400 6000 2450
Wire Wire Line
	4700 4550 6000 4550
Wire Wire Line
	6000 4550 6000 4400
Connection ~ 6000 4400
$Comp
L 74xGxx:74AHC1G04 U6
U 1 1 5F1FE5AC
P 7600 5250
F 0 "U6" H 7575 5517 50  0000 C CNN
F 1 "74AHC1G04" H 7575 5426 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-143" H 7600 5250 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 7600 5250 50  0001 C CNN
	1    7600 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 5350 2200 1450
Wire Wire Line
	2200 1450 3900 1450
Wire Wire Line
	3900 1550 2300 1550
Wire Wire Line
	2300 1550 2300 5450
Wire Wire Line
	2300 5450 2200 5450
Wire Wire Line
	6350 5600 6350 4500
Wire Wire Line
	6350 4500 6500 4500
Wire Wire Line
	6350 4500 6350 2550
Wire Wire Line
	6350 2550 6500 2550
Connection ~ 6350 4500
Wire Wire Line
	5350 5550 5350 5250
Wire Wire Line
	5350 5250 7300 5250
Wire Wire Line
	7850 5250 8400 5250
Wire Wire Line
	8100 4500 8100 5850
Wire Wire Line
	5800 5850 5800 5650
Connection ~ 8100 4500
Wire Wire Line
	8100 4500 8400 4500
Wire Wire Line
	8400 4500 8400 5150
Wire Wire Line
	5350 5550 5800 5550
Wire Wire Line
	5800 5850 8100 5850
Wire Wire Line
	2200 5550 5350 5550
Connection ~ 5350 5550
Wire Wire Line
	6500 2650 5700 2650
Wire Wire Line
	5700 2650 5700 2750
Connection ~ 5700 3050
Wire Wire Line
	6500 4600 5700 4600
Connection ~ 5700 4600
Wire Wire Line
	5700 4600 5700 4850
Wire Wire Line
	6500 2750 5700 2750
Connection ~ 5700 2750
Wire Wire Line
	5700 2750 5700 3050
Wire Wire Line
	7000 3050 7550 3050
Wire Wire Line
	7550 3050 7550 2450
Wire Wire Line
	7550 2450 7500 2450
Connection ~ 7000 3050
Wire Wire Line
	7550 4400 7500 4400
$Comp
L 74xGxx:74AHC1G02 U3
U 1 1 5F273562
P 6100 5600
F 0 "U3" H 6075 5867 50  0000 C CNN
F 1 "74AHC1G02" H 6075 5776 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5" H 6100 5600 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 6100 5600 50  0001 C CNN
	1    6100 5600
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5F275882
P 3750 2150
F 0 "R1" H 3820 2196 50  0000 L CNN
F 1 "1K" H 3820 2105 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 3680 2150 50  0001 C CNN
F 3 "~" H 3750 2150 50  0001 C CNN
	1    3750 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 2000 3750 1850
Wire Wire Line
	3750 1850 3900 1850
Wire Wire Line
	3750 2300 3750 3450
Wire Wire Line
	3750 3450 4300 3450
Connection ~ 4300 3450
Wire Wire Line
	5600 5400 6100 5400
Wire Wire Line
	6100 5400 6100 5500
Connection ~ 5600 5400
Wire Wire Line
	5600 5400 5600 6100
Wire Wire Line
	5600 5100 7600 5100
Wire Wire Line
	7600 5100 7600 5150
Connection ~ 5600 5100
Wire Wire Line
	5600 5100 5600 5400
Wire Wire Line
	5700 5750 6100 5750
Wire Wire Line
	6100 5750 6100 5700
Connection ~ 5700 5750
Wire Wire Line
	5700 5750 5700 6000
Wire Wire Line
	5700 5350 7600 5350
Connection ~ 5700 5350
Wire Wire Line
	5700 5350 5700 5750
Wire Wire Line
	8700 5300 8700 6000
Wire Wire Line
	8700 6000 5700 6000
Connection ~ 5700 6000
Wire Wire Line
	5700 6000 5700 6100
Wire Wire Line
	8700 5100 8700 4950
Connection ~ 5600 4950
Wire Wire Line
	5600 4950 5600 5100
Connection ~ 5700 5050
Wire Wire Line
	5700 5050 5700 5350
Wire Wire Line
	5700 4850 5700 5050
Wire Wire Line
	8700 4950 5600 4950
Wire Wire Line
	7500 3150 5900 3150
$Comp
L 74xx:74469 U5
U 1 1 5F18E56A
P 7000 4100
F 0 "U5" H 7000 5181 50  0000 C CNN
F 1 "74469" H 7000 5090 50  0000 C CNN
F 2 "Package_DIP:DIP-24_W7.62mm" H 7000 4100 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74469" H 7000 4100 50  0001 C CNN
	1    7000 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5050 7000 5050
Wire Wire Line
	7550 4400 7550 5050
Wire Wire Line
	7000 5000 7000 5050
Connection ~ 7000 5050
Wire Wire Line
	7000 5050 7550 5050
Wire Wire Line
	4300 1200 5600 1200
Wire Wire Line
	7000 1200 7000 1250
Wire Wire Line
	5600 1200 5600 3200
Connection ~ 5600 1200
Wire Wire Line
	5600 1200 7000 1200
Wire Wire Line
	4300 1200 4300 1250
$EndSCHEMATC

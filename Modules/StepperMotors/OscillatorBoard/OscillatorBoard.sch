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
L Driver_LED:STP16CP05 U?
U 1 1 5F173294
P 3300 2250
F 0 "U?" H 3300 3531 50  0000 C CNN
F 1 "STP16CP05" H 3300 3440 50  0000 C CNN
F 2 "" H 3300 2250 50  0001 C CNN
F 3 "https://www.st.com/resource/en/datasheet/stp16cp05.pdf" H 3300 2250 50  0001 C CNN
	1    3300 2250
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74469 U?
U 1 1 5F187F57
P 6000 2050
F 0 "U?" H 6000 3131 50  0000 C CNN
F 1 "74469" H 6000 3040 50  0000 C CNN
F 2 "" H 6000 2050 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74469" H 6000 2050 50  0001 C CNN
	1    6000 2050
	1    0    0    -1  
$EndComp
$Comp
L 74xx:74469 U?
U 1 1 5F18E56A
P 6000 4000
F 0 "U?" H 6000 5081 50  0000 C CNN
F 1 "74469" H 6000 4990 50  0000 C CNN
F 2 "" H 6000 4000 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74469" H 6000 4000 50  0001 C CNN
	1    6000 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J?
U 1 1 5F1A2882
P 4700 6200
F 0 "J?" V 4546 6248 50  0000 L CNN
F 1 "Conn_01x02_Female" V 4637 6248 50  0000 L CNN
F 2 "" H 4700 6200 50  0001 C CNN
F 3 "~" H 4700 6200 50  0001 C CNN
	1    4700 6200
	0    1    1    0   
$EndComp
Wire Wire Line
	4700 4900 6000 4900
Wire Wire Line
	4700 4750 3300 4750
Wire Wire Line
	4700 3350 3300 3350
Wire Wire Line
	4700 2950 6000 2950
Wire Wire Line
	4600 3100 6000 3100
Wire Wire Line
	4600 4150 3300 4150
Wire Wire Line
	4600 3100 4600 1150
Connection ~ 4600 3100
Connection ~ 4600 1150
Wire Wire Line
	4600 1150 3300 1150
Wire Wire Line
	4600 1150 6000 1150
Connection ~ 4700 3350
Wire Wire Line
	4700 3350 4700 2950
Wire Wire Line
	4700 3350 4700 4500
$Comp
L Oscillator:MAX7375AXR105 U?
U 1 1 5F196CE0
P 3300 4450
F 0 "U?" H 3071 4496 50  0000 R CNN
F 1 "MAX7375AXR105" H 3071 4405 50  0000 R CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70" H 4400 4100 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX7375.pdf" H 3200 4450 50  0001 C CNN
	1    3300 4450
	1    0    0    -1  
$EndComp
Connection ~ 4600 4150
Wire Wire Line
	4600 3100 4600 4150
Connection ~ 4700 4750
Wire Wire Line
	4700 4750 4700 4900
Connection ~ 4700 4900
$Comp
L Connector:Conn_01x03_Female J?
U 1 1 5F1A9676
P 1000 5350
F 0 "J?" H 1028 5376 50  0000 L CNN
F 1 "Conn_01x03_Female" H 1028 5285 50  0000 L CNN
F 2 "" H 1000 5350 50  0001 C CNN
F 3 "~" H 1000 5350 50  0001 C CNN
	1    1000 5350
	-1   0    0    1   
$EndComp
Wire Wire Line
	4600 4150 4600 6000
Wire Wire Line
	4700 4900 4700 6000
Text Label 1200 5250 0    50   ~ 0
SDA
Text Label 1200 5350 0    50   ~ 0
SCL
Text Label 1200 5450 0    50   ~ 0
LCK
Text Label 4700 6200 3    50   ~ 0
GND
Text Label 4600 6200 3    50   ~ 0
VCC
Wire Wire Line
	6500 3050 4900 3050
Wire Wire Line
	4900 3050 4900 4600
Wire Wire Line
	4900 4600 5500 4600
Wire Wire Line
	6500 2450 6500 3050
$Comp
L Connector:Conn_01x01_Female J?
U 1 1 5F1ADB6B
P 8700 5100
F 0 "J?" H 8592 4875 50  0000 C CNN
F 1 "Conn_01x01_Female" H 8592 4966 50  0000 C CNN
F 2 "" H 8700 5100 50  0001 C CNN
F 3 "~" H 8700 5100 50  0001 C CNN
	1    8700 5100
	1    0    0    -1  
$EndComp
Text Label 8500 5100 1    50   ~ 0
OUT
Wire Wire Line
	3700 1350 5500 1350
Wire Wire Line
	5500 1350 5500 1450
Wire Wire Line
	3700 1450 5450 1450
Wire Wire Line
	5450 1450 5450 1550
Wire Wire Line
	5450 1550 5500 1550
Wire Wire Line
	3700 1550 5350 1550
Wire Wire Line
	5350 1550 5350 1650
Wire Wire Line
	5350 1650 5500 1650
Wire Wire Line
	3700 1650 5250 1650
Wire Wire Line
	5250 1650 5250 1750
Wire Wire Line
	5250 1750 5500 1750
Wire Wire Line
	3700 1750 5150 1750
Wire Wire Line
	5150 1750 5150 1850
Wire Wire Line
	5150 1850 5500 1850
Wire Wire Line
	3700 1850 5050 1850
Wire Wire Line
	5050 1850 5050 1950
Wire Wire Line
	5050 1950 5500 1950
Wire Wire Line
	3700 1950 4950 1950
Wire Wire Line
	4950 1950 4950 2050
Wire Wire Line
	4950 2050 5500 2050
Wire Wire Line
	3700 2050 4850 2050
Wire Wire Line
	4850 2050 4850 2150
Wire Wire Line
	4850 2150 5500 2150
Wire Wire Line
	3700 2150 4450 2150
Wire Wire Line
	4450 2150 4450 3400
Wire Wire Line
	4450 3400 5500 3400
Wire Wire Line
	3700 2250 4400 2250
Wire Wire Line
	4400 2250 4400 3500
Wire Wire Line
	4400 3500 5500 3500
Wire Wire Line
	3700 2350 4350 2350
Wire Wire Line
	4350 2350 4350 3600
Wire Wire Line
	4350 3600 5500 3600
Wire Wire Line
	3700 2450 4300 2450
Wire Wire Line
	4300 2450 4300 3700
Wire Wire Line
	4300 3700 5500 3700
Wire Wire Line
	3700 2550 4250 2550
Wire Wire Line
	4250 2550 4250 3800
Wire Wire Line
	4250 3800 5500 3800
Wire Wire Line
	3700 2650 4200 2650
Wire Wire Line
	4200 2650 4200 3900
Wire Wire Line
	4200 3900 5500 3900
Wire Wire Line
	3700 2750 4150 2750
Wire Wire Line
	4150 2750 4150 4000
Wire Wire Line
	4150 4000 5500 4000
Wire Wire Line
	3700 2850 4100 2850
Wire Wire Line
	4100 2850 4100 4100
Wire Wire Line
	4100 4100 5500 4100
$Comp
L 74xGxx:74AUC1G08 U?
U 1 1 5F1BC4E1
P 7700 5100
F 0 "U?" H 7675 5367 50  0000 C CNN
F 1 "74AUC1G08" H 7675 5276 50  0000 C CNN
F 2 "" H 7700 5100 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 7700 5100 50  0001 C CNN
	1    7700 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7950 5100 8500 5100
Wire Wire Line
	6500 4400 7100 4400
Wire Wire Line
	5000 2350 5500 2350
Wire Wire Line
	5000 4300 5500 4300
Wire Wire Line
	5000 4300 5000 2350
Wire Wire Line
	3700 4450 5000 4450
Wire Wire Line
	5000 4450 5000 4300
Connection ~ 5000 4300
$Comp
L 74xGxx:74AHC1G04 U?
U 1 1 5F1FE5AC
P 6600 5150
F 0 "U?" H 6575 5417 50  0000 C CNN
F 1 "74AHC1G04" H 6575 5326 50  0000 C CNN
F 2 "" H 6600 5150 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 6600 5150 50  0001 C CNN
	1    6600 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 5250 1200 1350
Wire Wire Line
	1200 1350 2900 1350
Wire Wire Line
	2900 1450 1300 1450
Wire Wire Line
	1300 1450 1300 5350
Wire Wire Line
	1300 5350 1200 5350
Wire Wire Line
	5350 5500 5350 4400
Wire Wire Line
	5350 4400 5500 4400
Wire Wire Line
	5350 4400 5350 2450
Wire Wire Line
	5350 2450 5500 2450
Connection ~ 5350 4400
Wire Wire Line
	4350 5450 4350 5150
Wire Wire Line
	4350 5150 6300 5150
Wire Wire Line
	6850 5150 7400 5150
Wire Wire Line
	7100 4400 7100 5750
Wire Wire Line
	4800 5750 4800 5550
Connection ~ 7100 4400
Wire Wire Line
	7100 4400 7400 4400
Wire Wire Line
	7400 4400 7400 5050
Wire Wire Line
	4350 5450 4800 5450
Wire Wire Line
	4800 5750 7100 5750
Wire Wire Line
	1200 5450 4350 5450
Connection ~ 4350 5450
Wire Wire Line
	5500 2550 4700 2550
Wire Wire Line
	4700 2550 4700 2650
Connection ~ 4700 2950
Wire Wire Line
	5500 4500 4700 4500
Connection ~ 4700 4500
Wire Wire Line
	4700 4500 4700 4750
Wire Wire Line
	5500 2650 4700 2650
Connection ~ 4700 2650
Wire Wire Line
	4700 2650 4700 2950
Wire Wire Line
	6000 2950 6550 2950
Wire Wire Line
	6550 2950 6550 2350
Wire Wire Line
	6550 2350 6500 2350
Connection ~ 6000 2950
Wire Wire Line
	6000 4900 6550 4900
Wire Wire Line
	6550 4900 6550 4300
Wire Wire Line
	6550 4300 6500 4300
Connection ~ 6000 4900
$Comp
L 74xGxx:74AHC1G02 U?
U 1 1 5F273562
P 5100 5500
F 0 "U?" H 5075 5767 50  0000 C CNN
F 1 "74AHC1G02" H 5075 5676 50  0000 C CNN
F 2 "" H 5100 5500 50  0001 C CNN
F 3 "http://www.ti.com/lit/sg/scyt129e/scyt129e.pdf" H 5100 5500 50  0001 C CNN
	1    5100 5500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F275882
P 2750 2050
F 0 "R?" H 2820 2096 50  0000 L CNN
F 1 "1K" H 2820 2005 50  0000 L CNN
F 2 "" V 2680 2050 50  0001 C CNN
F 3 "~" H 2750 2050 50  0001 C CNN
	1    2750 2050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1900 2750 1750
Wire Wire Line
	2750 1750 2900 1750
Wire Wire Line
	2750 2200 2750 3350
Wire Wire Line
	2750 3350 3300 3350
Connection ~ 3300 3350
$EndSCHEMATC

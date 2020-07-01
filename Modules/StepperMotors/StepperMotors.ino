// Step pin of each motor driver
#define M1 3
#define M2 4
#define M3 5

#define A4 4489 // LA
#define A4d 4239 // LA#
#define B4 4001 // SI

#define C4 3778 // DO
#define C4d 3567 // DO#
#define D4 3363 // RE
#define D4d 3175 // RE#
#define E4 2995 // MI
#define F4 2825 // FA
#define F4d 2674 // FA#
#define G4 2515 // SOL
#define G4d 2375 // SOL#
#define A5 2243 // LA
#define A5d 2112 // LA#
#define B5 1996 // SI

#define C5 1886 // DO
#define C5d 1776 // DO#
#define D5 1678 // RE
#define D5d 1584 // RE#
#define E5 1495 // MI
#define F5 1409 // FA
#define F5d 1328 // FA#
#define G5 1252 // SOL
#define G5d 1182 // SOL#
#define A6 1116 // LA
#define A6d 1053 // LA#
#define B6 993 // SI

#define C6 936 // DO

const PROGMEM uint16_t notes1[] = {
    0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,C5,0,A5d,0,A5d,0,A5d,0,A5d,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,A5d,0,A5d,0,A5d,0,A5d,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,G4,0,G4,0,G4,0,G4,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,D5,0,D5,0,D5,0,D5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,C5,0,A5d,0,A5d,0,A5d,0,A5d,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,F4,0,F4,0,F4,0,F4,0,C5,0,C5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,G4,0,G4,0,G4,0,G4,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,D5,0,D5,0,D5,0,D5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,C5,0,C5,0,C5,0,A5d,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,G4,0,G4,0,G4,0,G4,0,G4,0,G4,0,G4,0,G4,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,C5,0,C5,0,C5,0,C5,0,F5,0,F5,0,F5,0,F5,0,F5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,C5,0,C5,0,C5,0,C5,0,C5,0,F5,0,F5,0,F5,0,F5,0,F5,0,C5,0,C5,0,C5,0,C5,0,C5,0,F5,0,F5,0,F5,0,F5,0,F5,0,A5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,C5,0,C5,0,C5,0,C5,0,C5,0,F5,0,F5,0,F5,0,F5,0,F5,0,A5d,0,A5d,0,A5d,0,A5d,0,A5d,0,D5,0,D5,0,D5,0,D5,0,D5,0,G4,0,G4,0,G4,0,G4,0,G4,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,G4,0,G4,0,G4,0,G4,0,G4,0,F5,0,F5,0,F5,0,F5,0,C5,0,C5,0,C5,0,C5,0,C5,0,G4,0,G4,0,G4,0,G4,0,G4,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,D5,0,A5d,0,A5d,0,A5d,0,A5d,0,A5d,0,F5,0,F5,0,F5,0,F5,0,F5,0,C5,0,C5,0,C5,0,C5,0,C5,0,G4,0,G4,0,G4,0,G4,0,G4,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,A5,0,D5,0,D5,0,D5,0,D5,0,D5,0
};
const PROGMEM uint32_t durations1[] = {
    3600,4425,4500,4900,4950,5350,5400,5650,5700,5847,5850,6100,6150,6297,6300,6550,6600,6747,6750,7000,7050,7197,7200,7450,7500,7647,7650,7900,7950,8097,8100,8350,8400,8547,8550,8800,8850,8997,9000,9250,9300,9447,9450,9700,9750,9897,9900,10150,10200,10347,10350,10600,10650,10797,10800,11050,11100,11247,11250,11500,11550,11697,11700,11950,12000,12147,12150,12400,12450,12597,12600,12850,12900,13047,13050,13300,13350,13497,13500,13750,13800,13947,13950,14200,14250,14397,14400,14650,14700,14847,14850,15100,15150,15297,15300,15550,15600,15747,15750,16000,16050,16197,16200,16450,16500,16647,16650,16900,16950,17097,17100,17350,17400,17547,17550,17800,17850,17997,18000,18250,18300,18447,18450,18700,18750,18897,18900,19150,19200,19347,19350,19600,19650,19797,19800,20050,20100,20247,20250,20500,20550,20697,20700,20950,21000,21147,21150,21400,21450,21597,21600,21850,21900,22047,22050,22300,22350,22497,22500,22750,22800,22947,22950,23200,23250,23397,23400,23650,23700,23847,23850,24100,24150,24297,24300,24550,24600,24747,24750,25000,25050,25197,25200,25450,25500,25647,25650,25900,25950,26097,26100,26350,26400,26547,26550,26800,26850,26997,27000,27250,27300,27447,27450,27700,27750,27897,27900,28150,28200,28347,28350,28600,28650,28797,28800,29050,29100,29247,29250,29500,29550,29697,29700,29950,30000,30147,30150,30400,30450,30597,30600,30850,30900,31047,31050,31300,31350,31497,31500,31750,31800,31947,31950,32200,32250,32397,32400,32650,32700,32847,32850,33100,33150,33297,33300,33550,33600,33850,33900,34150,34200,34450,34500,34750,34800,35050,35100,35350,35400,35547,35550,35800,35850,35997,36000,36250,36300,36447,36450,36700,36750,36897,36900,37150,37200,37347,37350,37600,37650,37797,37800,38050,38100,38247,38250,38500,38550,38697,38700,38950,39000,39147,39150,39400,39450,39597,39600,39850,39900,40047,40050,40300,40350,40497,40500,40750,40800,40947,40950,41200,41250,41397,41400,41650,41700,41847,41850,41997,42000,42147,42150,42297,42300,42550,42600,42747,42750,43000,43050,43197,43200,43450,43500,43647,43650,43797,43800,43947,43950,44097,44100,44350,44400,44547,44550,44800,44850,44997,45000,45250,45300,45447,45450,45597,45600,45747,45750,45897,45900,46150,46200,46347,46350,46600,46650,46797,46800,47050,47100,47247,47250,47500,47550,47697,47700,47950,48000,48147,48150,48400,48450,48597,48600,48850,48900,49047,49050,49197,49200,49347,49350,49497,49500,49750,49800,49947,49950,50097,50100,50247,50250,50397,50400,50650,50700,50847,50850,50997,51000,51147,51150,51297,51300,51550,51600,51747,51750,51897,51900,52047,52050,52197,52200,52450,52500,52647,52650,52797,52800,52947,52950,53097,53100,53350,53400,53547,53550,53800,53850,53997,54000,54250,54300,54447,54450,54597,54600,54747,54750,54897,54900,55150,55200,55347,55350,55497,55500,55647,55650,55797,55800,56050,56100,56247,56250,56397,56400,56547,56550,56697,56700,56950,57000,57147,57150,57297,57300,57447,57450,57597,57600,57850,57900,58047,58050,58197,58200,58347,58350,58497,58500,58750,58800,58947,58950,59097,59100,59247,59250,59397,59400,59650,59700,59847,59850,59997,60000,60147,60150,60297,60300,60550,60600,60747,60750,60897,60900,61047,61050,61197,61200,61450,61500,61647,61650,61797,61800,61947,61950,62097,62100,62350,62400,62547,62550,62697,62700,62847,62850,62997,63000,63250,63300,63447,63450,63597,63600,63747,63750,63897,63900,64150,64200,64347,64350,64600,64650,64797,64800,65050,65100,65247,65250,65397,65400,65547,65550,65697,65700,65950,66000,66147,66150,66297,66300,66447,66450,66597,66600,66850,66900,67047,67050,67197,67200,67347,67350,67497,67500,67750,67800,67947,67950,68097,68100,68247,68250,68397,68400,68650,68700,68847,68850,68997,69000,69147,69150,69297,69300,69550,69600,69747,69750,69897,69900,70047,70050,70197,70200,70450,70500,70647,70650,70797,70800,70947,70950,71097,71100,71350,71400,71547,71550,71697,71700,71847,71850,71997,72000,72250,72300,72447,72450,72597,72600,72747,72750,72897,72900,73150,73200,73347,73350,73497,73500,73647,73650,73797,73800,74050,74100,74247,74250,74397,74400,74547,74550,74697,74700,74950,75000,75147,75150,75297,75300,75447,75450,75597,75600,76000,76050,76197,76200,76347,76350,76497,76505,77630,4294967295
};
const PROGMEM uint16_t notes2[] = {
    0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,0,D4,A4,C4,D4,0,D4,0,D4,C4,D4,0,D4,0,D4,0,D4,C4,0,C4,D4,C4,0,C4,D4,0,A4,C4,D4,0,D4,0,D4,E4,F4,0,F4,0,F4,G4,E4,0,E4,D4,C4,D4,0,A4,C4,D4,0,D4,0,D4,F4,G4,0,G4,0,G4,A5,G4,0,G4,F4,G4,F4,0,D4,0,D4,E4,F4,0,F4,G4,F4,D4,0,D4,F4,E4,0,E4,F4,D4,E4,0,A5,C5,D5,0,D5,0,D5,E5,F5,0,F5,0,F5,G5,E5,0,E5,D5,C5,0,C5,0,D5,0,C5,D5,0,D5,0,D5,E5,F5,0,F5,0,F5,G5,E5,0,E5,D5,C5,D5,0,A5,C5,D5,0,D5,0,D5,F5,G5,0,G5,0,G5,A6,A6d,0,A6d,A6,G5,A6,D5,0,D5,E5,F5,0,F5,G5,A6,D5,0,D5,F5,E5,0,E5,0,D5,0,C5,D5,0,D5,E5,F5,0,F5,0,F5,G5,A6,F5,0,A5,0,A5,0,A5,0,D5,0,A5d,0,A5d,0,A5d,0,E4,0,E4,0,D4,0,F4,0,F4,0,G4,0,A5,0,A5,0,A5,0,A5d,0,A5,0,G4,0,G4,0,G4,0,G4,0,A5,0,A5,0,A5,0,A5,0,A5d,0,A5,0,G4,0,F4,0,E4,0,D4,0,D4,0,E4,0,F4,0,G4,0,A5,0,G4,0,F4,0,E4,0,F4,0,G4,0,A5,0,G4,0,F4,0,G4,0,A5,0,G4,0,F4,0,E4,0,F4,0,E4,0,D4,0,E4,0,D4,0,D5,0,E5,0,F5,0,E5,0,F5,0,G5,0,F5,0,G5,0,A6,0,G5,0,F5,0,D5,0,D5,0,E5,0,F5,0,G5,0,A6,0,A6d,0,G5,0,F5,0,G5,0,E5,0,D5,0,E5,0,C5d,0,D5,0,D5,0,C5,0,C5,0,C5,0,C5,0,G5,0,D5,0,D5,0,F5,0,G5,0,E5,0,D5,0,D5,E5,0,F5,0,F5,0,D5,E5,0,F5,0,F5,0,D5,E5,0,F5,0,F5,0,F5,0,F5,0,E5,0,G5,0,G5,0,F5,0,F5,0,G5,0,E5,0,A5,0,D4,0
};
const PROGMEM uint32_t durations2[] = {
    300,450,460,750,760,900,910,1200,1210,1350,1360,1500,1510,1650,1660,1800,1810,2100,2110,2250,2260,2550,2560,2700,2710,3000,3010,3150,3160,3300,3310,3450,3460,3600,3610,3900,3910,4050,4060,4350,4360,4500,4510,4800,4810,4950,4960,5100,5250,5400,5700,5710,6000,6010,6150,6300,6600,6610,6900,6910,7050,7060,7200,7500,7510,7800,7950,8100,8110,8250,8550,8700,8850,9000,9300,9310,9600,9610,9750,9900,10200,10210,10500,10510,10650,10800,11100,11110,11400,11550,11700,12000,12300,12450,12600,12900,12910,13200,13210,13350,13500,13800,13810,14100,14110,14250,14400,14700,14710,15000,15150,15300,15447,15450,15750,15900,16050,16200,16500,16510,16800,17100,17250,17550,17700,17850,18000,18300,18310,18600,18750,18900,19350,19500,19650,19800,20100,20110,20400,20410,20550,20700,21000,21010,21300,21310,21450,21600,21900,21910,22200,22350,22500,22510,22647,22650,22900,23250,23400,23700,23710,24000,24010,24150,24300,24600,24610,24900,24910,25050,25200,25500,25510,25800,25950,26100,26400,26700,26850,27000,27300,27310,27600,27610,27750,27900,28200,28210,28500,28510,28650,28800,29100,29110,29400,29550,29700,29850,30150,30300,30450,30600,30900,30910,31200,31500,31650,31950,32100,32250,32400,32700,32710,33000,33008,33158,33177,33300,33600,33610,33900,34200,34500,34510,34650,34660,34800,35100,35250,35400,35700,35850,35860,35850,36000,36000,36900,37050,37500,37650,37660,37800,37810,37800,38700,38847,38850,39100,39150,39550,39600,40000,40200,40347,40350,40497,40500,40750,40800,41050,41100,41350,41400,41547,41550,41697,42300,42550,42600,42850,42900,43150,43200,43347,43350,43497,44100,44350,44400,44650,44700,44950,45000,45147,45150,45297,45900,46150,46200,46450,46500,46750,46800,47050,47400,47547,47550,47697,47700,48225,48300,48447,48450,48597,48600,48850,48900,49150,49200,49450,49500,49750,49800,50050,50100,50350,50400,50650,51000,51147,51150,51297,51300,51550,51900,52047,52050,52197,52200,52450,52500,52750,52800,53050,53100,53350,53700,53847,54000,54147,54600,54747,54750,54897,54900,55150,55500,55647,55650,55797,55800,56050,56100,56350,56400,56650,56700,56950,57000,57250,57300,57550,57600,57850,58200,58347,58350,58497,58500,58750,58800,59050,59100,59350,59400,59650,60000,60250,60300,60550,60900,61047,61050,61197,61200,61450,61800,61947,61950,62097,62100,62350,63000,63250,63900,64150,64200,64450,64500,64750,64800,64947,64950,65097,65700,65950,66600,66850,67500,67750,67800,68050,68100,68350,68400,68800,68877,69000,69147,69150,69297,69300,69700,69784,69900,70047,70050,70197,70200,70600,70684,70800,70947,70950,71097,71100,71350,71400,71650,71700,71950,72000,72147,72150,72297,72900,73150,73800,74050,74700,74950,75000,75250,75300,75550,75600,76000,76500,77625,4294967295
};
const PROGMEM uint16_t notes3[] = {
    0,D4,0,D4,0,D4,0,D4,0,E4,0,F4,0,F4,0,G4,0,E4,0,D4,0,C4,0,C4,0,D4,0,A4,0,C4,0,D4,0,D4,0,E4,0,F4,0,F4,0,G4,0,E4,0,D4,0,C4,0,D4,0,A4,0,C4,0,D4,0,D4,0,F4,0,G4,0,G4,0,A5,0,A5d,0,A5,0,G4,0,A5,0,D4,0,D4,0,E4,0,F4,0,G4,0,A5,0,D4,0,D4,0,F4,0,E4,0,F4,0,D4,0,E4,0,A5,0,C5,0,D5,0,D5,0,E5,0,F5,0,F5,0,G5,0,E5,0,D5,0,C5,0,C5,0,D5,0,A5,0,C5,0,D5,0,D5,0,E5,0,F5,0,F5,0,G5,0,E5,0,D5,0,C5,0,D5,0,A5,0,C5,0,D5,0,D5,0,F5,0,G5,0,G5,0,A6,0,A6d,0,A6,0,G5,0,A6,0,D5,0,D5,0,E5,0,F5,0,G5,0,A6,0,D5,0,D5,0,F5,0,E5,0,D5,0,C5,D5,0,E5,0,F5,0,F5,0,G5,0,A6,0,F5,0,A6d,0,E4,0,D4,0,F4,0,A5,0,A5d,0,G4,0,A5,0,A5,0,A5d,0,G4,0,F4,0,E4,0,D4,0,D4,0,E4,0,F4,0,G4,0,E4,0,F4,0,G4,0,A5,0,G4,0,A5,0,G4,0,F4,0,E4,0,F4,0,E4,0,D4,0,E4,0,C4,0,D4,0,D5,0,E5,0,F5,0,G5,0,F5,0,G5,0,A6,0,G5,0,F5,0,D5,0,D5,0,F5,0,G5,0,A6,0,A6d,0,D5,0,G5,0,F5,0,G5,0,E5,0,D5,0,A6,0,A6d,0,A6,0,A6,0,A6,0,A6,0,G5,0,G5,0,F5,0,F5,0,G5,0,E5,0,D5,0,A6,0,A6d,0,A6,0,A6,0,C6,0,A6,0,G5,0,G5,0,F5,0,F5,0,G5,0,E5,0,D5,0
};
const PROGMEM uint32_t durations3[] = {
    2700,3525,3600,4425,5400,5925,6000,6147,6150,6297,6300,6825,6900,7047,7050,7197,7200,7725,7800,7947,7950,8097,8100,8247,8250,8397,8700,8847,8850,8997,9000,9525,9600,9747,9750,9897,9900,10425,10500,10647,10650,10797,10800,11325,11400,11547,11550,11697,11700,11950,12300,12447,12450,12597,12600,13125,13200,13347,13350,13497,13500,14025,14100,14247,14250,14397,14400,14925,15000,15147,15150,15297,15300,15447,15450,15700,15900,16047,16050,16197,16200,16725,16800,17050,17100,17247,17250,17500,17700,17847,17850,17997,18000,18525,18600,18747,18750,18897,18900,19300,19500,19647,19650,19797,19800,20325,20400,20547,20550,20697,20700,21225,21300,21447,21450,21597,21600,22125,22200,22347,22350,22497,22500,22647,22650,23050,23100,23247,23250,23397,23400,23925,24000,24147,24150,24297,24300,24825,24900,25047,25050,25197,25200,25725,25800,25947,25950,26097,26100,26350,26700,26847,26850,26997,27000,27525,27600,27747,27750,27897,27900,28425,28500,28647,28650,28797,28800,29325,29400,29547,29550,29697,29700,29847,29850,30100,30300,30447,30450,30597,30600,31125,31200,31450,31500,31647,31650,31900,32100,32247,32250,32397,32400,32925,33000,33147,33158,33300,33825,33900,34150,34200,34450,34500,34750,34800,35050,35100,35625,35700,35950,36900,37725,38700,39100,39150,39550,39600,40425,40500,41325,41400,41547,42300,43125,43200,43347,44100,44925,45000,45147,45900,46150,46200,46450,46500,46750,46800,47050,47400,47547,47550,47697,47700,48525,48600,49125,49200,49450,49500,49750,49800,50050,50100,50350,50400,51225,51300,51825,51900,52047,52050,52197,52200,52450,52500,52750,52800,53050,53100,53625,53700,53847,53850,53997,54000,54525,54600,54747,54750,54897,54900,55725,55800,56050,56100,56350,56400,56650,56700,56950,57000,57250,57300,57550,57600,58125,58188,58438,58500,58750,58800,59050,59100,59350,59400,59650,59700,59950,60000,60250,60300,60825,60900,61047,61050,61197,61200,62025,62100,62925,63000,63825,63900,64150,64200,64450,64500,64750,64800,64947,64950,65350,65700,66525,66600,67425,67500,67750,67800,68050,68100,68350,68400,69225,69300,70125,70200,71025,71100,71350,71400,71650,71700,71950,72000,72147,72150,72550,72900,73725,73800,74625,74700,74950,75000,75250,75300,75550,75600,76425,4294967295
};

void setup() {
}

struct Motor {
    const uint16_t* notes;
    const uint32_t* durations;
    int stepPin;
    // Index of the note currently played
    int index;
    // Time before the next rise of the STEP pin
    // The value registered here is the given one -100 us
    // To ensure we have time for the low state
    int current;
    // Saves the state of the STEP pin
    bool stepHigh;
    // Moment the motor need to switch to the next note
    unsigned long next;
};

void initMotor(struct Motor* m, const uint16_t* notes, const uint32_t* durations, int pin) {
    m->notes = notes;
    m->durations = durations;
    m->stepPin = pin;
    m->index = -1;
    m->current = 0;
    m->stepHigh = false;
    m->next = 0;
    pinMode(m->stepPin, OUTPUT);
    digitalWrite(m->stepPin, LOW);
}

void loop() {    
    
    struct Motor motors[3];
    initMotor(motors+0, notes1, durations1, M1);
    initMotor(motors+1, notes2, durations2, M2);
    initMotor(motors+2, notes3, durations3, M3);

    unsigned long lastUpdate = micros();
    while(1) {
                
        unsigned long t = micros();
        unsigned long delta = t - lastUpdate;
        lastUpdate = t;

        for(int i = 0; i < 3; i++) 
            motors[i].current -= delta;

        // Goes low for the last 100 us of the oscillation
        for(int i = 0; i < 3; i++) {
            if(motors[i].current < 0 && motors[i].stepHigh) {
                motors[i].stepHigh = false;
                digitalWrite(motors[i].stepPin, LOW);
            }
        }

        // When the low state has ended, goes to the next oscillation (and note if necessary)
        for(int i = 0; i < 3; i++) {
            if(motors[i].current < -95) {
                // If the duration is over: next note
                if(t > motors[i].next) {
                    motors[i].index++;
                    motors[i].next = 1000UL*(pgm_read_dword(motors[i].durations + motors[i].index)); // The next note change moment
                }
                // Starts a new oscillation
                int note = pgm_read_word(motors[i].notes + motors[i].index);
                // Starts the oscillation if the note is not 0
                if(note) {
                    motors[i].stepHigh = true;
                    digitalWrite(motors[i].stepPin, HIGH);
                }
                // Makes the fake oscillation last 1 ms if the note is 0
                else 
                    note = 1000;  
                motors[i].current += note; // note - 100 - (overtime on last oscillation)
            }
        }
    }
}

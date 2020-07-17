import React from 'react';
import KTrack from "./KTrack";
import {Grid, Button} from "@material-ui/core";
import makeStyles from "@material-ui/core/styles/makeStyles";
import { playMelody, stopMelody } from "../../MelodyPlayer";

export default function KInstrumentsPage() {

    const classes = useStyles();
    const [playingMelodyB, setPlayingMelodyB] = React.useState(false);
    const [playingMelodyM, setPlayingMelodyM] = React.useState(false);

    const tracks = [
        {name:"Track0",lowest:55,highest:82,notes:[{start:0,end:290,pitch:62},{start:300,end:440,pitch:62},{start:450,end:740,pitch:62},{start:750,end:890,pitch:62},{start:900,end:1190,pitch:62},{start:1200,end:1340,pitch:62},{start:1350,end:1490,pitch:62},{start:1500,end:1640,pitch:62},{start:1650,end:1790,pitch:62},{start:1800,end:2090,pitch:62},{start:2100,end:2240,pitch:62},{start:2250,end:2540,pitch:62},{start:2550,end:2690,pitch:62},{start:2700,end:2990,pitch:62},{start:3000,end:3140,pitch:62},{start:3150,end:3290,pitch:62},{start:3300,end:3440,pitch:62},{start:3450,end:3590,pitch:62},{start:3600,end:3890,pitch:62},{start:3900,end:4040,pitch:62},{start:4050,end:4340,pitch:62},{start:4350,end:4490,pitch:62},{start:4500,end:4790,pitch:62},{start:4800,end:4940,pitch:62},{start:4950,end:5100,pitch:62},{start:5100,end:5250,pitch:57},{start:5250,end:5400,pitch:60},{start:5400,end:5690,pitch:62},{start:5700,end:5990,pitch:62},{start:6000,end:6150,pitch:62},{start:6150,end:6300,pitch:57},{start:6300,end:6590,pitch:58},{start:6600,end:6890,pitch:58},{start:6900,end:7050,pitch:58},{start:7050,end:7200,pitch:67},{start:7200,end:7490,pitch:57},{start:7500,end:7800,pitch:57},{start:7800,end:7950,pitch:62},{start:7950,end:8100,pitch:60},{start:8100,end:8250,pitch:57},{start:8250,end:8550,pitch:62},{start:8700,end:8850,pitch:57},{start:8850,end:9000,pitch:60},{start:9000,end:9290,pitch:58},{start:9300,end:9590,pitch:58},{start:9600,end:9750,pitch:58},{start:9750,end:9900,pitch:64},{start:9900,end:10190,pitch:65},{start:10200,end:10490,pitch:65},{start:10500,end:10650,pitch:65},{start:10650,end:10800,pitch:60},{start:10800,end:11090,pitch:57},{start:11100,end:11400,pitch:57},{start:11400,end:11550,pitch:62},{start:11550,end:11700,pitch:60},{start:11700,end:12000,pitch:62},{start:12300,end:12450,pitch:57},{start:12450,end:12600,pitch:60},{start:12600,end:12890,pitch:62},{start:12900,end:13190,pitch:62},{start:13200,end:13350,pitch:62},{start:13350,end:13500,pitch:65},{start:13500,end:13790,pitch:67},{start:13800,end:14090,pitch:67},{start:14100,end:14250,pitch:67},{start:14250,end:14400,pitch:62},{start:14400,end:14690,pitch:67},{start:14700,end:15000,pitch:67},{start:15000,end:15150,pitch:65},{start:15150,end:15300,pitch:64},{start:15300,end:15447,pitch:65},{start:15450,end:15740,pitch:62},{start:15900,end:16050,pitch:62},{start:16050,end:16200,pitch:64},{start:16200,end:16490,pitch:58},{start:16500,end:16800,pitch:58},{start:16800,end:17100,pitch:67},{start:17100,end:17250,pitch:65},{start:17250,end:17540,pitch:62},{start:17700,end:17850,pitch:62},{start:17850,end:18000,pitch:65},{start:18000,end:18290,pitch:57},{start:18300,end:18600,pitch:57},{start:18600,end:18750,pitch:62},{start:18750,end:18900,pitch:59},{start:18900,end:19350,pitch:57},{start:19500,end:19650,pitch:69},{start:19650,end:19800,pitch:72},{start:19800,end:20090,pitch:74},{start:20100,end:20390,pitch:74},{start:20400,end:20550,pitch:74},{start:20550,end:20700,pitch:69},{start:20700,end:20990,pitch:70},{start:21000,end:21290,pitch:70},{start:21300,end:21450,pitch:70},{start:21450,end:21600,pitch:79},{start:21600,end:21890,pitch:69},{start:21900,end:22200,pitch:69},{start:22200,end:22350,pitch:74},{start:22350,end:22500,pitch:72},{start:22500,end:22647,pitch:69},{start:22650,end:22900,pitch:74},{start:23100,end:23250,pitch:69},{start:23250,end:23400,pitch:72},{start:23400,end:23690,pitch:70},{start:23700,end:23990,pitch:70},{start:24000,end:24150,pitch:70},{start:24150,end:24300,pitch:76},{start:24300,end:24590,pitch:77},{start:24600,end:24890,pitch:77},{start:24900,end:25050,pitch:77},{start:25050,end:25190,pitch:72},{start:25200,end:25490,pitch:72},{start:25500,end:25800,pitch:72},{start:25800,end:25950,pitch:74},{start:25950,end:26100,pitch:72},{start:26100,end:26400,pitch:74},{start:26700,end:26850,pitch:69},{start:26850,end:27000,pitch:72},{start:27000,end:27290,pitch:74},{start:27300,end:27590,pitch:74},{start:27600,end:27750,pitch:74},{start:27750,end:27900,pitch:77},{start:27900,end:28190,pitch:79},{start:28200,end:28490,pitch:79},{start:28500,end:28650,pitch:79},{start:28650,end:28800,pitch:74},{start:28800,end:29090,pitch:79},{start:29100,end:29400,pitch:79},{start:29400,end:29550,pitch:77},{start:29550,end:29700,pitch:76},{start:29700,end:29850,pitch:77},{start:29850,end:30140,pitch:74},{start:30300,end:30450,pitch:74},{start:30450,end:30600,pitch:76},{start:30600,end:30890,pitch:70},{start:30900,end:31200,pitch:70},{start:31200,end:31500,pitch:79},{start:31500,end:31650,pitch:77},{start:31650,end:31940,pitch:74},{start:32100,end:32250,pitch:74},{start:32250,end:32400,pitch:77},{start:32400,end:32690,pitch:69},{start:32700,end:33000,pitch:69},{start:33000,end:33150,pitch:74},{start:33150,end:33300,pitch:73},{start:33300,end:33590,pitch:74},{start:33600,end:33900,pitch:74},{start:33900,end:34200,pitch:69},{start:34200,end:34500,pitch:74},{start:34500,end:34640,pitch:77},{start:34650,end:34800,pitch:77},{start:34800,end:35100,pitch:79},{start:35100,end:35250,pitch:74},{start:35250,end:35390,pitch:77},{start:35700,end:35850,pitch:77},{start:35850,end:36000,pitch:74},{start:36000,end:36150,pitch:69},{start:36900,end:37040,pitch:79},{start:37500,end:37650,pitch:79},{start:37650,end:37790,pitch:70},{start:37800,end:37950,pitch:70},{start:38700,end:38837,pitch:61},{start:38850,end:39100,pitch:61},{start:39150,end:39550,pitch:55},{start:39600,end:40000,pitch:57},{start:40200,end:40347,pitch:65},{start:40350,end:40497,pitch:67},{start:40500,end:40740,pitch:62},{start:40800,end:41040,pitch:62},{start:41100,end:41350,pitch:62},{start:41400,end:41547,pitch:70},{start:41550,end:41697,pitch:62},{start:42300,end:42540,pitch:60},{start:42600,end:42840,pitch:60},{start:42900,end:43140,pitch:60},{start:43200,end:43347,pitch:60},{start:43350,end:43497,pitch:65},{start:44100,end:44340,pitch:62},{start:44400,end:44640,pitch:62},{start:44700,end:44950,pitch:62},{start:45000,end:45147,pitch:70},{start:45150,end:45297,pitch:62},{start:45900,end:46140,pitch:61},{start:46200,end:46450,pitch:61},{start:46500,end:46750,pitch:57},{start:46800,end:47040,pitch:62},{start:47400,end:47547,pitch:62},{start:47550,end:47697,pitch:64},{start:47700,end:48225,pitch:62},{start:48300,end:48447,pitch:67},{start:48450,end:48597,pitch:69},{start:48600,end:48850,pitch:60},{start:48900,end:49150,pitch:65},{start:49200,end:49450,pitch:60},{start:49500,end:49750,pitch:65},{start:49800,end:50040,pitch:57},{start:50100,end:50350,pitch:57},{start:50400,end:50650,pitch:60},{start:51000,end:51147,pitch:65},{start:51150,end:51297,pitch:67},{start:51300,end:51550,pitch:65},{start:51900,end:52047,pitch:67},{start:52050,end:52197,pitch:65},{start:52200,end:52440,pitch:61},{start:52500,end:52740,pitch:61},{start:52800,end:53050,pitch:61},{start:53100,end:53350,pitch:62},{start:53700,end:53847,pitch:64},{start:53850,end:53997,pitch:60},{start:54000,end:54147,pitch:62},{start:54600,end:54747,pitch:74},{start:54750,end:54897,pitch:76},{start:54900,end:55150,pitch:74},{start:55500,end:55647,pitch:76},{start:55650,end:55797,pitch:77},{start:55800,end:56050,pitch:72},{start:56100,end:56350,pitch:77},{start:56400,end:56650,pitch:72},{start:56700,end:56950,pitch:77},{start:57000,end:57250,pitch:72},{start:57300,end:57550,pitch:77},{start:57600,end:57850,pitch:70},{start:58200,end:58347,pitch:74},{start:58350,end:58497,pitch:76},{start:58500,end:58750,pitch:74},{start:58800,end:59050,pitch:79},{start:59100,end:59350,pitch:74},{start:59400,end:59640,pitch:70},{start:59700,end:59950,pitch:70},{start:60000,end:60250,pitch:79},{start:60300,end:60550,pitch:77},{start:60900,end:61047,pitch:79},{start:61050,end:61197,pitch:76},{start:61200,end:61450,pitch:74},{start:61800,end:61947,pitch:76},{start:61950,end:62097,pitch:73},{start:62100,end:62350,pitch:74},{start:63000,end:63250,pitch:79},{start:63900,end:64140,pitch:77},{start:64200,end:64440,pitch:77},{start:64500,end:64750,pitch:77},{start:64800,end:64947,pitch:81},{start:64950,end:65087,pitch:79},{start:65700,end:65950,pitch:79},{start:66600,end:66850,pitch:74},{start:67500,end:67750,pitch:77},{start:67800,end:68040,pitch:69},{start:68100,end:68350,pitch:69},{start:68400,end:68790,pitch:74},{start:68850,end:68997,pitch:74},{start:69000,end:69147,pitch:76},{start:69150,end:69297,pitch:77},{start:69300,end:69690,pitch:74},{start:69750,end:69897,pitch:74},{start:69900,end:70047,pitch:76},{start:70050,end:70197,pitch:77},{start:70200,end:70600,pitch:82},{start:70650,end:70797,pitch:74},{start:70800,end:70947,pitch:76},{start:70950,end:71087,pitch:77},{start:71100,end:71340,pitch:77},{start:71400,end:71640,pitch:77},{start:71700,end:71950,pitch:77},{start:72000,end:72147,pitch:81},{start:72150,end:72287,pitch:79},{start:72900,end:73150,pitch:79},{start:73800,end:74050,pitch:74},{start:74700,end:74950,pitch:77},{start:75000,end:75240,pitch:69},{start:75300,end:75550,pitch:69},{start:75600,end:76000,pitch:74},{start:76500,end:77625,pitch:62},]},
        {name:"Track1",lowest:53,highest:84,notes:[{start:5400,end:5690,pitch:53},{start:5700,end:5990,pitch:53},{start:6000,end:6150,pitch:53},{start:6150,end:6300,pitch:60},{start:6300,end:6590,pitch:62},{start:6600,end:6890,pitch:62},{start:6900,end:7040,pitch:62},{start:7050,end:7200,pitch:62},{start:7200,end:7490,pitch:60},{start:7500,end:7800,pitch:60},{start:7800,end:7950,pitch:57},{start:7950,end:8100,pitch:55},{start:8100,end:8250,pitch:60},{start:8250,end:8550,pitch:57},{start:9000,end:9290,pitch:53},{start:9300,end:9600,pitch:53},{start:9600,end:9750,pitch:62},{start:9750,end:9900,pitch:58},{start:9900,end:10190,pitch:57},{start:10200,end:10500,pitch:57},{start:10500,end:10650,pitch:60},{start:10650,end:10800,pitch:67},{start:10800,end:11090,pitch:60},{start:11100,end:11400,pitch:60},{start:11400,end:11550,pitch:57},{start:11550,end:11700,pitch:55},{start:11700,end:11990,pitch:53},{start:12600,end:12890,pitch:53},{start:12900,end:13200,pitch:53},{start:13200,end:13340,pitch:57},{start:13350,end:13500,pitch:57},{start:13500,end:13790,pitch:58},{start:13800,end:14100,pitch:58},{start:14100,end:14250,pitch:62},{start:14250,end:14400,pitch:69},{start:14400,end:14690,pitch:62},{start:14700,end:15000,pitch:62},{start:15000,end:15150,pitch:69},{start:15150,end:15300,pitch:67},{start:15300,end:15447,pitch:69},{start:16200,end:16490,pitch:62},{start:16500,end:16800,pitch:62},{start:16800,end:17100,pitch:58},{start:17100,end:17250,pitch:69},{start:18000,end:18290,pitch:61},{start:18300,end:18600,pitch:61},{start:18600,end:18750,pitch:65},{start:18750,end:18900,pitch:62},{start:18900,end:19350,pitch:61},{start:19800,end:20090,pitch:65},{start:20100,end:20390,pitch:65},{start:20400,end:20550,pitch:65},{start:20550,end:20700,pitch:72},{start:20700,end:20990,pitch:74},{start:21000,end:21290,pitch:74},{start:21300,end:21440,pitch:74},{start:21450,end:21600,pitch:74},{start:21600,end:21890,pitch:72},{start:21900,end:22200,pitch:72},{start:22200,end:22350,pitch:69},{start:22350,end:22500,pitch:67},{start:22500,end:22647,pitch:72},{start:22650,end:22900,pitch:69},{start:23400,end:23690,pitch:65},{start:23700,end:24000,pitch:65},{start:24000,end:24150,pitch:74},{start:24150,end:24300,pitch:70},{start:24300,end:24590,pitch:69},{start:24600,end:24900,pitch:69},{start:24900,end:25050,pitch:72},{start:25050,end:25200,pitch:79},{start:25200,end:25490,pitch:76},{start:25500,end:25800,pitch:76},{start:25800,end:25950,pitch:69},{start:26100,end:26390,pitch:65},{start:27000,end:27290,pitch:65},{start:27300,end:27600,pitch:65},{start:27600,end:27740,pitch:69},{start:27750,end:27900,pitch:69},{start:27900,end:28190,pitch:70},{start:28200,end:28500,pitch:70},{start:28500,end:28650,pitch:74},{start:28650,end:28800,pitch:81},{start:28800,end:29090,pitch:74},{start:29100,end:29400,pitch:74},{start:29400,end:29550,pitch:81},{start:29550,end:29700,pitch:79},{start:29700,end:29850,pitch:81},{start:30600,end:30890,pitch:74},{start:30900,end:31200,pitch:74},{start:31200,end:31500,pitch:70},{start:31500,end:31650,pitch:81},{start:32400,end:32690,pitch:73},{start:32700,end:33000,pitch:73},{start:33300,end:33590,pitch:69},{start:33600,end:33900,pitch:69},{start:33900,end:34190,pitch:72},{start:34200,end:34500,pitch:72},{start:34800,end:35100,pitch:70},{start:35100,end:35250,pitch:81},{start:35700,end:35840,pitch:69},{start:35850,end:36000,pitch:69},{start:36900,end:37050,pitch:74},{start:37500,end:37650,pitch:70},{start:37650,end:37800,pitch:74},{start:38700,end:38837,pitch:64},{start:38850,end:39100,pitch:64},{start:39150,end:39550,pitch:62},{start:39600,end:40000,pitch:61},{start:40500,end:40740,pitch:65},{start:40800,end:41040,pitch:65},{start:41100,end:41350,pitch:65},{start:41400,end:41547,pitch:62},{start:41550,end:41697,pitch:65},{start:42300,end:42540,pitch:64},{start:42600,end:42840,pitch:64},{start:42900,end:43140,pitch:64},{start:43200,end:43347,pitch:64},{start:43350,end:43497,pitch:60},{start:44100,end:44340,pitch:65},{start:44400,end:44640,pitch:65},{start:44700,end:44950,pitch:65},{start:45000,end:45147,pitch:62},{start:45150,end:45297,pitch:65},{start:45900,end:46150,pitch:64},{start:46200,end:46450,pitch:65},{start:46500,end:46750,pitch:64},{start:46800,end:47050,pitch:53},{start:47700,end:48225,pitch:57},{start:48600,end:48850,pitch:67},{start:48900,end:49150,pitch:60},{start:49200,end:49450,pitch:64},{start:49500,end:49750,pitch:57},{start:49800,end:50040,pitch:60},{start:50100,end:50350,pitch:60},{start:50400,end:50650,pitch:64},{start:51300,end:51550,pitch:60},{start:52200,end:52450,pitch:64},{start:52500,end:52750,pitch:65},{start:52800,end:53050,pitch:64},{start:53100,end:53340,pitch:53},{start:54000,end:54147,pitch:53},{start:54900,end:55150,pitch:69},{start:55800,end:56050,pitch:79},{start:56100,end:56350,pitch:72},{start:56400,end:56650,pitch:79},{start:56700,end:56950,pitch:81},{start:57000,end:57250,pitch:79},{start:57300,end:57550,pitch:72},{start:57600,end:57850,pitch:65},{start:58500,end:58740,pitch:69},{start:58800,end:59050,pitch:69},{start:59100,end:59350,pitch:81},{start:59400,end:59640,pitch:74},{start:59700,end:59950,pitch:74},{start:60000,end:60250,pitch:70},{start:60300,end:60540,pitch:69},{start:61200,end:61450,pitch:69},{start:62100,end:62350,pitch:77},{start:63000,end:63250,pitch:74},{start:63900,end:64140,pitch:72},{start:64200,end:64440,pitch:72},{start:64500,end:64740,pitch:72},{start:64800,end:64947,pitch:72},{start:65700,end:65950,pitch:70},{start:66600,end:66840,pitch:69},{start:67500,end:67750,pitch:69},{start:67800,end:68050,pitch:79},{start:68100,end:68350,pitch:76},{start:68400,end:68800,pitch:65},{start:69300,end:69700,pitch:77},{start:70200,end:70600,pitch:74},{start:71100,end:71340,pitch:72},{start:71400,end:71650,pitch:72},{start:71700,end:71950,pitch:84},{start:72000,end:72147,pitch:72},{start:72900,end:73150,pitch:70},{start:73800,end:74040,pitch:69},{start:74700,end:74950,pitch:69},{start:75000,end:75250,pitch:79},{start:75300,end:75550,pitch:76},{start:75600,end:76000,pitch:65},]},
        {name:"Track2",lowest:57,highest:82,notes:[{start:5400,end:5690,pitch:57},{start:5700,end:5990,pitch:57},{start:6000,end:6150,pitch:57},{start:6150,end:6300,pitch:64},{start:6300,end:6590,pitch:65},{start:6600,end:6890,pitch:65},{start:6900,end:7050,pitch:65},{start:7200,end:7490,pitch:64},{start:7500,end:7800,pitch:64},{start:9000,end:9290,pitch:62},{start:9300,end:9600,pitch:62},{start:9900,end:10190,pitch:60},{start:10200,end:10500,pitch:60},{start:10800,end:11090,pitch:64},{start:11100,end:11400,pitch:64},{start:11700,end:11990,pitch:57},{start:12600,end:12890,pitch:57},{start:12900,end:13200,pitch:57},{start:13500,end:13790,pitch:62},{start:13800,end:14100,pitch:62},{start:14400,end:14690,pitch:70},{start:14700,end:15000,pitch:70},{start:16200,end:16490,pitch:65},{start:16500,end:16800,pitch:65},{start:16800,end:17100,pitch:62},{start:18000,end:18290,pitch:64},{start:18300,end:18590,pitch:64},{start:18900,end:19350,pitch:64},{start:19800,end:20090,pitch:69},{start:20100,end:20390,pitch:69},{start:20400,end:20550,pitch:69},{start:20550,end:20700,pitch:76},{start:20700,end:20990,pitch:77},{start:21000,end:21290,pitch:77},{start:21300,end:21450,pitch:77},{start:21600,end:21890,pitch:76},{start:21900,end:22200,pitch:76},{start:23400,end:23690,pitch:74},{start:23700,end:24000,pitch:74},{start:24300,end:24590,pitch:72},{start:24600,end:24900,pitch:72},{start:26100,end:26390,pitch:69},{start:27000,end:27290,pitch:69},{start:27300,end:27600,pitch:69},{start:27900,end:28190,pitch:74},{start:28200,end:28500,pitch:74},{start:28800,end:29090,pitch:82},{start:29100,end:29400,pitch:82},{start:30600,end:30890,pitch:77},{start:30900,end:31200,pitch:77},{start:31200,end:31500,pitch:74},{start:32400,end:32690,pitch:76},{start:32700,end:32990,pitch:76},{start:33900,end:34200,pitch:76},{start:34200,end:34500,pitch:77},{start:34800,end:35100,pitch:74},{start:36900,end:37050,pitch:82},{start:39600,end:40000,pitch:65},{start:40500,end:40740,pitch:69},{start:40800,end:41040,pitch:69},{start:41100,end:41350,pitch:69},{start:41400,end:41547,pitch:65},{start:41550,end:41697,pitch:69},{start:42300,end:42540,pitch:67},{start:42600,end:42840,pitch:67},{start:42900,end:43140,pitch:67},{start:43200,end:43347,pitch:67},{start:43350,end:43487,pitch:69},{start:44100,end:44340,pitch:69},{start:44400,end:44640,pitch:69},{start:44700,end:44950,pitch:69},{start:45000,end:45147,pitch:65},{start:45150,end:45297,pitch:69},{start:45900,end:46150,pitch:67},{start:46800,end:47050,pitch:57},{start:47700,end:48225,pitch:65},{start:49500,end:49750,pitch:60},{start:49800,end:50050,pitch:67},{start:50100,end:50350,pitch:69},{start:50400,end:50650,pitch:67},{start:51300,end:51550,pitch:69},{start:53100,end:53340,pitch:57},{start:54000,end:54147,pitch:57},{start:54900,end:55150,pitch:77},{start:57600,end:57850,pitch:74},{start:58500,end:58750,pitch:77},{start:58800,end:59050,pitch:74},{start:59400,end:59650,pitch:82},{start:62100,end:62350,pitch:81},{start:63000,end:63250,pitch:82},{start:63900,end:64140,pitch:81},{start:64200,end:64440,pitch:81},{start:64500,end:64750,pitch:81},{start:64800,end:64947,pitch:76},{start:65700,end:65950,pitch:74},{start:66600,end:66850,pitch:77},{start:68400,end:68800,pitch:69},{start:69300,end:69700,pitch:81},{start:70200,end:70600,pitch:77},{start:71100,end:71340,pitch:81},{start:71400,end:71650,pitch:81},{start:72000,end:72147,pitch:76},{start:72900,end:73150,pitch:74},{start:73800,end:74050,pitch:77},{start:75600,end:76000,pitch:69},]},
    ];
    const totallength = 77625;

    const instruments = [
        {name:'Stepper1', warnings:[{track:'Track1', message:'Must go up one octave'}, {track:'Track2', message:'Must go up one octave'}], errors: []},
        {name:'Stepper2', warnings:[{track:'Track0', message:'Must go up two octaves'}], errors: []},
        {name:'Stepper3', warnings:[], errors: []},
        {name:'Whistle', warnings:[], errors: [{track:'Track0', message:'Too fast'}]},
        {name:'Drum', warnings:[{track:'Track1', message:'Must go up one octave'}], errors: [{track:'Track0', message:'Loss of notes'}]},
        {name:'Tesla', warnings:[], errors: []},
        {name:'Harp', warnings:[], errors: []},
    ];

    // Filters the errors and warnings for a particular track
    const instrumentsForTrack = (track) => {
        return instruments.map(inst => ({
            name: inst.name,
            warnings: inst.warnings.filter(w => w.track === track).map(w => w.message),
            errors: inst.errors.filter(e => e.track === track).map(e => e.message)
        }));
    };

    let selectedInstruments = [];
    for(let i=0; i < tracks.length; i++)
        // eslint-disable-next-line react-hooks/rules-of-hooks
        selectedInstruments.push(React.useState([]));
    /* When filled: [
           [[inst0, inst1], setInstrumentsTrack0],
           [[inst5], setInstrumentsTrack1],
           [[inst3], setInstrumentsTrack2]
       ]
    */

    let selectedTracks = [];
    for(let i = 0; i < tracks.length; i++)
        // eslint-disable-next-line react-hooks/rules-of-hooks
        selectedTracks.push(React.useState(false));
    /* When filled: [
           [selectedTrack0, setSelectedTrack0],
           [selectedTrack1, setSelectedTrack1],
           [selectedTrack2, setSelectedTrack2]
       ]
    */

    const handlePlayBrowser = () => {
        if(! playingMelodyB) {
            let notes = [];
            for(let i = 0; i < tracks.length; i++) {
                if(selectedTracks[i][0])
                    notes = notes.concat(tracks[i].notes);
            }
            setPlayingMelodyB(true);
            playMelody(notes)
                .then((forced) => {
                    if(!forced) setPlayingMelodyB(false)
                });
        }
        else {
            stopMelody();
            setPlayingMelodyB(false);
        }
    }

    const handlePlayMusicbox = () => {

        setPlayingMelodyM( ! playingMelodyM);
    }

    return (
        <>
            <Grid
                container
                direction='row'
                justify='space-between'
                alignItems='center'
                className={classes.topToolbar}
            >
                <Grid item xs={4}>
                    <Grid
                        container
                        alignItems='center'
                        justify='space-evenly'
                    >
                        <Grid item>
                            <Button
                                className={classes.topToolbarButton}
                                onClick={()=>{ for(let t of selectedTracks) t[1](true) }}
                            >
                                Select all
                            </Button>
                        </Grid>
                        <Grid item>
                            <Button
                                className={classes.topToolbarButton}
                                onClick={()=>{ for(let t of selectedTracks) t[1](false) }}
                            >
                                Deselect all
                            </Button>
                        </Grid>
                    </Grid>
                </Grid>
                <Grid item xs={4}>
                    <Grid
                        container
                        alignItems='center'
                        justify='space-evenly'
                    >
                        <Grid item>
                            <Button className={classes.topToolbarButton} onClick={handlePlayBrowser}>
                                {playingMelodyB ? 'Stop playing' : 'Play on browser'}
                            </Button>
                        </Grid>
                        <Grid item>
                            <Button className={classes.topToolbarButton} onClick={handlePlayMusicbox}>
                                {playingMelodyM ? 'Stop playing' : 'Play on music box'}
                            </Button>
                        </Grid>
                    </Grid>
                </Grid>
            </Grid>
            <Grid
                container
                alignItems='stretch'
                direction='column'
                className={classes.trackslist}
            >
                {tracks.map((track, index) =>
                    <Grid item xs={12} className={classes.track}>
                        <KTrack
                            track={track}
                            totallength={totallength}
                            instruments={instrumentsForTrack(track.name)}
                            selectedInstruments={selectedInstruments[index][0]}
                            setSelectedInstruments={selectedInstruments[index][1]}
                            selected={selectedTracks[index][0]}
                            setSelected={selectedTracks[index][1]}
                        />
                    </Grid>
                )}
            </Grid>
        </>
    );
}

const useStyles = makeStyles(theme => ({
    trackslist: {
        backgroundColor: theme.palette.background.borders,
        padding: theme.spacing(1),
    },
    track: {
        marginBottom: theme.spacing(2),
    },
    topToolbar: {
        backgroundColor: theme.palette.primary.light,
    },
    topToolbarButton: {
        backgroundColor: theme.palette.secondary.main,
        color: theme.palette.text.dark,
        borderColor: theme.palette.background.borders,
    }
}));
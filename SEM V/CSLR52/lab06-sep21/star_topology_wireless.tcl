#initialize the variables
set val(chan)           Channel/WirelessChannel    ;#Channel Type
set val(prop)           Propagation/TwoRayGround   ;# radio-propagation model
set val(netif)          Phy/WirelessPhy            ;# network interface type WAVELAN DSSS 2.4GHz
set val(mac)            Mac/802_11                 ;# MAC type
set val(ifq)            Queue/DropTail/PriQueue    ;# interface queue type
set val(ll)             LL                         ;# link layer type
set val(ant)            Antenna/OmniAntenna        ;# antenna model
set val(ifqlen)         50                         ;# max packet in ifq
set val(nn)             6                          ;# number of  
set val(rp)             AODV                       ;# routing protocol
set val(x)  500   ;# in metres
set val(y)  500   ;# in metres
#Adhoc OnDemand Distance Vector

#creation of Simulator
set ns [new Simulator]

#creation of Trace and namfile
set tracefile [open out.tr w]
$ns trace-all $tracefile
set namfile [open out.nam w]
$ns namtrace-all-wireless $namfile $val(x) $val(y)

#create topography
set topo [new Topography]
$topo load_flatgrid $val(x) $val(y)

#GOD Creation - General Operations Director
create-god $val(nn)

set channel1 [new $val(chan)]

#configure the node
$ns node-config -adhocRouting $val(rp) \
   -llType $val(ll) \
   -macType $val(mac) \
   -ifqType $val(ifq) \
   -ifqLen $val(ifqlen) \
   -antType $val(ant) \
   -propType $val(prop) \
   -phyType $val(netif) \
   -topoInstance $topo \
   -agentTrace ON \
   -macTrace ON \
   -routerTrace ON \
   -movementTrace ON \
   -channel $channel1

set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]


$n0 random-motion 0
$n1 random-motion 0
$n2 random-motion 0
$n3 random-motion 0
$n4 random-motion 0
$n5 random-motion 0


#initial coordinates of the nodes
$n0 set X_ 400.0
$n0 set Y_ 250.0
$n0 set Z_ 0.0

$n1 set X_ 0.0
$n1 set Y_ 100.0
$n1 set Z_ 0.0

$n2 set X_ 0.0
$n2 set Y_ 400.0
$n2 set Z_ 0.0

$n3 set X_ 150.0
$n3 set Y_ 250.0
$n3 set Z_ 0.0

$n4 set X_ 200.0
$n4 set Y_ 400.0
$n4 set Z_ 0.0

$n5 set X_ 200.0
$n5 set Y_ 100.0
$n5 set Z_ 0.0

$ns initial_node_pos $n0 20
$ns initial_node_pos $n1 20
$ns initial_node_pos $n2 20
$ns initial_node_pos $n3 50
$ns initial_node_pos $n4 20
$ns initial_node_pos $n5 20
#Dont mention any values above than 500 because in this example, we use X and Y as 500,500

# #mobility of the nodes
# #At what Time? Which node? Where to? at What Speed?
# $ns at 1.0 "$n1 setdest 490.0 340.0 25.0"
# $ns at 1.0 "$n4 setdest 300.0 130.0 5.0"
# $ns at 1.0 "$n5 setdest 190.0 440.0 15.0"
# #the nodes can move any number of times at any location during the  
# simulation (runtime)
# $ns at 20.0 "$n5 setdest 100.0 200.0 30.0"

#creation of agents
set tcp1 [new Agent/TCP]
set sink1 [new Agent/TCPSink]
$ns attach-agent $n0 $tcp1
$ns attach-agent $n3 $sink1
$ns connect $tcp1 $sink1
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1
$ns at 1.0 "$ftp1 start"
$ns at 2.0 "$ftp1 stop"

set tcp2 [new Agent/TCP]
set sink2 [new Agent/TCPSink]
$ns attach-agent $n0 $tcp2
$ns attach-agent $n1 $sink2
$ns connect $tcp2 $sink2
set ftp2 [new Application/FTP]
$ftp2 attach-agent $tcp2
$ns at 2.1 "$ftp2 start"
$ns at 3.0 "$ftp2 stop"

$ns at 10.0 "finish"

proc finish {} {
  global ns tracefile namfile
  $ns flush-trace
  close $tracefile
  close $namfile
  exec nam out.nam & 
  exit 0
}

puts "Starting Simulation"
$ns run
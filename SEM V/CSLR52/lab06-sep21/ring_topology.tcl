#Create a simulator object
set ns [new Simulator]

#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red
$ns color 3 Green
$ns color 4 Orange
$ns color 5 Purple

#Open the nam trace file
set nf [open out.nam w]
$ns namtrace-all $nf

#Define a 'finish' procedure
proc finish {} {
    global ns nf
    $ns flush-trace
    #Close the trace file
    close $nf
    #Executenam on the trace file
    exec nam out.nam &
    exit 0
}

#Create six nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

#Create links between the nodes
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
$ns duplex-link $n1 $n2 1Mb 10ms DropTail
$ns duplex-link $n2 $n3 1Mb 10ms DropTail
$ns duplex-link $n3 $n4 1Mb 10ms DropTail
$ns duplex-link $n4 $n0 1Mb 10ms DropTail

#Create a TCP agent and attach it to all nodes
set tcp0 [new Agent/TCP]
$tcp0 set class_ 1
$ns attach-agent $n0 $tcp0

set tcp1 [new Agent/TCP]
$tcp1 set class_ 1
$ns attach-agent $n1 $tcp1

set tcp2 [new Agent/TCP]
$tcp2 set class_ 1
$ns attach-agent $n2 $tcp2

set tcp3 [new Agent/TCP]
$tcp3 set class_ 1
$ns attach-agent $n3 $tcp3

set tcp4 [new Agent/TCP]
$tcp4 set class_ 1
$ns attach-agent $n4 $tcp4

#Create a TCP Sink agent (a traffic sink) for TCP and attach it to node n3
set sink0 [new Agent/TCPSink]
$ns attach-agent $n0 $sink0

set sink1 [new Agent/TCPSink]
$ns attach-agent $n1 $sink1

set sink2 [new Agent/TCPSink]
$ns attach-agent $n2 $sink2

set sink3 [new Agent/TCPSink]
$ns attach-agent $n3 $sink3

set sink4 [new Agent/TCPSink]
$ns attach-agent $n4 $sink4

#Connect the traffic sources with the traffic sink
$ns connect $tcp0 $sink1
$tcp0 set fid_ 1

$ns connect $tcp1 $sink2
$tcp1 set fid_ 2

$ns connect $tcp2 $sink3
$tcp2 set fid_ 3

$ns connect $tcp3 $sink4
$tcp3 set fid_ 4

$ns connect $tcp4 $sink0
$tcp4 set fid_ 5

# Create a CBR traffic source and attach it to tcp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.01
$cbr0 attach-agent $tcp0

set cbr1 [new Application/Traffic/CBR]
$cbr1 set packetSize_ 500
$cbr1 set interval_ 0.02
$cbr1 attach-agent $tcp1

set cbr2 [new Application/Traffic/CBR]
$cbr2 set packetSize_ 500
$cbr2 set interval_ 0.03
$cbr2 attach-agent $tcp2

set cbr3 [new Application/Traffic/CBR]
$cbr3 set packetSize_ 500
$cbr3 set interval_ 0.05
$cbr3 attach-agent $tcp3

set cbr4 [new Application/Traffic/CBR]
$cbr4 set packetSize_ 500
$cbr4 set interval_ 0.07
$cbr4 attach-agent $tcp4

#Schedule events for the CBR agents
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

$ns at 0.5 "$cbr1 start"
$ns at 4.5 "$cbr1 stop"

$ns at 0.5 "$cbr2 start"
$ns at 4.5 "$cbr2 stop"

$ns at 0.5 "$cbr3 start"
$ns at 4.5 "$cbr3 stop"

$ns at 0.5 "$cbr4 start"
$ns at 4.5 "$cbr4 stop"

#Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

#Run the simulation
$ns run
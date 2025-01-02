my $n = <>;
$_ = <>; my @A = split;
if(int($n) % 7 == 0){
	$z = -1;
	for($i = 0; $i < int($n); $i += 1){
		if($i % 7 != 6){
			if(($z == -1) || (int($A[$z]) > int($A[$i]))){
				$z = $i;
			}
		}
	}
	print $z + 1;

}else{

$z = 1000000000;
foreach(@A){
	$x = int($_)-1;
	while($x % 6 != 0){
		$x -= 1;
	}
	$z = $x if($x < $z);
}
for($i = 0; $i < $n; $i += 1){
	$A[$i] = int($A[$i]) - $z;
}
$i = -1;
$t = 0;
$g = 1;
while($g != 0){
	$t += 1; $t = 0 if($t == 7);
	$i += 1; $i = 0 if($i == $n);
	if($t != 0){
		$A[$i] -= 1;
		if($A[$i] == 0){
			print $i+1;
			$g = 0;
		}
	}
}

}

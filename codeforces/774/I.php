<?php

$n = intval(fgets(STDIN, 5000));
$s = [];
for($i=0;$i<$n;++$i) {
    $s[]=trim(fgets(STDIN, 5000));
}
$str=trim(fgets(STDIN, 5000));
$len=strlen($str);
$d=[];
$mx = 1000000000;
for($i=0;$i<=$len;++$i) $d[]=$mx;
$d[0]=0;
for($at=0;$at<$len;++$at) {
//		echo $d[$at];
	if($d[$at]!=$mx) {
	//	echo $d[$at];
	    for($i=0;$i<$n;++$i) {
	        $to=$at;
	        $slen = strlen($s[$i]);
	        for($j=0;$j<$slen;++$j) {
	            if($to<$len&&$str[$to]==$s[$i][$j]) ++$to;
	        }
	        if($d[$at]+1<$d[$to]) $d[$to]=$d[$at]+1;
	    }
	}
}
echo ($d[$len]==$mx?-1:$d[$len]);

  
?>
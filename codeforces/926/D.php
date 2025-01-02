<?php
    $fl = STDIN;
    $a = array(6);
    for($i = 0; $i < 6; ++$i)
    	fscanf($fl, "%s", $a[$i]);
    
    $pri = array(3, 4, 0, 1, 6, 7);
    
    $flag = true;
    for($i = 0; $flag && $i < 3; ++$i) {
        for($j = 0; $flag && $j < 6; ++$j) {
            for($k = 0; $flag && $k < 2; ++$k) {
                if($a[$i * 2 + $k][$pri[$j]] == '.') {
                    $a[$i * 2 + $k][$pri[$j]] = 'P';
                    $flag = false;
                }    
            }
        }
    }
    
    for($i = 0; $i < 6; ++$i)
        printf("%s\n", $a[$i]);
?>
<?php 
	fwrite(STDOUT, strtoupper(base_convert(trim(fgets(STDIN)), 8, 16)));
?>

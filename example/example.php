<?php
rs_sig_file('test/test-a.txt', 'test/test-a.sig');
rs_delta_file('test/test-a.sig', 'test/test-b.txt', 'test/test-a.delta');
rs_patch_file('test/test-a.txt', 'test/test-a.delta', 'test/test-a-new.txt');

#Options

is another lightweight library for processing command line arguments. It provides a callback interface and displays usage information. Supports option formats:
* `-a`
* `-abc`
* `-a ARG`
* `-aARG`
* `--alpha`
* `--alpha = ARG`
* `--alpha ARG`
* files processing and `--` token

See *main.c* to understand how to use the library.

Example:
```
options -ha --delta=ARG -z ARG

Option, version 1.00
Synopsis:
	option [OPTIONS] FILES

Options:
-a, --alpha
	Lorem ipsum dolor sit amet, consectetur adipiscing
	elit, sed do eiusmod tempor incididunt ut
	labore et dolore magna aliqua.

--beta
	Lorem ipsum dolor sit amet, consectetur adipiscing
	elit, sed do eiusmod tempor incididunt ut
	labore et dolore magna aliqua.

-g
	Lorem ipsum dolor sit amet, consectetur adipiscing
	elit, sed do eiusmod tempor incididunt ut
	labore et dolore magna aliqua.

-d, --delta ARG
	Lorem ipsum dolor sit amet, consectetur adipiscing
	elit, sed do eiusmod tempor incididunt ut
	labore et dolore magna aliqua.

--epsilon ARG
	Lorem ipsum dolor sit amet, consectetur adipiscing
	elit, sed do eiusmod tempor incididunt ut
	labore et dolore magna aliqua.

-z ARG
	Lorem ipsum dolor sit amet, consectetur adipiscing
	elit, sed do eiusmod tempor incididunt ut
	labore et dolore magna aliqua.

-h, --help
	Print this help

Return values:
4	Description of custom error 2
3	Description of custom error 1
2	Internal error
1	Invalid option
0	No errors, all done

Printitng help... done
Alpha... done
Delta "ARG"... done
Zeta "ARG"... FAILED [Description of custom error 2, 4]
```

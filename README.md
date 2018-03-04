# shunt-yard
This is a program that interactively reads in an artihmetic expression in infix form, and prints the expression converted to postifx form.

Essentially, it's a quick (and dirty) implementation of the shunting yard algorithm.

# Installation
To install, first download:

`git clone https://github.com/GabrielDougherty/shunt-yard.git`

Then build:

`cd shunt-yard`

`make`

And run:

`./shunt_math`

# Expression Grammar
The grammar of the input expression is `expression q`.
Additionally, there must be a space between each operation, variable, number and parentheses.

The input arithmetic expression may contain:

- variables or numbers
- any of the operations among `+-*/^`
- parentheses

# Example Usage
Valid expressions:

`2 * 4 + 3 q`

`( 2 + 3 ^ 7 ) / 2 * 4 q`

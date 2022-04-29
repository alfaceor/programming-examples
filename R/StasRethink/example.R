#/usr/bin/env Rscript
library(ggplot2)
dbinom(6, size=9, prob=0.5)
p_grid <- seq(from=0, to=1, length.out=20)
p_grid
prior <- rep(1, 20)
likelihood <- dbinom(6, size=9, prob=p_grid)
unstd.posterior <- likelihood * prior
posterior <- unstd.posterior / sum(unstd.posterior)
posterior

# p <- ggplot(aes=(x=pgrid, y=posterior)) + geom_point() + geom_line()
qplot(x=p_grid, y=posterior)


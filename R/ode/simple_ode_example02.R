library(ggplot2)
dydt_rhs <- function(t, y, parms){
  if ( t > 4 ){
    dy <- -y  
  }else{
    dy <- -5*y
  }
  list(dy)
}

y_analitc <- function(t){
  if ( t > 4 ){
    y <- exp(-t)
  }else{
    y <- exp(4)*exp(-5*t)
  }

}

times <- seq(0, 10, 0.01)
yini <- c(y=1)
out_sol <- deSolve::ode(func = dydt_rhs, times = times, y = yini,
               parms = NULL) #, method = "impAdams") #,
               #events = list(data = injectevents))

head(out_sol)

p <- ggplot(data = data.frame(out_sol), mapping = aes(time, y))
p <- p + geom_point()
p <- p + geom_function()
p <- p + scale_y_log10()
p

fln_output <- "simple_ode.png"
ggsave(fln_output, plot=p)


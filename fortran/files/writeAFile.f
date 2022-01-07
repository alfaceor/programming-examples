      program writeAFile
      implicit none
      character*18 filename
      real*8 value
      integer i
      filename='arquivo.dat'
      value=2.3
      open(unit=700, file=filename)
      do i=1,10
        write(700, "(A)",advance="no") "text value "
        !write(700, *, advance=no) "",i*value,""
        !write(700, '(a,$)') "",i*value,""
      end do
      close(700)

  800 format (A)
  900 format (A,I2,A,F10.3)
      write (*, 800, advance="no") "0"
      do i=1,5
        write(*, 900, advance="no") " ", i, " ", value
      end do
cccccc 900 format (I2,F10.3)
      end program

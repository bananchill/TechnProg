module global_variable
   use Environment

   implicit none
   real(R_)                   :: m
end module global_variable

program lab_1
   use Environment
   use global_variable
   
   implicit none
   integer, parameter         :: N = 11
   integer                    :: k, i, Out=0
   character(*), parameter    :: output_file = "output.txt"
   real(R_)                   :: x_values(N), y_values(N), res_spline, res_lagrange, xk_values(N-1)
   real(R_)                   :: b(N), c(N), d(N), fun, delta_spline, delta_lagrange
   real(R_)                   :: low = 0.5, high = 1, epsabs = 0.0, epsrel = 1.0e-10, result, epsest, nofun, flag
   real(R_)                   :: m_values(2) = [-1.0, -0.5]

   x_values = [(0.3 * k, k=0,N-1)]
   y_values = [(f(x_values(i)), i=1,N)]

   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "(a)") " yk | function |  Spline  | Lagrange | D Spline |D Lagrange|"
      write (Out, "(a)") "------------------------------------------------------------"
   close (Out)
   
   xk_values = [(0.15 + 0.3 * k, k=0, 9)]
   call spline(N, x_values, y_values, b, c, d)
   do i=1,N-1
      res_spline = seval(N, xk_values(i), x_values, y_values, b, c, d)
      res_lagrange = lagrange(xk_values(i), x_values, y_values, N)
      fun = f(xk_values(i))
      delta_spline = abs(fun - res_spline)
      delta_lagrange = abs(fun - res_lagrange)

      open (file=output_file, encoding=E_, newunit=Out, position="append")
         write (Out, "(f4.2, '|', 5(f10.8, '|'))") xk_values(i), fun, res_spline, res_lagrange, delta_spline, delta_lagrange
      close (Out)
   end do
   
   do i=1,2
      m = m_values(i)
      call quanc8(f_m, low, high, epsabs, epsrel, result, epsest, nofun, flag)
      open (file=output_file, encoding=E_, newunit=Out, position="append")
         write (Out, "(a, f5.2, a, f10.7)") "QUANC8 результат (m = ", m, ") = ", result
      close (Out)
   end do

contains
   include "SEVAL.F"
   real(R_) function f(x)
      real(R_)                :: x

      f = 1 - exp(-x)
   end function f

   real(R_) function f_m(x)
      real(R_)                :: x

      f_m = (abs(sin(x) - 0.6)) ** m
   end function f_m

   real(R_) function lagrange(x, x_values, y_values, N)
      integer                 :: N, i, j
      real(R_)                :: x, x_values(:), y_values(:)
      real(R_)                :: basics_pol, lagrange_pol

      lagrange_pol = 0
      basics_pol = 1
      do i=1,N
         basics_pol = 1
         do j=1,N
            if (j /= i) then
               basics_pol = basics_pol * (x - x_values(j)) / (x_values(i) - x_values(j))
            end if
         end do
         lagrange_pol = lagrange_pol + basics_pol * y_values(i)
      end do
      lagrange = lagrange_pol
   end function lagrange
end program lab_1

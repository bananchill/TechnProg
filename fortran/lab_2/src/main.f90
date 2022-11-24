program lab_2
   use Environment
   
   implicit none
   character(*), parameter             :: output_file = "output.txt"
   integer                             :: Out = 0, i
   integer, parameter                  :: N(3) = [3, 6, 9]
   open (file=output_file, encoding=E_, newunit=Out)
      write (Out, "(a)") "Вычисления:"
   close (Out)
   do i=1,3
      call main(N(i))
   end do
contains
   function generate_matrix(N)
      integer                          :: N, i, k
      real(R_)                         :: B(N, N), generate_matrix(N, N)

      do i=1,N
         do k=1,N
            if (i == k) B(i, k) = 0.01 / ((N - i + k) * (i + 1))
            if (i < k) B(i, k) = 0
            if (i > k) B(i, k) = i * (N - k)
         end do
      end do
      generate_matrix = B
   end function generate_matrix

   function inverse_matrix(B, N)
      integer                          :: N
      real(R_)                         :: inverse_matrix(N, N)
      integer                          :: i, k, tmp(N, N)
      real(R_)                         :: B(N, N), ipvt(N), work(N)
      real(R_)                         :: cond, z(N)

      do i=1,N
         do k=1,N
            tmp(i, k) = merge(1, 0, i == k)
         end do
      end do
      call decomp(N, N, B, cond, ipvt, work)
      
      do k=1,N
         z = tmp(k, :)
         call solve(N, N, B, z, ipvt)
         inverse_matrix(:, k) = z
      end do

      open (file=output_file, encoding=E_, newunit=Out, position="append")
         write (Out, "(a, e15.5)") "cond = ", cond
      close (Out)
   end function inverse_matrix

   real(R_) function norm_r(B, B1, N)
      integer                          :: N, i, j
      real(R_)                         :: B(:, :), B1(:, :), E(N, N), R(N, N)
      
      do i=1,N
         do j=1,N
            E(i, j) = merge(1, 0, i==j)
         end do
      end do

      R = matmul(B, B1) - E
      norm_r = sqrt(sum(R ** 2))
   end function  norm_r


   subroutine print_matrix(B, string)
      character(*)                     :: string
      real(R_)                         :: B(:, :)
      integer                          :: N, i
      
      N = Ubound(B, 1)
      open (file=output_file, encoding=E_, newunit=Out, position="append")
         write (Out, "(a)") string
         write (Out, "("//N//"e15.3)") (B(i, :), i=1,N)
      close (Out)
   end subroutine print_matrix
      
   subroutine main(N)
      integer                          :: N
      real(R_)                         :: B(N, N), B_COPY(N, N) ,B1(N, N)
      
      B = generate_matrix(N)
      B_COPY = B
      call print_matrix(B, "Полученная матрица:")
      B1 = inverse_matrix(B_COPY, N)
      call print_matrix(B1, "Обратная матрица: ")
      open (file=output_file, encoding=E_, newunit=Out, position="append")
         write (Out, "(a, e10.3)") "||R|| = ", norm_r(B, B1, N)
         write (Out, "(a)") "============================================"
      close(Out) 
   end subroutine main
      
end program lab_2

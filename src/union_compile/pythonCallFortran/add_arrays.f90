subroutine add_arrays(array1, array2, result, size) 
  implicit none
  integer, intent(in) :: size
  real, dimension(size), intent(in) :: array1, array2
  real, dimension(size), intent(out) :: result
  integer :: i
  do i = 1, size
    result(i) = array1(i) + array2(i)
  end do
end subroutine add_arrays

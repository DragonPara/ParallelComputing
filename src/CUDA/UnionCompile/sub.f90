subroutine Sub_Fortran(NumInt,NumFloat,NumDouble)
    implicit none
    integer::NumInt
    real::NumFloat ! real==real(4)==real*4
    real(8)::NumDouble
    NumDouble=NumFloat**NumInt
end subroutine

real(8) function Function_Fortran(NumDouble)
    implicit none
    real(8)::NumDouble
    call cudafunction()
    Function_Fortran=sqrt(NumDouble)
end function
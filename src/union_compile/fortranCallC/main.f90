program test
    use iso_c_binding
    use api
    implicit none
    print *,abs_ok(-100)
    print *,fabs_ok(-100.2_8)
end program test
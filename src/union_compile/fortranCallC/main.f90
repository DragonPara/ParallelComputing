program test
    use iso_c_binding
    use api
    implicit none
    print *,abs(-100)
    print *,abs(-100.2_4)
    print *,abs(-100.2_8)
end program test
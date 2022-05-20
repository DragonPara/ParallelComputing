module api
    use iso_c_binding
    implicit none
    interface 
        integer(C_INT) function abs_ok(x) bind(C)
            import C_INT
            integer(C_INT),intent(in),value::x
        end function abs_ok
        real(C_DOUBLE) function fabs_ok(x) bind(C)
            import C_DOUBLE
            real(C_DOUBLE),intent(in),value::x
        end function fabs_ok
    end interface    
end module api
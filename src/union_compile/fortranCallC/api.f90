module api
    use iso_c_binding
    implicit none
    interface abs
        integer(C_INT) function abs_ok(x) bind(C)
            import C_INT
            integer(C_INT),intent(in),value::x
        end function abs_ok
        real(C_FLOAT) function fabs_ok(x) bind(C)
            import C_FLOAT
            real(C_FLOAT),intent(in),value::x
        end function fabs_ok
        real(C_DOUBLE) function lfabs_ok(x) bind(C)
            import C_DOUBLE
            real(C_DOUBLE),intent(in),value::x
        end function lfabs_ok
    end interface    
end module api
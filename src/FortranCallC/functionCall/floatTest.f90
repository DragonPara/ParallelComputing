        program b
        real(4)::x=3.3
		real(4)::xx(10)
		do i=i,10
			xx(i)=i*1.1
		enddo
        call signalFloat(x)
		call arrayFloat(xx)
		print *, "After change via C interface: ",xx(1);
        end program b
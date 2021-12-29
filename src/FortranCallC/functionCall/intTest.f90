        program b
        integer::x=3
		integer::xx(10)
		do i=i,10
			xx(i)=i
		enddo
        call signalInt(x)
		call arrayInt(xx)
		print *, "After change via C interface: ",xx(1);
        end program b
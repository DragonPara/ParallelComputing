        program b
        character::x='a'
        character::xx(10)
		do i=i,10
			xx(i)='a'
		enddo
        call signalChar(x)
		call arrayChar(xx)
		print *, "After change via C interface: ",xx(1);
        end program b
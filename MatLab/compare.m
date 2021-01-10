function same = compare(array, array_length, password, password_length)
    if((array(1:array_length)== password(1:password_length)))
        same=1;
    else
        same=0;
    end
    %same = prod((array(1:array_length)== password(1:password_length)),'all');

end
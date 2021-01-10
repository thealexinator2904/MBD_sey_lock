function same = compare(array, array_length, password, password_length)
    if(array_length == password_length)
        same = prod((array(1:array_length-1)== password(1:password_length-1)),'all');
    else
        same = 0;
    end
    %same = prod((array(1:array_length)== password(1:password_length)),'all');

end
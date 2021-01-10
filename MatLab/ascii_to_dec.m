function dec = ascii_to_dec(ascii_in)

  if ascii_in == 0
    dec = 0;
  else
    dec = uint8(ascii_in - 48);
  end

end



% a = uint8(17)
require 'tk'

root = TkRoot.new { title "Clock" }

time = TkVariable.new

label = TkLabel.new(root) do
  font TkFont.new('Helvetica 80 bold')
  textvariable time
  pack { padx 50 ; pady 50; side 'left' }
end

TkButton.new(root) do
  text 'Quit'
  command { exit }
  pack { padx 50 ; pady 50; side 'right' }
end

TkTimer.new(1000, -1, proc{ time.value = 
Time.now.strftime("%H:%M:%S") }).start(0)

Tk.mainloop()

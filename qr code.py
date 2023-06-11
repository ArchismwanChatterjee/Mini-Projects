# importing the qrcode module using pip install qrcode
import qrcode


val = int(input("Enter your value: "))
print(val)

for i in range(val):
    obj_qr = qrcode.QRCode(
        version=i+1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=5,
        border=0,
    )
    
    if i % 2 == 0:
        obj_qr.add_data("https://www.w3schools.com/default.asp")
    else:
        obj_qr.add_data("https://www.geeksforgeeks.org/")
    
    obj_qr.make(fit=True)
    
    if i % 2 == 0:
        qr_img = obj_qr.make_image(back_color="black", fill_color="cyan")
    else:
        qr_img = obj_qr.make_image(back_color="black", fill_color="white")
    
    qr_img.save("qr-img1.png")
    qr_img.show('qr-img1.png')

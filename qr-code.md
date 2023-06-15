## QR CODE GENERATOR USING PYTHON

1. To run the code we need to install the package first for that we may use pip installer
```bash
$ pip install qrcode
```
2. In the above code the user will be able to generate 'n' qrcodes where n is any number 
3. Here the even qrcodes are generated to [w3schools](https://www.w3schools.com/default.asp) and the odd qrcodees are generated to [GeeksforGeeks](https://www.geeksforgeeks.org/)
4. We can even add our own desired links by just changing the site link here
```python
 obj_qr.add_data("https://www.w3schools.com/default.asp")
 ```
5. We can even optimize the version,border,size of the qrcode
```python
  obj_qr = qrcode.QRCode(
        version=i+1,
        error_correction=qrcode.constants.ERROR_CORRECT_L,
        box_size=5,
        border=0,
    )
```
6. To change the colors of the qr we use 
```python
qr_img = obj_qr.make_image(back_color="black", fill_color="white")
```
## EXAMPLES:

![qr-img1](https://github.com/ArchismwanChatterjee/Mini-Projects/assets/115975340/5002287b-8289-415e-9041-73b766c82ebc) 

![qr-img1](https://github.com/ArchismwanChatterjee/Mini-Projects/assets/115975340/c8347c4b-c77e-4ec7-887b-24f25201e48a)

### USE THIS LINK TO ACCESS THE CODE DIRECTLY
[Qrcode Generator](https://github.com/ArchismwanChatterjee/Mini-Projects/blob/main/qr%20code.py)



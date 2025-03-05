def xor_crypt_alternative2(entrada, senha):
    tam_in = len(entrada)
    tam_senha = len(senha)
    saida = []
    j = 0

    for i in range(tam_in):
        if j == tam_senha:
            j = 0

        bit_entrada = int(entrada[i])
        bit_senha = int(senha[j])

        saida.append(str(bit_entrada ^ bit_senha))
        j += 1

    return ''.join(saida)


def bin_to_hex(binario):
    return ''.join(f'{int(binario[i:i+4], 2):X}' for i in range(0, len(binario), 4))


def hex_to_bin(hexa):
    lookup = {
        '0': '0000', '1': '0001', '2': '0010', '3': '0011',
        '4': '0100', '5': '0101', '6': '0110', '7': '0111',
        '8': '1000', '9': '1001', 'A': '1010', 'B': '1011',
        'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111'
    }
    binario = ''
    for char in hexa:
        if char.upper() in lookup:
            binario += lookup[char.upper()]
        else:
            raise ValueError(f"Caractere hexadecimal inválido: {char}")
    return binario


def string_to_binary(string):
    return ''.join(f'{ord(char):08b}' for char in string)


def binary_to_string(binario):
    caracteres = [binario[i:i+8] for i in range(0, len(binario), 8)]
    return ''.join(chr(int(byte, 2)) for byte in caracteres)


def main():
    while True:
        print("Selecione um modo: 1 - Criptografar; 2 - Descriptografar; 3 - BinToHex Converter; "
              "4 - HexToBin Converter; 5 - Anotar String; 6 - Sair")
        selec = int(input())

        if selec == 1:
            input_str = input("Digite uma string: ")
            password = input("Digite uma senha: ")
            input_bin = string_to_binary(input_str)
            password_bin = string_to_binary(password)
            output_bin = xor_crypt_alternative2(input_bin, password_bin)

            print("---------------------------------------------------")
            print("Binario entrada:")
            print(input_bin)
            print("---------------------------------------------------")
            print("Binario senha:")
            print(password_bin)
            print("---------------------------------------------------")
            print("Saida Xor:")
            print(output_bin)
            print("---------------------------------------------------")

        elif selec == 2:
            input_bin = input("Digite o Binario: ")
            password = input("Digite sua senha: ")
            password_bin = string_to_binary(password)
            decrypted_bin = xor_crypt_alternative2(input_bin, password_bin)
            decrypted = binary_to_string(decrypted_bin)

            print("---------------------------------------------------")
            print("Binario descript:")
            print(decrypted_bin)
            print("---------------------------------------------------")
            print("Descript:")
            print(decrypted)
            print("---------------------------------------------------")

        elif selec == 3:
            string_bin = input("Insira o codigo Binario: ")
            string_hex = bin_to_hex(string_bin)
            print("---------------------------------------------------")
            print(string_hex)
            print("---------------------------------------------------")

        elif selec == 4:
            string_hex = input("Insira o codigo Hexa: ")
            string_bin = hex_to_bin(string_hex)
            print("---------------------------------------------------")
            print(string_bin)
            print("---------------------------------------------------")

        elif selec == 5:
            string_note = input("Insira o binario ou hexa para anotar: ")
            print("---------------------------------------------------")
            for i in range(0, len(string_note), 4):
                print(string_note[i:i+4])
            print("---------------------------------------------------")

        elif selec == 6:
            break

        else:
            print("Opção inválida. Tente novamente.")


if __name__ == "__main__":
    main()

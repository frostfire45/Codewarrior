NVMIF2  MC9S12XF384_V1  0x2E5 "hcs12xe_common.fpp"
WORKSPACE 0x2000 0x2000 3 2
DATABUFFER 0x2500 0x3FFF
MODULEIMPORT MC9S12XE_FLASH_4000
MODULEIMPORT MC9S12XE_FLASH_FLAT_8000_PPAGE_FE
MODULEIMPORT MC9S12XE_FLASH_C000
MODULEIMPORT MC9S12XE_FLASH_FTM1024K MODULEREMAP 0xE08000 0xE7BFFF
MODULEIMPORT MC9S12XE_FLASH_FTM1024K MODULEREMAP 0xF08000 0xFFBFFF
MODULEIMPORT DFLASH_12X_FTM1024K MODULEREMAP 0x000800 0x1F0BFF
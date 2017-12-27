/*
 * name:        nRF24L01+
 * description: Single Chip 2.4GHz Transceiver
 * manuf:       Nordic Semiconductor
 * version:     0.1
 * url:         https://www.nordicsemi.com/eng/content/download/2726/34069/file/nRF24L01P_Product_Specification_1_0.pdf
 * date:        2017-12-19
 * author       https://chisl.io/
 * file:        nRF24L01_.hpp
 */

#include <cinttypes>

/* Derive from class nRF24L01_Base and implement the read and write functions! */

/* nRF24L01+: Single Chip 2.4GHz Transceiver */
class nRF24L01_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	virtual uint64_t read64(uint16_t address, uint16_t n=64) = 0;  // 64 bit read
	virtual void write(uint16_t address, uint64_t value, uint16_t n=64) = 0;  // 64 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG CONFIG                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG CONFIG:
	 * Configuration Register 
	 */
	struct CONFIG
	{
		static const uint16_t __address = 0;
		
		/* Bits Reserved_0: */
		/* Only '0' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits MASK_RX_DR: */
		/*
		 * Mask interrupt caused by RX_DR
		 *           1: Interrupt not reflected on the IRQ pin
		 *           0: Reflect RX_DR as active low interrupt on the
		 *           IRQ pin 
		 */
		struct MASK_RX_DR
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits MASK_TX_DS: */
		/*
		 * Mask interrupt caused by TX_DS
		 *           1: Interrupt not reflected on the IRQ pin
		 *           0: Reflect TX_DS as active low interrupt on the IRQ
		 *           pin 
		 */
		struct MASK_TX_DS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits MASK_MAX_RT: */
		/*
		 * Mask interrupt caused by MAX_RT
		 *           1: Interrupt not reflected on the IRQ pin
		 *           0: Reflect MAX_RT as active low interrupt on the
		 *           IRQ pin 
		 */
		struct MASK_MAX_RT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits EN_CRC: */
		/*
		 * Enable CRC. Forced high if one of the bits in the
		 *           EN_AA is high 
		 */
		struct EN_CRC
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits CRCO: */
		/* CRC encoding scheme  */
		struct CRCO
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t CRC_1_BYTE = 0b0; // 1 byte
			static const uint8_t CRC_2_BYTES = 0b1; // 2 bytes
		};
		/* Bits PWR_UP: */
		/* 1: POWER UP, 0:POWER DOWN  */
		struct PWR_UP
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t POWER_UP = 0b1; // 
			static const uint8_t POWER_DOWN = 0b0; // 
		};
		/* Bits PRIM_RX: */
		/*
		 * RX/TX control
		 *           1: PRX, 0: PTX 
		 */
		struct PRIM_RX
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t PRX = 0b1; // 
			static const uint8_t PTX = 0b0; // 
		};
	};
	
	/* Set register CONFIG */
	void setCONFIG(uint8_t value)
	{
		write(CONFIG::__address, value, 8);
	}
	
	/* Get register CONFIG */
	uint8_t getCONFIG()
	{
		return read8(CONFIG::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG EN_AA                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG EN_AA:
	 * Enable 'Auto Acknowledgment' Function Disable
	 *       this functionality to be compatible with nRF2401,
	 *       see page 75 
	 */
	struct EN_AA
	{
		static const uint16_t __address = 1;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits ENAA_P5: */
		/* Enable auto acknowledgement data pipe 5  */
		struct ENAA_P5
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits ENAA_P4: */
		/* Enable auto acknowledgement data pipe 4  */
		struct ENAA_P4
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits ENAA_P3: */
		/* Enable auto acknowledgement data pipe 3  */
		struct ENAA_P3
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits ENAA_P2: */
		/* Enable auto acknowledgement data pipe 2  */
		struct ENAA_P2
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits ENAA_P1: */
		/* Enable auto acknowledgement data pipe 1  */
		struct ENAA_P1
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits ENAA_P0: */
		/* Enable auto acknowledgement data pipe 0  */
		struct ENAA_P0
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register EN_AA */
	void setEN_AA(uint8_t value)
	{
		write(EN_AA::__address, value, 8);
	}
	
	/* Get register EN_AA */
	uint8_t getEN_AA()
	{
		return read8(EN_AA::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG EN_RXADDR                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG EN_RXADDR:
	 * Enabled RX Addresses 
	 */
	struct EN_RXADDR
	{
		static const uint16_t __address = 2;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits ERX_P5: */
		/* Enable data pipe 5.  */
		struct ERX_P5
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits ERX_P4: */
		/* Enable data pipe 4.  */
		struct ERX_P4
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits ERX_P3: */
		/* Enable data pipe 3.  */
		struct ERX_P3
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits ERX_P2: */
		/* Enable data pipe 2.  */
		struct ERX_P2
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits ERX_P1: */
		/* Enable data pipe 1.  */
		struct ERX_P1
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits ERX_P0: */
		/* Enable data pipe 0.  */
		struct ERX_P0
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register EN_RXADDR */
	void setEN_RXADDR(uint8_t value)
	{
		write(EN_RXADDR::__address, value, 8);
	}
	
	/* Get register EN_RXADDR */
	uint8_t getEN_RXADDR()
	{
		return read8(EN_RXADDR::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG SETUP_AW                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SETUP_AW:
	 * Setup of Address Widths
	 *       (common for all data pipes) 
	 */
	struct SETUP_AW
	{
		static const uint16_t __address = 3;
		
		/* Bits Reserved_0: */
		/* Only '000000' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits AW: */
		/*
		 * RX/TX Address field width
		 *           '00' - Illegal
		 *           '01' - 3 bytes
		 *           '10' - 4 bytes
		 *           11' - 5 bytes
		 *           LSByte is used if address width is below 5 bytes 
		 */
		struct AW
		{
			static const uint8_t dflt = 0b11; // 2'b11
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t ILLEGAL = 0b00; // 
			static const uint8_t WIDTH_3_BYTES = 0b01; // 
			static const uint8_t WIDTH_4_BYTES = 0b10; // 
			static const uint8_t WIDTH_5_BYTES = 0b11; // 
		};
	};
	
	/* Set register SETUP_AW */
	void setSETUP_AW(uint8_t value)
	{
		write(SETUP_AW::__address, value, 8);
	}
	
	/* Get register SETUP_AW */
	uint8_t getSETUP_AW()
	{
		return read8(SETUP_AW::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG SETUP_RETR                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG SETUP_RETR:
	 * Setup of Automatic Retransmission 
	 */
	struct SETUP_RETR
	{
		static const uint16_t __address = 4;
		
		/* Bits ARDa: */
		/*
		 * Auto Retransmit Delay
		 *           4'b0000 Wait 250µs
		 *           4'b0001 Wait 500µs
		 *           4'b0010 Wait 750µs
		 *           ........
		 *           4b1111 Wait 4000µs
		 *           (Delay defined from end of transmission to start of
		 *           next transmission)b 
		 */
		struct ARDa
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits ARC: */
		/*
		 * Auto Retransmit Count
		 *           4'b0000 Re-Transmit disabled
		 *           4b0001 Up to 1 Re-Transmit on fail of AA
		 *           ......
		 *           4b1111 Up to 15 Re-Transmit on fail of AA 
		 */
		struct ARC
		{
			static const uint8_t dflt = 0b0011; // 4'b11
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register SETUP_RETR */
	void setSETUP_RETR(uint8_t value)
	{
		write(SETUP_RETR::__address, value, 8);
	}
	
	/* Get register SETUP_RETR */
	uint8_t getSETUP_RETR()
	{
		return read8(SETUP_RETR::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG RF_CH                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG RF_CH:
	 * RF Channel 
	 */
	struct RF_CH
	{
		static const uint16_t __address = 5;
		
		/* Bits Reserved_0: */
		/* Only '0' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits RF_CH: */
		/* Sets the frequency channel nRF24L01+ operates on  */
		struct RF_CH_
		{
			static const uint8_t dflt = 0b0000010; // 7'b10
			static const uint8_t mask = 0b01111111; // [0,1,2,3,4,5,6]
		};
	};
	
	/* Set register RF_CH */
	void setRF_CH(uint8_t value)
	{
		write(RF_CH::__address, value, 8);
	}
	
	/* Get register RF_CH */
	uint8_t getRF_CH()
	{
		return read8(RF_CH::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RF_SETUP                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RF_SETUP:
	 * RF Setup Register 
	 */
	struct RF_SETUP
	{
		static const uint16_t __address = 6;
		
		/* Bits CONT_WAVE: */
		/* Enables continuous carrier transmit when high.  */
		struct CONT_WAVE
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits Reserved_0: */
		/* Only '0' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits RF_DR_LOW: */
		/*
		 * Set RF Data Rate to 250kbps. See RF_DR_HIGH
		 *           for encoding. 
		 */
		struct RF_DR_LOW
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits PLL_LOCK: */
		/* Force PLL lock signal. Only used in test  */
		struct PLL_LOCK
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits RF_DR_HIGH: */
		/*
		 * Select between the high speed data rates. This bit
		 *           is don't care if RF_DR_LOW is set.
		 *           Encoding:
		 *           [RF_DR_LOW, RF_DR_HIGH]:
		 *           2'b00 - 1Mbps
		 *           2'b01 - 2Mbps
		 *           2'b10 - 250kbps
		 *           2'b11 - Reserved 
		 */
		struct RF_DR_HIGH
		{
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits RF_PWR: */
		/* Set RF output power in TX mode  */
		struct RF_PWR
		{
			static const uint8_t dflt = 0b11; // 2'b11
			static const uint8_t mask = 0b00000110; // [1,2]
			static const uint8_t TX_MINUS18dBm = 0b00; // -18dBm
			static const uint8_t TX_MINUS12dBm = 0b01; // -12dBm
			static const uint8_t TX_MINUS6dBm = 0b10; // -6dBm
			static const uint8_t TX_0dBm = 0b11; // 0dBm
		};
		/* Bits Obsolete: */
		/* Don't care */
		struct Obsolete
		{
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register RF_SETUP */
	void setRF_SETUP(uint8_t value)
	{
		write(RF_SETUP::__address, value, 8);
	}
	
	/* Get register RF_SETUP */
	uint8_t getRF_SETUP()
	{
		return read8(RF_SETUP::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG STATUS                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS:
	 * Status Register (In parallel to the SPI command
	 *       word applied on the MOSI pin, the STATUS register
	 *       is shifted serially out on the MISO pin) 
	 */
	struct STATUS
	{
		static const uint16_t __address = 7;
		
		/* Bits Reserved_0: */
		/* Only '0' allowed  */
		struct Reserved_0
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits RX_DR: */
		/*
		 * Data Ready RX FIFO interrupt. Asserted when
		 *           new data arrives RX FIFOc.
		 *           Write 1 to clear bit. 
		 */
		struct RX_DR
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits TX_DS: */
		/*
		 * Data Sent TX FIFO interrupt. Asserted when
		 *           packet transmitted on TX. If AUTO_ACK is acti-
		 *           vated, this bit is set high only when ACK is
		 *           received.
		 *           Write 1 to clear bit. 
		 */
		struct TX_DS
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
			static const uint8_t CLEAR = 0b0; // 
		};
		/* Bits MAX_RT: */
		/*
		 * Maximum number of TX retransmits interrupt
		 *           Write 1 to clear bit. If MAX_RT is asserted it must
		 *           be cleared to enable further communication. 
		 */
		struct MAX_RT
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t CLEAR = 0b1; // 
		};
		/* Bits RX_P_NO: */
		/*
		 * Data pipe number for the payload available for
		 *           reading from RX_FIFO
		 *           000-101: Data Pipe Number
		 *           110: Not Used
		 *           111: RX FIFO Empty 
		 */
		struct RX_P_NO
		{
			/* Mode:r */
			static const uint8_t dflt = 0b111; // 3'b111
			static const uint8_t mask = 0b00001110; // [1,2,3]
			static const uint8_t NOT_USED = 0b110; // 
			static const uint8_t RX_FIFO_EMPTY = 0b111; // 
		};
		/* Bits TX_FULL: */
		/*
		 * TX FIFO full flag.
		 *           1: TX FIFO full.
		 *           0: Available locations in TX FIFO. 
		 */
		struct TX_FULL
		{
			/* Mode:r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t TX_FIFO_FULL = 0b1; // 
		};
	};
	
	/* Set register STATUS */
	void setSTATUS(uint8_t value)
	{
		write(STATUS::__address, value, 8);
	}
	
	/* Get register STATUS */
	uint8_t getSTATUS()
	{
		return read8(STATUS::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG OBSERVE_TX                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG OBSERVE_TX:
	 * Transmit observe register 
	 */
	struct OBSERVE_TX
	{
		static const uint16_t __address = 8;
		
		/* Bits PLOS_CNT: */
		/*
		 * Count lost packets. The counter is overflow pro-
		 *           tected to 15, and discontinues at max until reset.
		 *           The counter is reset by writing to RF_CH. See
		 *           page 75. 
		 */
		struct PLOS_CNT
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits ARC_CNT: */
		/*
		 * Count retransmitted packets. The counter is reset
		 *           when transmission of a new packet starts. See
		 *           page 75. 
		 */
		struct ARC_CNT
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00001111; // [0,1,2,3]
		};
	};
	
	/* Set register OBSERVE_TX */
	void setOBSERVE_TX(uint8_t value)
	{
		write(OBSERVE_TX::__address, value, 8);
	}
	
	/* Get register OBSERVE_TX */
	uint8_t getOBSERVE_TX()
	{
		return read8(OBSERVE_TX::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                             REG RPD                                              *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/* REG RPD:
	 */
	struct RPD
	{
		static const uint16_t __address = 9;
		
		/* Bits Reserved_0: */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b0000000; // 7'b0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits RPD: */
		/*
		 * Received Power Detector. This register is called
		 *           CD (Carrier Detect) in the nRF24L01. The name is
		 *           different in nRF24L01+ due to the different input
		 *           power level threshold for this bit. See section 6.4
		 *           on page 25. 
		 */
		struct RPD_
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register RPD */
	void setRPD(uint8_t value)
	{
		write(RPD::__address, value, 8);
	}
	
	/* Get register RPD */
	uint8_t getRPD()
	{
		return read8(RPD::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG RX_ADDR_P0                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RX_ADDR_P0:
	 * Receive address data pipe 0. 5 Bytes maximum
	 *       length. (LSByte is written first. Write the number of
	 *       bytes defined by SETUP_AW) 
	 */
	struct RX_ADDR_P0
	{
		static const uint16_t __address = 10;
		
		/* Bits RX_ADDR_P0: */
		struct RX_ADDR_P0_
		{
			/* Mode:rw */
			static const uint64_t dflt = 0b1110011111100111111001111110011111100111; // 40'he7e7e7e7e7
			static const uint64_t mask = 0b1111111111111111111111111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39]
		};
	};
	
	/* Set register RX_ADDR_P0 */
	void setRX_ADDR_P0(uint64_t value)
	{
		write(RX_ADDR_P0::__address, value, 40);
	}
	
	/* Get register RX_ADDR_P0 */
	uint64_t getRX_ADDR_P0()
	{
		return read64(RX_ADDR_P0::__address, 40);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG RX_ADDR_P1                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RX_ADDR_P1:
	 * Receive address data pipe 1. 5 Bytes maximum
	 *       length. (LSByte is written first. Write the number of
	 *       bytes defined by SETUP_AW) 
	 */
	struct RX_ADDR_P1
	{
		static const uint16_t __address = 11;
		
		/* Bits RX_ADDR_P1: */
		struct RX_ADDR_P1_
		{
			/* Mode:rw */
			static const uint64_t dflt = 0b1100001011000010110000101100001011000010; // 40'hc2c2c2c2c2
			static const uint64_t mask = 0b1111111111111111111111111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39]
		};
	};
	
	/* Set register RX_ADDR_P1 */
	void setRX_ADDR_P1(uint64_t value)
	{
		write(RX_ADDR_P1::__address, value, 40);
	}
	
	/* Get register RX_ADDR_P1 */
	uint64_t getRX_ADDR_P1()
	{
		return read64(RX_ADDR_P1::__address, 40);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG RX_ADDR_P2                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RX_ADDR_P2:
	 * Receive address data pipe 2. Only LSB. MSBytes
	 *       are equal to RX_ADDR_P1[39:8] 
	 */
	struct RX_ADDR_P2
	{
		static const uint16_t __address = 12;
		
		/* Bits RX_ADDR_P2: */
		struct RX_ADDR_P2_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b11000011; // 8'hc3
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register RX_ADDR_P2 */
	void setRX_ADDR_P2(uint8_t value)
	{
		write(RX_ADDR_P2::__address, value, 8);
	}
	
	/* Get register RX_ADDR_P2 */
	uint8_t getRX_ADDR_P2()
	{
		return read8(RX_ADDR_P2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG RX_ADDR_P3                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RX_ADDR_P3:
	 * Receive address data pipe 3. Only LSB. MSBytes
	 *       are equal to RX_ADDR_P1[39:8] 
	 */
	struct RX_ADDR_P3
	{
		static const uint16_t __address = 13;
		
		/* Bits RX_ADDR_P3: */
		struct RX_ADDR_P3_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b11000100; // 8'hc4
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register RX_ADDR_P3 */
	void setRX_ADDR_P3(uint8_t value)
	{
		write(RX_ADDR_P3::__address, value, 8);
	}
	
	/* Get register RX_ADDR_P3 */
	uint8_t getRX_ADDR_P3()
	{
		return read8(RX_ADDR_P3::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG RX_ADDR_P4                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RX_ADDR_P4:
	 * Receive address data pipe 4. Only LSB. MSBytes
	 *       are equal to RX_ADDR_P1[39:8] 
	 */
	struct RX_ADDR_P4
	{
		static const uint16_t __address = 14;
		
		/* Bits RX_ADDR_P4: */
		struct RX_ADDR_P4_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b11000101; // 8'hc5
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register RX_ADDR_P4 */
	void setRX_ADDR_P4(uint8_t value)
	{
		write(RX_ADDR_P4::__address, value, 8);
	}
	
	/* Get register RX_ADDR_P4 */
	uint8_t getRX_ADDR_P4()
	{
		return read8(RX_ADDR_P4::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG RX_ADDR_P5                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG RX_ADDR_P5:
	 * Receive address data pipe 5. Only LSB. MSBytes
	 *       are equal to RX_ADDR_P1[39:8] 
	 */
	struct RX_ADDR_P5
	{
		static const uint16_t __address = 15;
		
		/* Bits RX_ADDR_P5: */
		struct RX_ADDR_P5_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b11000110; // 8'hc6
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register RX_ADDR_P5 */
	void setRX_ADDR_P5(uint8_t value)
	{
		write(RX_ADDR_P5::__address, value, 8);
	}
	
	/* Get register RX_ADDR_P5 */
	uint8_t getRX_ADDR_P5()
	{
		return read8(RX_ADDR_P5::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG TX_ADDR                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG TX_ADDR:
	 * Transmit address. Used for a PTX device only.
	 *       (LSByte is written first)
	 *       Set RX_ADDR_P0 equal to this address to handle
	 *       automatic acknowledge if this is a PTX device with
	 *       Enhanced ShockBurstTM enabled. See page 75. 
	 */
	struct TX_ADDR
	{
		static const uint16_t __address = 16;
		
		/* Bits TX_ADDR: */
		struct TX_ADDR_
		{
			/* Mode:rw */
			static const uint64_t dflt = 0b1110011111100111111001111110011111100111; // 40'he7e7e7e7e7
			static const uint64_t mask = 0b1111111111111111111111111111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39]
		};
	};
	
	/* Set register TX_ADDR */
	void setTX_ADDR(uint64_t value)
	{
		write(TX_ADDR::__address, value, 40);
	}
	
	/* Get register TX_ADDR */
	uint64_t getTX_ADDR()
	{
		return read64(TX_ADDR::__address, 40);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RX_PW_P0                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG RX_PW_P0:
	 */
	struct RX_PW_P0
	{
		static const uint16_t __address = 17;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits RX_PW_P0: */
		/*
		 * Number of bytes in RX payload in data pipe 0 (1 to 32 bytes).
		 *           0 Pipe not used
		 *           1 = 1 byte
		 *           ...
		 *           32 = 32 bytes 
		 */
		struct RX_PW_P0_
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
			static const uint8_t PIPE_NOT_USED = 0b0000; // 
		};
	};
	
	/* Set register RX_PW_P0 */
	void setRX_PW_P0(uint8_t value)
	{
		write(RX_PW_P0::__address, value, 8);
	}
	
	/* Get register RX_PW_P0 */
	uint8_t getRX_PW_P0()
	{
		return read8(RX_PW_P0::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RX_PW_P1                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG RX_PW_P1:
	 */
	struct RX_PW_P1
	{
		static const uint16_t __address = 18;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits RX_PW_P1: */
		/*
		 * Number of bytes in RX payload in data pipe 1 (1 to 32 bytes).
		 *           0 Pipe not used
		 *           1 = 1 byte
		 *           ...
		 *           32 = 32 bytes 
		 */
		struct RX_PW_P1_
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
			static const uint8_t PIPE_NOT_USED = 0b0000; // 
		};
	};
	
	/* Set register RX_PW_P1 */
	void setRX_PW_P1(uint8_t value)
	{
		write(RX_PW_P1::__address, value, 8);
	}
	
	/* Get register RX_PW_P1 */
	uint8_t getRX_PW_P1()
	{
		return read8(RX_PW_P1::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RX_PW_P2                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG RX_PW_P2:
	 */
	struct RX_PW_P2
	{
		static const uint16_t __address = 19;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits RX_PW_P2: */
		/*
		 * Number of bytes in RX payload in data pipe 2 (1 to
		 *           32 bytes).
		 *           0 Pipe not used
		 *           1 = 1 byte
		 *           ...
		 *           32 = 32 bytes 
		 */
		struct RX_PW_P2_
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
			static const uint8_t PIPE_NOT_USED = 0b0000; // 
		};
	};
	
	/* Set register RX_PW_P2 */
	void setRX_PW_P2(uint8_t value)
	{
		write(RX_PW_P2::__address, value, 8);
	}
	
	/* Get register RX_PW_P2 */
	uint8_t getRX_PW_P2()
	{
		return read8(RX_PW_P2::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RX_PW_P3                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG RX_PW_P3:
	 */
	struct RX_PW_P3
	{
		static const uint16_t __address = 20;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits RX_PW_P3: */
		/*
		 * Number of bytes in RX payload in data pipe 3 (1 to
		 *           32 bytes).
		 *           0 Pipe not used
		 *           1 = 1 byte
		 *           ...
		 *           32 = 32 bytes 
		 */
		struct RX_PW_P3_
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
			static const uint8_t PIPE_NOT_USED = 0b0000; // 
		};
	};
	
	/* Set register RX_PW_P3 */
	void setRX_PW_P3(uint8_t value)
	{
		write(RX_PW_P3::__address, value, 8);
	}
	
	/* Get register RX_PW_P3 */
	uint8_t getRX_PW_P3()
	{
		return read8(RX_PW_P3::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RX_PW_P4                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG RX_PW_P4:
	 */
	struct RX_PW_P4
	{
		static const uint16_t __address = 21;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits RX_PW_P4: */
		/*
		 * Number of bytes in RX payload in data pipe 4 (1 to
		 *           32 bytes).
		 *           0 Pipe not used
		 *           1 = 1 byte
		 *           ...
		 *           32 = 32 bytes 
		 */
		struct RX_PW_P4_
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
			static const uint8_t PIPE_NOT_USED = 0b0000; // 
		};
	};
	
	/* Set register RX_PW_P4 */
	void setRX_PW_P4(uint8_t value)
	{
		write(RX_PW_P4::__address, value, 8);
	}
	
	/* Get register RX_PW_P4 */
	uint8_t getRX_PW_P4()
	{
		return read8(RX_PW_P4::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG RX_PW_P5                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/* REG RX_PW_P5:
	 */
	struct RX_PW_P5
	{
		static const uint16_t __address = 22;
		
		/* Bits Reserved_0: */
		/* Only '00' allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits RX_PW_P5: */
		/*
		 * Number of bytes in RX payload in data pipe 5 (1 to
		 *           32 bytes).
		 *           0 Pipe not used
		 *           1 = 1 byte
		 *           ...
		 *           32 = 32 bytes 
		 */
		struct RX_PW_P5_
		{
			static const uint8_t dflt = 0b000000; // 6'b0
			static const uint8_t mask = 0b00111111; // [0,1,2,3,4,5]
			static const uint8_t PIPE_NOT_USED = 0b0000; // 
		};
	};
	
	/* Set register RX_PW_P5 */
	void setRX_PW_P5(uint8_t value)
	{
		write(RX_PW_P5::__address, value, 8);
	}
	
	/* Get register RX_PW_P5 */
	uint8_t getRX_PW_P5()
	{
		return read8(RX_PW_P5::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG FIFO_STATUS                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FIFO_STATUS:
	 * FIFO Status Register 
	 */
	struct FIFO_STATUS
	{
		static const uint16_t __address = 23;
		
		/* Bits Reserved_0: */
		/* Only '0' allowed  */
		struct Reserved_0
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
		};
		/* Bits TX_REUSE: */
		/*
		 * Used for a PTX device
		 *           Pulse the rfce high for at least 10Î¼s to Reuse last
		 *           transmitted payload. TX payload reuse is active
		 *           until W_TX_PAYLOAD or FLUSH TX is executed.
		 *           TX_REUSE is set by the SPI command
		 *           REUSE_TX_PL, and is reset by the SPI commands
		 *           W_TX_PAYLOAD or FLUSH TX 
		 */
		struct TX_REUSE
		{
			/* Mode:r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
		};
		/* Bits TX_FULL: */
		/*
		 * TX FIFO full flag. 1: TX FIFO full. 0: Available loca-
		 *           tions in TX FIFO. 
		 */
		struct TX_FULL
		{
			/* Mode:r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits TX_EMPTY: */
		/*
		 * TX FIFO empty flag.
		 *           1: TX FIFO empty.
		 *           0: Data in TX FIFO. 
		 */
		struct TX_EMPTY
		{
			/* Mode:r */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t TX_FIFO_EMPTY = 0b1; // 
		};
		/* Bits Reserved_1: */
		/* Only '00' allowed  */
		struct Reserved_1
		{
			/* Mode:rw */
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00001100; // [2,3]
		};
		/* Bits RX_FULL: */
		/*
		 * RX FIFO full flag.
		 *           1: RX FIFO full.
		 *           0: Available locations in RX FIFO. 
		 */
		struct RX_FULL
		{
			/* Mode:r */
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits RX_EMPTY: */
		/*
		 * RX FIFO empty flag.
		 *           1: RX FIFO empty.
		 *           0: Data in RX FIFO. 
		 */
		struct RX_EMPTY
		{
			/* Mode:r */
			static const uint8_t dflt = 0b1; // 1'b1
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t TX_FIFO_EMPTY = 0b1; // 
		};
	};
	
	/* Set register FIFO_STATUS */
	void setFIFO_STATUS(uint8_t value)
	{
		write(FIFO_STATUS::__address, value, 8);
	}
	
	/* Get register FIFO_STATUS */
	uint8_t getFIFO_STATUS()
	{
		return read8(FIFO_STATUS::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                            REG DYNPD                                             *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG DYNPD:
	 * Enable dynamic payload length 
	 */
	struct DYNPD
	{
		static const uint16_t __address = 28;
		
		/* Bits Reserved_0: */
		/* Only 2'b00 allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b11000000; // [6,7]
		};
		/* Bits DPL_P5: */
		/*
		 * Enable dynamic payload length data pipe 5.
		 *           (Requires EN_DPL and ENAA_P5) 
		 */
		struct DPL_P5
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00100000; // [5]
		};
		/* Bits DPL_P4: */
		/*
		 * Enable dynamic payload length data pipe 4.
		 *           (Requires EN_DPL and ENAA_P4) 
		 */
		struct DPL_P4
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
		};
		/* Bits DPL_P3: */
		/*
		 * Enable dynamic payload length data pipe 3.
		 *           (Requires EN_DPL and ENAA_P3) 
		 */
		struct DPL_P3
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
		};
		/* Bits DPL_P2: */
		/*
		 * Enable dynamic payload length data pipe 2.
		 *           (Requires EN_DPL and ENAA_P2) 
		 */
		struct DPL_P2
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits DPL_P1: */
		/*
		 * Enable dynamic payload length data pipe 1.
		 *           (Requires EN_DPL and ENAA_P1) 
		 */
		struct DPL_P1
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
		/* Bits DPL_P0: */
		/*
		 * Enable dynamic payload length data pipe 0.
		 *           (Requires EN_DPL and ENAA_P0) 
		 */
		struct DPL_P0
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
		};
	};
	
	/* Set register DYNPD */
	void setDYNPD(uint8_t value)
	{
		write(DYNPD::__address, value, 8);
	}
	
	/* Get register DYNPD */
	uint8_t getDYNPD()
	{
		return read8(DYNPD::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG FEATURE                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG FEATURE:
	 * Feature Register 
	 */
	struct FEATURE
	{
		static const uint16_t __address = 29;
		
		/* Bits Reserved_0: */
		/* Only 5'b00000 allowed  */
		struct Reserved_0
		{
			static const uint8_t dflt = 0b00000; // 5'b0
			static const uint8_t mask = 0b11111000; // [3,4,5,6,7]
		};
		/* Bits EN_DPL: */
		/* Enables Dynamic Payload Length  */
		struct EN_DPL
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
		};
		/* Bits EN_ACK_PAYd: */
		/* Enables Payload with ACK  */
		struct EN_ACK_PAYd
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
		};
	};
	
	/* Set register FEATURE */
	void setFEATURE(uint8_t value)
	{
		write(FEATURE::__address, value, 8);
	}
	
	/* Get register FEATURE */
	uint8_t getFEATURE()
	{
		return read8(FEATURE::__address, 8);
	}
	
};

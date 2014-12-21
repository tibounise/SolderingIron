import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.color.ColorSpace;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
import java.awt.image.BufferedImage;
import java.awt.image.ColorConvertOp;
import java.awt.image.DataBuffer;
import java.awt.image.IndexColorModel;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;

public class img2code {
    public static void main(String[] args) throws Exception {
        File imageFile = new File(args[0]);
        BufferedImage in = ImageIO.read(imageFile);
        BufferedImage blackWhite = new BufferedImage(in.getWidth(), in.getHeight(), BufferedImage.TYPE_BYTE_BINARY);
        ColorConvertOp op = new ColorConvertOp(ColorSpace.getInstance(ColorSpace.CS_GRAY), null);
        op.filter(in, blackWhite);

        DataBuffer buf = blackWhite.getRaster().getDataBuffer();
        int byteWidth = (in.getWidth() + 7) /8;
        StringBuffer str = new StringBuffer();
        int i=0,max=buf.getSize();

        while(i < max) {
            for(int j=0;j<byteWidth;++j) {
                str.append("0x"+Integer.toString(buf.getElem(i++),16)+(i != max ?",":""));
            }
        }

        System.out.println(str.toString());
    }
}
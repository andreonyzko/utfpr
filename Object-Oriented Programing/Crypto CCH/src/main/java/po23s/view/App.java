package po23s.view;

import java.text.NumberFormat;
import java.util.Locale;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import org.json.JSONObject;
import po23s.http.ClienteHttp;
import po23s.model.entity.Ticker;

public class App extends javax.swing.JFrame {
    public App() {
        initComponents();
        table = (DefaultTableModel) tblCurrencys.getModel();
    }
    @SuppressWarnings("unchecked")
    
    static NumberFormat nf = NumberFormat.getCurrencyInstance(new Locale("pt", "BR"));
    static ClienteHttp clientHttp = new ClienteHttp();
    
    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new App().setVisible(true);
            }
        });
    }
    
    public Ticker getTicker(Ticker ticker){
        String url = "https://www.mercadobitcoin.net/api/"+ ticker.getName() +"/ticker";
        String json = clientHttp.buscaDados(url);
        JSONObject jsonObj = new JSONObject(json);

        if(!jsonObj.has("ticker")){
            JOptionPane.showMessageDialog(this, "Moeda não encontrada");
            return null;
        }

        jsonObj = jsonObj.getJSONObject("ticker");
        ticker.setBuy(jsonObj.getDouble("buy"));
        ticker.setSell(jsonObj.getDouble("sell"));

        return ticker;
    }
    
    public Ticker findTicker(Ticker ticker){
        int tableSize= tblCurrencys.getRowCount();
        for(int i= 0; i < tableSize; i++){
            if(tblCurrencys.getValueAt(i, 0).toString().equalsIgnoreCase(ticker.getName())) return ticker;
        }
        return null;
    }
    
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        tblCurrencys = new javax.swing.JTable();
        btnUpdate = new javax.swing.JButton();
        btnAddCurrency = new javax.swing.JButton();
        btnDelete = new javax.swing.JButton();
        txtCurrencyName = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Mercado de Crypto");
        setBackground(new java.awt.Color(248, 248, 248));
        setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        setResizable(false);

        tblCurrencys.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Moeda", "Compra", "Venda"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tblCurrencys.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        tblCurrencys.getTableHeader().setResizingAllowed(false);
        tblCurrencys.getTableHeader().setReorderingAllowed(false);
        jScrollPane1.setViewportView(tblCurrencys);

        btnUpdate.setFont(new java.awt.Font("Arial", 1, 12)); // NOI18N
        btnUpdate.setText("Atualizar");
        btnUpdate.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnUpdateActionPerformed(evt);
            }
        });

        btnAddCurrency.setFont(new java.awt.Font("Arial", 1, 12)); // NOI18N
        btnAddCurrency.setText("Adicionar");
        btnAddCurrency.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddCurrencyActionPerformed(evt);
            }
        });

        btnDelete.setFont(new java.awt.Font("Arial", 1, 12)); // NOI18N
        btnDelete.setText("Deletar");
        btnDelete.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnDeleteActionPerformed(evt);
            }
        });

        txtCurrencyName.setFont(new java.awt.Font("Arial", 0, 12)); // NOI18N

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 375, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(txtCurrencyName)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnAddCurrency)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnUpdate)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btnDelete)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 275, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnAddCurrency)
                    .addComponent(btnUpdate)
                    .addComponent(btnDelete)
                    .addComponent(txtCurrencyName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(17, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnDeleteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnDeleteActionPerformed
        int currencyLine = tblCurrencys.getSelectedRow();
        
        if(currencyLine == -1){
            JOptionPane.showMessageDialog(this, "Selecione uma moeda para deletar");
            return;
        }
        
        table.removeRow(currencyLine);
    }//GEN-LAST:event_btnDeleteActionPerformed

    private void btnAddCurrencyActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddCurrencyActionPerformed
        String currencyName = txtCurrencyName.getText().toUpperCase();
        txtCurrencyName.setText("");

        if(currencyName.length() < 2){
            JOptionPane.showMessageDialog(this, "A moeda deve ter no mínimo 2 caracteres");
            return;
        }

        Ticker ticker = new Ticker();
        ticker.setName(currencyName);

        if(findTicker(ticker) != null){
            JOptionPane.showMessageDialog(this, "Essa moeda já está cadastrada");
            return;
        }

        ticker = getTicker(ticker);
        if(ticker == null) return;

        double buy = ticker.getBuy(), sell = ticker.getSell();
        table.addRow(new Object[]{ticker.getName(), nf.format(buy), nf.format(sell)});
    }//GEN-LAST:event_btnAddCurrencyActionPerformed

    private void btnUpdateActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnUpdateActionPerformed
        if(tblCurrencys.getRowCount() == 0){
            JOptionPane.showMessageDialog(this, "Nenhuma moeda cadastrada!");
            return;
        }
        
        int tableSize= tblCurrencys.getRowCount();
        for(int i= 0; i < tableSize; i++){
            Ticker ticker = new Ticker();
            ticker.setName(String.valueOf(tblCurrencys.getValueAt(i, 0)));
            ticker = getTicker(ticker);
            double buy = ticker.getBuy(), sell = ticker.getSell();
            tblCurrencys.setValueAt(nf.format(buy), i, 1);
            tblCurrencys.setValueAt(nf.format(sell), i, 2);
        }
    }//GEN-LAST:event_btnUpdateActionPerformed

    DefaultTableModel table;
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAddCurrency;
    private javax.swing.JButton btnDelete;
    private javax.swing.JButton btnUpdate;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTable tblCurrencys;
    private javax.swing.JTextField txtCurrencyName;
    // End of variables declaration//GEN-END:variables
}
